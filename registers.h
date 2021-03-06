/* Registers addresses and constants */

#ifndef REGISTERS_H
#define REGISTERS_H

typedef unsigned long uint32_t;
typedef unsigned int uint16_t;

/* System timer registers */
/* SysTick control and status register */
#define STK_CTRL	(*(volatile uint32_t *)(0xE000E010))

#define STK_CTRL_ENABLE	0
#define STL_CTRL_ENABLE_MASK (1 << STK_CTRL_ENABLE)

#define STK_CTRL_TICKINT	1
#define STK_CTRL_TICKINT_MASK	(1 << STK_CTRL_TICKINT)

#define STK_CTRL_CLKSOURCE	2
#define STK_CTRL_CLKSOURCE_MASK	(1 << STK_CTRL_CLKSOURCE)

#define STK_CTRL_COUNTFLAG	16
#define STK_CTRL_COUNTFLAG_MASK	(1 << STK_CTRL_COUNTFLAG)

#define STK_LOAD	(*(volatile uint32_t *)(0xE000E014))
#define STK_VAL		(*(volatile uint32_t *)(0xE000E018))
#define STL_CALIB	(*(volatile uint32_t *)(0xE000E01C))

/* Peripheral map */
#define APB1PERIPH_BASE	0x40000000
#define AHB1PERIPH_BASE	0x40020000
#define AHB2PERIPH_BASE	0x50000000

#define TIM6_BASE	(APB1PERIPH_BASE + 0x1000)
#define PWR_BASE	(APB1PERIPH_BASE + 0x7000)

#define GPIOA_BASE	(AHB1PERIPH_BASE + 0x0000)
#define GPIOG_BASE	(AHB1PERIPH_BASE + 0x1800)
#define RCC_BASE	(AHB1PERIPH_BASE + 0x3800)
#define FLASH_BASE	(AHB1PERIPH_BASE + 0x3C00)

#define RNG_BASE	(AHB2PERIPH_BASE + 0x060800)

/* TIM6: Basic timer */
/* TIM6 control register 1 */
#define TIM6_CR1	(*(volatile uint16_t *)(TIM6_BASE + 0x00))

#define TIM6_CR1_CEN	0
#define TIM6_CR1_CEN_MASK	(1 << TIM6_CR1_CEN)

#define TIM6_CR1_UDIS	1
#define TIM6_CR1_UDIS_MASK	(1 << TIM6_CR1_UDIS)

#define TIM6_CR1_URS	2
#define TIM6_CR1_URS_MASK	(1 << TIM6_CR1_URS)

#define TIM6_CR1_OPM	3
#define TIM6_CR1_OPM_MASK	(1 << TIM6_CR1_OPM)

#define TIM6_CR1_ARPE	7
#define TIM6_CR1_ARPE_MASK	(1 << TIM6_CR1_ARPE)

/* TIM6 DMA/Interrupt enable register */
#define TIM6_DIER	(*(volatile uint16_t *)(TIM6_BASE + 0x0C))

#define TIM6_DIER_UIE	0
#define TIM6_DIER_UIE_MASK	(1 << TIM6_DIER_UIE)

#define TIM6_DIER_UDE	8
#define TIM6_DIER_UDE_MASK	(1 << TIM6_DIER_UDE)

/* TIM6 prescaler */
#define TIM6_PSC	(*(volatile uint16_t *)(TIM6_BASE + 0x28))

/* TIM6 auto-reload register */
#define TIM6_ARR	(*(volatile uint16_t *)(TIM6_BASE + 0x2C))

/* PWR: Power controller */
/* PWR power control register */
#define PWR_CR		(*(volatile uint32_t *)(PWR_BASE + 0x00))

#define PWR_CR_VOS	14
#define PWR_CR_VOS_MASK	(0x3 << PWR_CR_VOS)

/* GPIO: General-purpose I/Os */
#define GPIO_OTYPER_PUSH_PULL	0
#define GPIO_OTYPER_OPEN_DRAIN	1

#define GPIO_OSPEEDR_LO		0
#define GPIO_OSPEEDR_MED	1
#define GPIO_OSPEEDR_FAST	2
#define GPIO_OSPEEDR_HI		3

#define GPIO_PUPDR_NO		0
#define GPIO_PUPDR_UP		1
#define GPIO_PUPDR_DOWN		2
/* GPIOA port mode register */
#define GPIOA_MODER	(*(volatile uint32_t *)(GPIOA_BASE + 0x00))
/* GPIOA port putput type register */
#define GPIOA_OTYPER	(*(volatile uint32_t *)(GPIOA_BASE + 0x04))
/* GPIOA port output speed register */
#define GPIOA_OSPEEDR	(*(volatile uint32_t *)(GPIOA_BASE + 0x08))
/* GPIOA port input data register */
#define GPIOA_IDR	(*(volatile uint32_t *)(GPIOA_BASE + 0x10))
/* GPIOA port pull-up/pull-down register */
#define GPIOA_PUPDR	(*(volatile uint32_t *)(GPIOA_BASE + 0x0C))
/* GPIOA port output data register */
#define GPIOA_ODR	(*(volatile uint32_t *)(GPIOA_BASE + 0x14))
/* GPIOG port mode register */
#define GPIOG_MODER	(*(volatile uint32_t *)(GPIOG_BASE + 0x00))
/* GPIOG port putput type register */
#define GPIOG_OTYPER	(*(volatile uint32_t *)(GPIOG_BASE + 0x04))
/* GPIOG port output speed register */
#define GPIOG_OSPEEDR	(*(volatile uint32_t *)(GPIOG_BASE + 0x08))
/* GPIOG port input data register */
#define GPIOG_IDR	(*(volatile uint32_t *)(GPIOG_BASE + 0x10))
/* GPIOG port pull-up/pull-down register */
#define GPIOG_PUPDR	(*(volatile uint32_t *)(GPIOG_BASE + 0x0C))
/* GPIOG port output data register */
#define GPIOG_ODR	(*(volatile uint32_t *)(GPIOG_BASE + 0x14))

/* RCC: Reset and clock control */
/* RCC clock control register */
#define RCC_CR		(*(volatile uint32_t *)(RCC_BASE + 0x00))

#define RCC_CR_HSION		0
#define RCC_CR_HSION_MASK	(0x01 << RCC_CR_HSION)

#define RCC_CR_HSIRDY		1
#define RCC_CR_HSIRDY_MASK	(0x01 << RCC_CR_HSIRDY)

#define RCC_CR_HSITRIM		3
#define RCC_CR_HSITRIM_MASK	(0x1F << RCC_CR_HSITRIM)

#define RCC_CR_HSICAL		8
#define RCC_CR_HSICAL_MASK	(0xFF << RCC_CR_HSICAL_MASK)

#define RCC_CR_HSEON		16
#define RCC_CR_HSEON_MASK	(0x01 << RCC_CR_HSEON)

#define RCC_CR_HSERDY		17
#define RCC_CR_HSERDY_MASK	(0x01 << RCC_CR_HSERDY)

#define RCC_CR_HSEBYP		18
#define RCC_CR_HSEBYP_MASK	(0x01 << RCC_CR_HSEBYP)

#define RCC_CR_CSSON		19
#define RCC_CR_CSSON_MASK	(0x01 << RCC_CR_CSSON)

#define RCC_CR_PLLON		24
#define RCC_CR_PLLON_MASK	(0x01 << RCC_CR_PLLON)

#define RCC_CR_PLLRDY		25
#define RCC_CR_PLLRDY_MASK	(0x01 << RCC_CR_PLLRDY)

#define RCC_CR_PLLI2SON		26
#define RCC_CR_PLLI2SON_MASK	(0x01 << RCC_CR_PLLI2SON)

#define RCC_CR_PLLI2SRDY	27
#define RCC_CR_PLLI2SRDY_MASK	(0x01 << RCC_CR_PLLI2SRDY)

#define RCC_CR_PLLISAION	28
#define RCC_CR_PLLISAION_MASK	(0x01 << RCC_CR_PLLISAION)

#define RCC_CR_PLLISAIRDY	29
#define RCC_CR_PLLISAIRDY_MASK	(0x01 << RCC_CR_PLLISAIRDY)

/* RCC PLL configuration register */
#define RCC_PLLCFGR		(*(volatile uint32_t *)(RCC_BASE + 0x04))

#define	RCC_PLLCFGR_PLLM	0
#define RCC_PLLCFGR_PLLM_MASK	(0x3F << RCC_PLLCFGR_PLLM)

#define RCC_PLLCFGR_PLLN	6
#define RCC_PLLCFGR_PLLN_MASK	(0x1FF << RCC_PLLCFGR_PLLN)

#define RCC_PLLCFGR_PLLP	16
#define RCC_PLLCFGR_PLLP_MASK	(0x3 << RCC_PLLCFGR_PLLP)
#define RCC_PLLCFGR_PLLP_DIV2	0
#define RCC_PLLCFGR_PLLP_DIV4	1
#define RCC_PLLCFGR_PLLP_DIV6	2
#define RCC_PLLCFGR_PLLP_DIV8	3

#define RCC_PLLCFGR_PLLSRC	22
#define RCC_PLLCFGR_PLLSRC_MASK	(0x1 << RCC_PLLCFGR_PLLSRC)

#define RCC_PLLCFGR_PLLQ	24
#define RCC_PLLCFGR_PLLQ_MASK	(0xF << RCC_PLLCFGR_PLLQ)

/* RCC clock configuration register */
#define RCC_CFGR		(*(volatile uint32_t *)(RCC_BASE + 0x08))

#define RCC_CFGR_SW		0
#define RCC_CFGR_SW_MASK	(0x03 << RCC_CFGR_SW)
#define RCC_CFGR_SW_HSI		0x0
#define RCC_CFGR_SW_HSE		0x1
#define RCC_CFGR_SW_PLL		0x2

#define RCC_CFGR_SWS		2
#define RCC_CFGR_SWS_MASK	(0x03 << RCC_CFGR_SWS)
#define RCC_CFGR_SWS_HSI	0x0
#define RCC_CFGR_SWS_HSE	0x1
#define RCC_CFGR_SWS_PLL	0x2

#define RCC_CFGR_HPRE		4
#define RCC_CFGR_HPRE_MASK	(0x0F << RCC_CFGR_HPRE)
#define RCC_CFGR_HPRE_DIV1	0x0
#define RCC_CFGR_HPRE_DIV2	0x8
#define RCC_CFGR_HPRE_DIV4	0x9
#define RCC_CFGR_HPRE_DIV8	0xA
#define RCC_CFGR_HPRE_DIV16	0xB
#define RCC_CFGR_HPRE_DIV64	0xC
#define RCC_CFGR_HPRE_DIV128	0xD
#define RCC_CFGR_HPRE_DIV256	0xE
#define RCC_CFGR_HPRE_DIV512	0xF

#define RCC_CFGR_PPRE1		10
#define RCC_CFGR_PPRE1_MASK	(0x7 << RCC_CFGR_PPRE1)
#define RCC_CFGR_PPRE1_DIV1	0x0
#define RCC_CFGR_PPRE1_DIV2	0x4
#define RCC_CFGR_PPRE1_DIV4	0x5
#define RCC_CFGR_PPRE1_DIV8	0x6
#define RCC_CFGR_PPRE1_DIV16	0x7

#define RCC_CFGR_PPRE2		13
#define RCC_CFGR_PPRE2_MASK	(0x7 << RCC_CFGR_PPRE2)
#define RCC_CFGR_PPRE2_DIV1	0x0
#define RCC_CFGR_PPRE2_DIV2	0x4
#define RCC_CFGR_PPRE2_DIV4	0x5
#define RCC_CFGR_PPRE2_DIV8	0x6
#define RCC_CFGR_PPRE2_DIV16	0x7

#define RCC_CFGR_RTCPRE		16
#define RCC_CFGR_RTCPRE_MASK	(0x1F << RCC_CFGR_RTCPRE)

#define RCC_CFGR_MCO1		21
#define RCC_CFGR_MCO1_MASK	(0x3 << RCC_CFGR_MCO1)
#define RCC_CFGR_MCO1_HSI	0
#define RCC_CFGR_MCO1_LSE	1
#define RCC_CFGR_MCO1_HSE	2
#define RCC_CFGR_MCO1_PLL	3

#define RCC_CFGR_I2SSRC		23
#define RCC_CFGR_I2SSRC_MASK	(0x1 << RCC_CFGR_I2SSRC)

/* RCC clock interrupt register */
#define RCC_CIR			(*(volatile uint32_t *)(RCC_BASE + 0x0C))

/* RCC AHB1 peripheral clock register */
#define RCC_AHB1ENR		(*(volatile uint32_t *)(RCC_BASE + 0x30))

#define RCC_AHB1ENR_GPIOAEN	0
#define RCC_AHB1ENR_GPIOAEN_MASK	(1 << RCC_AHB1ENR_GPIOAEN)

#define RCC_AHB1ENR_GPIOBEN	1
#define RCC_AHB1ENR_GPIOBEN_MASK	(1 << RCC_AHB1ENR_GPIOBEN)

#define RCC_AHB1ENR_GPIOCEN	2
#define RCC_AHB1ENR_GPIOCEN_MASK	(1 << RCC_AHB1ENR_GPIOCEN)

#define RCC_AHB1ENR_GPIODEN	3
#define RCC_AHB1ENR_GPIODEN_MASK	(1 << RCC_AHB1ENR_GPIODEN)

#define RCC_AHB1ENR_GPIOEEN	4
#define RCC_AHB1ENR_GPIOEEN_MASK	(1 << RCC_AHB1ENR_GPIOEEN)

#define RCC_AHB1ENR_GPIOFEN	5
#define RCC_AHB1ENR_GPIOFEN_MASK	(1 << RCC_AHB1ENR_GPIOFEN)

#define RCC_AHB1ENR_GPIOGEN	6
#define RCC_AHB1ENR_GPIOGEN_MASK	(1 << RCC_AHB1ENR_GPIOGEN)

#define RCC_AHB1ENR_GPIOHEN	7
#define RCC_AHB1ENR_GPIOHEN_MASK	(1 << RCC_AHB1ENR_GPIOHEN)

#define RCC_AHB1ENR_GPIOIEN	8
#define RCC_AHB1ENR_GPIOIEN_MASK	(1 << RCC_AHB1ENR_GPIOIEN)

#define RCC_AHB1ENR_GPIOJEN	9
#define RCC_AHB1ENR_GPIOJEN_MASK	(1 << RCC_AHB1ENR_GPIOJEN)

#define RCC_AHB1ENR_GPIOKEN	10
#define RCC_AHB1ENR_GPIOKEN_MASK	(1 << RCC_AHB1ENR_GPIOKEN)

#define RCC_AHB1ENR_CCMDATARAMEN	20
#define RCC_AHB1ENR_CCMDATARAMEN_MASK	(1 << RCC_AHB1ENR_CCMDATARAMEN)

/* RCC AHB2 peripheral clock enable register */
#define RCC_AHB2ENR		(*(volatile uint32_t *)(RCC_BASE + 0x34))

#define RCC_AHB2ENR_DCMIEN	0
#define RCC_AHB2ENR_DCMIEN_MASK	(1 << RCC_AHB2ENR_DCMIEN)

#define RCC_AHB2ENR_CRYPEN	4
#define RCC_AHB2ENR_CRYPEN_MASK	(1 << RCC_AHB2ENR_CRYPEN)

#define RCC_AHB2ENR_HASHEN	5
#define RCC_AHB2ENR_HASHEN_MASK	(1 << RCC_AHB2ENR_HASHEN)

#define RCC_AHB2ENR_RNGEN	6
#define RCC_AHB2ENR_RNGEN_MASK	(1 << RCC_AHB2ENR_RNGEN)

#define RCC_AHB2ENR_OTGFSEN	7
#define RCC_AHB2ENR_OTGFSEN_MASK	(1 << RCC_AHB2ENR_OTGFSEN)

/* RCC ABP1 peripheral clock enable register */
#define RCC_APB1ENR		(*(volatile uint32_t *)(RCC_BASE + 0x40))

#define RCC_APB1ENR_TIM2EN	0
#define RCC_APB1ENR_TIM2EN_MASK	(1 << RCC_APB1ENR_TIM2EN)

#define RCC_APB1ENR_TIM3EN	1
#define RCC_APB1ENR_TIM3EN_MASK	(1 << RCC_APB1ENR_TIM3EN)

#define RCC_APB1ENR_TIM4EN	2
#define RCC_APB1ENR_TIM4EN_MASK	(1 << RCC_APB1ENR_TIM4EN)

#define RCC_APB1ENR_TIM5EN	3
#define RCC_APB1ENR_TIM5EN_MASK	(1 << RCC_APB1ENR_TIM5EN)

#define RCC_APB1ENR_TIM6EN	4
#define RCC_APB1ENR_TIM6EN_MASK	(1 << RCC_APB1ENR_TIM6EN)

#define RCC_APB1ENR_TIM7EN	5
#define RCC_APB1ENR_TIM7EN_MASK	(1 << RCC_APB1ENR_TIM7EN)

#define RCC_APB1ENR_TIM12EN	6
#define RCC_APB1ENR_TIM12EN_MASK	(1 << RCC_APB1ENR_TIM12EN)

#define RCC_APB1ENR_TIM13EN	7
#define RCC_APB1ENR_TIM13EN_MASK	(1 << RCC_APB1ENR_TIM13EN)

#define RCC_APB1ENR_TIM14EN	8
#define RCC_APB1ENR_TIM14EN_MASK	(1 << RCC_APB1ENR_TIM14EN)

#define RCC_APB1ENR_WWDGEN	11
#define RCC_APB1ENR_WWDGEN_MASK	(1 << RCC_APB1ENR_WWDGEN)

#define RCC_APB1ENR_SPI2EN	14
#define RCC_APB1ENR_SPI2EN_MASK	(1 << RCC_APB1ENR_SPI2EN)

#define RCC_APB1ENR_SPI3EN	15
#define RCC_APB1ENR_SPI3EN_MASK	(1 << RCC_APB1ENR_SPI3EN)

#define RCC_APB1ENR_USART2EN	17
#define RCC_APB1ENR_USART2EN_MASK	(1 << RCC_APB1ENR_USART2EN)

#define RCC_APB1ENR_USART3EN	18
#define RCC_APB1ENR_USART3EN_MASK	(1 << RCC_APB1ENR_USART3EN)

#define RCC_APB1ENR_USART4EN	19
#define RCC_APB1ENR_USART4EN_MASK	(1 << RCC_APB1ENR_USART4EN)

#define RCC_APB1ENR_USART5EN	20
#define RCC_APB1ENR_USART5EN_MASK	(1 << RCC_APB1ENR_USART5EN)

#define RCC_APB1ENR_I2C1EN	21
#define RCC_APB1ENR_I2C1EN_MASK	(1 << RCC_APB1ENR_I2C1EN)

#define RCC_APB1ENR_I2C2EN	22
#define RCC_APB1ENR_I2C2EN_MASK	(1 << RCC_APB1ENR_I2C2EN)

#define RCC_APB1ENR_I2C3EN	23
#define RCC_APB1ENR_I2C3EN_MASK	(1 << RCC_APB1ENR_I2C3EN)

#define RCC_APB1ENR_CAN1EN	25
#define RCC_APB1ENR_CAN1EN_MASK	(1 << RCC_APB1ENR_CAN1EN)

#define RCC_APB1ENR_CAN2EN	26
#define RCC_APB1ENR_CAN2EN_MASK	(1 << RCC_APB1ENR_CAN2EN)

#define RCC_APB1ENR_PWREN	28
#define RCC_APB1ENR_PWREN_MASK	(1 << RCC_APB1ENR_PWREN)

#define RCC_APB1ENR_DACEN	29
#define RCC_APB1ENR_DACEN_MASK	(1 << RCC_APB1ENR_DACEN)

#define RCC_APB1ENR_UART7EN	30
#define RCC_APB1ENR_UART7EN_MASK	(1 << RCC_APB1ENR_UART7EN)

#define RCC_APB1ENR_UART8EN	31
#define RCC_APB1ENR_UART8EN_MASK	(1 << RCC_APB1ENR_UART8EN)

/* Flash interface registers */
/* Flash access control register */
#define FLASH_ACR		(*(volatile uint32_t *)(FLASH_BASE + 0x00))

#define FLASH_ACR_LATENCY	0
#define FLASH_ACR_LATENCY_MASK	(0xF << FLASH_ACR_LATENCY)

#define FLASH_ACR_PRFTEN	8
#define FLASH_ACR_PRFTEN_MASK	(1 << FLASH_ACR_PRFTEN)

#define FLASH_ACR_ICEN		9
#define FLASH_ACR_ICEN_MASK	(1 << FLASH_ACR_ICEN)

#define FLASH_ACR_DCEN		10
#define FLASH_ACR_DCEN_MASK	(1 << FLASH_ACR_DCEN)

#define FLASH_ACR_ICRST		11
#define FLASH_ACR_ICRST_MASK	(1 << FLASH_ACR_ICRST)

#define FLASH_ACR_DCRST		12
#define FLASH_ACR_DCRST_MASK	(1 << FLASH_ACR_DCRST)

/* RNG: Random number generator registers */
/* RNG control register */
#define RNG_CR			(*(volatile uint32_t *)(RNG_BASE + 0x00))

#define RNG_CR_RNGEN		2
#define RNG_CR_RNGEN_MASK	(1 << RNG_CR_RNGEN)

#define RNG_CR_IE		3
#define RNG_CR_IE_MASK		(1 << RNG_CR_IE)

/* RNG status register */
#define RNG_SR			(*(volatile uint32_t *)(RNG_BASE + 0x04))

#define RNG_SR_DRDY		0
#define RNG_SR_DRDY_MASK	(1 << RNG_SR_DRDY)

#define RNG_SR_CECS		1
#define RNG_SR_CECS_MASK	(1 << RNG_SR_CECS)

#define RNG_SR_SECS		2
#define RNG_SR_SECS_MASK	(1 << RNG_SR_SECS)

#define RNG_SR_CEIS		5
#define RNG_SR_CEIS_MASK	(1 << RNG_SR_CEIS)

#define RNG_SR_SEIS		6
#define RNG_SR_SEIS_MASK	(1 << RNG_SR_SEIS)

/* RNG data register */
#define RNG_DR			(*(volatile uint32_t *)(RNG_BASE + 0x08))

#endif /* REGISTERS_H */

