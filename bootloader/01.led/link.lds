OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

SECTIONS {

	. = 0x00000000;
	.start : { KEEP(*(.start)) }

	. = ALIGN(4);
	.text : { KEEP(*(.text)) }

	. = ALIGN(4);
	_hwinit_start = .;
	.hwinitcall : { KEEP(*(.hwinitcall)) }
	_hwinit_end = .;

	. = ALIGN(4);
	.rodata : { KEEP(*(.rodata)) }

	. = ALIGN(4);
	.data : { KEEP(*(.data)) }

	. = ALIGN(4);
	_end = .;

	. = ALIGN(4);
	_bss_start = .;
	.bss : { KEEP(*(.bss*)) }
	. = ALIGN(4);
	_bss_end = .;

	_heap_start = .;
}
