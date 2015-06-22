/* Vector table and startup initializations */

#include "registers.h"

#define HSE_STARTUP_TIMEOUT	512

extern void *_etext;
extern void *_sdata;
extern void *_edata;
extern void *_sbss;
extern void *_ebss;
extern void *_estack;

extern void main(void);

static int cstart(void)
{
	int *nvdata = (int *)&_etext;
	int *data = (int *)&_sdata;

	/* Copy data to SRAM */
	while (data < (int *)&_edata) {
		*(data++) = *(nvdata++);
	}
	
	/* Zero .bss */
	data = (int *)&_sbss;
	while (data < (int *)&_ebss) {
		*(data++) = 0;
	}

	return 0;
}

static int clocks(void)
{
	volatile int startup_counter = 0;

	RCC_CR |= 1 << RCC_CR_HSION;
	RCC_CFGR = 0;
	RCC_CR &= ~(RCC_CR_HSEON_MASK & RCC_CR_CSSON_MASK & RCC_CR_PLLON_MASK);
	RCC_PLLCFGR = 0x24003010;	/* Reset value */

	RCC_CR &= ~(RCC_CR_HSEBYP);
	RCC_CIR = 0x0;

	RCC_CR |= 1 << RCC_CR_HSEON;
	do {
		startup_counter++;
	} while ((!(RCC_CR & RCC_CR_HSERDY)) && 
		 (startup_counter != HSE_STARTUP_TIMEOUT));

	if (startup_counter == HSE_STARTUP_TIMEOUT)
		return -1;	
	RCC_APB1ENR |= 1 << RCC_APB1ENR_PWREN;
	PWR_CR |= 0x3 << PWR_CR_VOS;

	RCC_CFGR |= RCC_CFGR_HPRE_DIV1 << RCC_CFGR_HPRE;
	RCC_CFGR |= RCC_CFGR_PPRE2_DIV2 << RCC_CFGR_PPRE2;
	RCC_CFGR |= RCC_CFGR_PPRE1_DIV4 << RCC_CFGR_PPRE1;

	/* Set SYSCLK = 168 MHz */
	/* PLL_VCO = (HSE_VALUE / PLL_M) * PLL_N
	 * SYSCLK = PLL_VCO / PLL_P
	 * USB OTG FS, SDIO, RNG Clock = PLL_VCO / PLLQ
	 */
	/* PLL_M = 8; PLL_N = 336; PLL_P = 2; PLL_Q = 7 */
	RCC_PLLCFGR = (8 << RCC_PLLCFGR_PLLM) |
		      (336 << RCC_PLLCFGR_PLLN) |
		      (RCC_PLLCFGR_PLLP_DIV2 << RCC_PLLCFGR_PLLP) |
		      (7 << RCC_PLLCFGR_PLLQ) |
		      (1 << RCC_PLLCFGR_PLLSRC);

	RCC_CR |= 1 << RCC_CR_PLLON;
	while (!(RCC_CR & RCC_CR_PLLRDY_MASK));

	FLASH_ACR = 1 << FLASH_ACR_ICEN | 1 << FLASH_ACR_DCEN |
		5 << FLASH_ACR_LATENCY;
	while ((FLASH_ACR & FLASH_ACR_LATENCY_MASK) != 5 << FLASH_ACR_LATENCY);

	RCC_CFGR &= ~RCC_CFGR_SW_MASK;
	RCC_CFGR |= RCC_CFGR_SW_PLL << RCC_CFGR_SW;

	while ((RCC_CFGR & RCC_CFGR_SWS_MASK) >> RCC_CFGR_SWS != 
			RCC_CFGR_SWS_PLL);

	RCC_AHB1ENR |= 1 << RCC_AHB1ENR_CCMDATARAMEN;

	return 0;
}

void reset(void)
{
	if (cstart())
		goto loop;
	if (clocks())
		goto loop;

	main();

 loop:
	for (;;);
}

