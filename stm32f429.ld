ENTRY(reset)

/*_estack = 0x20030000;*/	/* end of 192K RAM */
_estack = 0x20010000;

_Min_Heap_Size = 0;
_Min_Stack_Size = 0x400;

MEMORY
{
	FLASH(rx)	: ORIGIN = 0x08000000, LENGTH = 2048K
	RAM(xrw)	: ORIGIN = 0x20000000, LENGTH = 192K
	CCMRAM(rw)	: ORIGIN = 0x10000000, LENGTH = 64K
}

SECTIONS
{
	.vectors :
	{
		KEEP(*(.vectors))
		. = ALIGN(4);
	} > FLASH

	.text :
	{
		. = ALIGN(4);
		_stext = .;
		*(.text*)
		. = ALIGN(4);
		_etext = .;
	} > FLASH

	.rodata :
	{
		. = ALIGN(4);
		*(.rodata)
		*(.rodata*)
		. = ALIGN(4);
	} > FLASH

	_sidata = LOADADDR(.data);

	.data :
	{
		. = ALIGN(4);
		_sdata = .;
		*(.data)
		*(.data*)
		. = ALIGN(4);
		_edata = .;
	} > RAM AT > FLASH

	.ccmram :
	{
		. = ALIGN(4);
		_sccmram = .;
		*(.ccmram)
		*(.ccmram*)
		. = ALIGN(4);
		_eccmram = .;
	} > CCMRAM AT > FLASH

	.bss :
	{
		_sbss = .;
		*(.bss)
		*(.bss*)
		. = ALIGN(4);
		_ebss = .;
	}
}

PROVIDE(end = .);
_end = .;
