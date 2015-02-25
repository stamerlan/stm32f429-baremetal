#include "registers.h"

/* Time from reset in ms */
static long long jiffies;

static void Delay(long long ms)
{
	long long start = jiffies;

	while ((long long)start + ms - jiffies > 0);
}

void systick(void)
{
	jiffies++;
}

void main(void)
{
	RCC_AHB1ENR |= 1 << RCC_AHB1ENR_GPIOGEN;

	GPIOG_MODER &= ~((0x3 << (13 * 2)) | (0x3 << (14 * 2)));
	GPIOG_MODER |= (0x1 << (13 * 2)) | (0x1 << (14 * 2));
	GPIOG_OTYPER &= ~((1 << 13) | (1 << 14));
	GPIOG_OSPEEDR &= ~((0x3 << (13 * 2)) | (0x3 << (14 * 2)));
	GPIOG_OSPEEDR |= (GPIO_OSPEEDR_HI << (13 * 2)) | 
		(GPIO_OSPEEDR_HI << (14 * 2));
	GPIOG_PUPDR &= ~((0x0 << (13 * 2)) | (0x0 << (14 * 2)));

	STK_LOAD = 168000 - 1;
	STK_VAL = 0;
	STK_CTRL |= (1 << STK_CTRL_ENABLE) | (1 << STK_CTRL_TICKINT) |
		(1 << STK_CTRL_CLKSOURCE);

	for (;;) {
		GPIOG_ODR |= 1 << 13;
		Delay(125);
		GPIOG_ODR |= 1 << 14;
		Delay(125);
		GPIOG_ODR &= ~((1 << 13) | (1 << 14));
		Delay(500);
	}
}
