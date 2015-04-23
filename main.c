#include "registers.h"

#define DUMMY_LOOPS	4

/* Time from reset in ms */
static volatile long long jiffies;

static void Delay(long long ms)
{
	long long start = jiffies;

	while ((long long)start + ms - jiffies > 0);
}

__attribute__((noreturn))
static void fault(void)
{
	for (;;) {
		GPIOG_ODR |= 1 << 14;
		Delay(100);
		GPIOG_ODR &= ~(1 << 14);
		Delay(100);
	}
}

void systick(void)
{
	jiffies++;
}

void main(void)
{
	int i;

	/* Configure PG13 and PG14 output pushpull mode */
	RCC_AHB1ENR |= RCC_AHB1ENR_GPIOGEN_MASK;
	GPIOG_MODER &= ~((0x3 << (13 * 2)) | (0x3 << (14 * 2)));
	GPIOG_MODER |= (0x1 << (13 * 2)) | (0x1 << (14 * 2));
	GPIOG_OTYPER &= ~((1 << 13) | (1 << 14));
	GPIOG_OSPEEDR &= ~((0x3 << (13 * 2)) | (0x3 << (14 * 2)));
	GPIOG_OSPEEDR |= (GPIO_OSPEEDR_HI << (13 * 2)) | 
		(GPIO_OSPEEDR_HI << (14 * 2));
	GPIOG_PUPDR &= ~((0x0 << (13 * 2)) | (0x0 << (14 * 2)));

	/* Configure PA0 input mode */
	RCC_AHB1ENR |= RCC_AHB1ENR_GPIOAEN_MASK;
	GPIOA_MODER &= ~(0x3 << (0 * 2));
	GPIOA_OTYPER &= ~(0x1 << 0);
	GPIOA_OSPEEDR &= ~(0x3 << (0 * 2));
	GPIOA_OSPEEDR |= (GPIO_OSPEEDR_HI << (0 * 2));
	GPIOA_PUPDR &= ~(0x0 << (0 * 2));

	/* Configure system timer for delay function */
	STK_LOAD = 168000 - 1;
	STK_VAL = 0;
	STK_CTRL |= (1 << STK_CTRL_ENABLE) | (1 << STK_CTRL_TICKINT) |
		(1 << STK_CTRL_CLKSOURCE);

	/* Configure random number generator */
	RCC_AHB2ENR |= RCC_AHB2ENR_RNGEN_MASK;
	RNG_CR |= RNG_CR_RNGEN_MASK;

	for (;;) {
		/* TODO: may be use interrupt */
		while (!(GPIOA_IDR & 0x1));

		GPIOG_ODR &= ~((1 << 13) | (1 << 14));
		Delay(125);

		/* Couple dummy loops */
		for (i = 0; i < DUMMY_LOOPS; i++) {
			GPIOG_ODR |= 1 << 13;
			Delay(250);
			GPIOG_ODR &= ~(1 << 13);
			GPIOG_ODR |= 1 << 14;
			Delay(250);
			GPIOG_ODR &= ~(1 << 14);
		}

		/* Wait for random number is generated */		
		while (!(RNG_SR & RNG_SR_DRDY_MASK)) {
			if (RNG_SR & RNG_SR_SEIS_MASK) {
				RNG_SR &= ~RNG_SR_SEIS_MASK;
				RNG_CR &= ~RNG_CR_RNGEN_MASK;
				RNG_CR |= RNG_CR_RNGEN_MASK;
			}

			if (RNG_SR & RNG_SR_CEIS_MASK)
				fault();

			GPIOG_ODR |= 1 << 13;
			Delay(250);
			GPIOG_ODR &= ~(1 << 13);
			GPIOG_ODR |= 1 << 14;
			Delay(250);
			GPIOG_ODR &= ~(1 << 14);
		}

		/* TODO: Code duplicated */
		if (RNG_SR & RNG_SR_SEIS_MASK) {
			RNG_SR &= ~RNG_SR_SEIS_MASK;
			RNG_CR &= ~RNG_CR_RNGEN_MASK;
			RNG_CR |= RNG_CR_RNGEN_MASK;
		}

		if (RNG_SR & RNG_SR_CEIS_MASK)
			fault();

		GPIOG_ODR |= (RNG_DR & 1) ? (1 << 13) : (1 << 14);
	}
}

