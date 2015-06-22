extern void *_estack;

static void loop(void) __attribute__((isr));
void reset(void) __attribute__((weak));

void nmi(void) __attribute__((weak, alias("loop")));
void hard_fault(void) __attribute__((weak, alias("loop")));
void mem_manage(void) __attribute__((weak, alias("loop")));
void bus_fault(void) __attribute__((weak, alias("loop")));
void usage_fault(void) __attribute__((weak, alias("loop")));
void svcall(void) __attribute__((weak, alias("loop")));
void debug_monitor(void) __attribute__((weak, alias("loop")));
void pend_sv(void) __attribute__((weak, alias("loop")));
void systick(void) __attribute__((weak, alias("loop")));

static void loop(void)
{
	for (;;);
}

void reset(void)
{
	for (;;);
}

void *vector_table[] __attribute__((section(".vectors"))) = {
	[0x00] = &_estack,
	[0x01] = reset,
	[0x02] = nmi,
	[0x03] = hard_fault,
	[0x04] = mem_manage,
	[0x05] = bus_fault,
	[0x06] = usage_fault,
	[0x0B] = svcall,
	[0x0C] = debug_monitor,
	[0x0E] = pend_sv,
	[0x0F] = systick,
};
