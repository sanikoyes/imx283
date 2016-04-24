/*
 * main entry code.
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2.  This program  is licensed "as is" without any warranty of any
 * kind,whether express or implied.
 */

#include <arch/asm_defines.h>

	.code 32
	.section ".start","ax"

	.global _start

////////////////////////////////////////////////////////////////////////////////
// initialize vector
////////////////////////////////////////////////////////////////////////////////
    .func startup_vectors
startup_vectors:
        ldr     pc, reset_addr
        ldr     pc, undefined_addr
        ldr     pc, swi_addr
        ldr     pc, prefetch_addr
        ldr     pc, abort_addr
        nop                             /* reserved vector */
        ldr     pc, irq_addr
        ldr     pc, fiq_addr

reset_addr:      .word     _start
undefined_addr:  .word     undefined_handler
swi_addr:        .word     swi_handler
prefetch_addr:   .word     prefetch_handler
abort_addr:      .word     abort_handler
irq_addr:        .word     irq_handler
fiq_addr:        .word     fiq_handler

/*!
 * Exception Handlers
 */
undefined_handler:
        b       undefined_handler
swi_handler:
        b       swi_handler
prefetch_handler:
        b       prefetch_handler
abort_handler:
        b       abort_handler
irq_handler:
        b       irq_handler
fiq_handler:
        b       fiq_handler

    .endfunc    //startup()

////////////////////////////////////////////////////////////////////////////////
// entry
////////////////////////////////////////////////////////////////////////////////
    .func _start
_start:
	// Initialize stack registers
	bl stack_init
	// Clear bbs section
	bl clear_bss
	// Initialize HW modules relevant for linux_prep
	bl hw_init
	// Goto main
	mov r0,#0
	bl main
	// halt
1:
	b 1b
    .endfunc

/*
 * Initialize stack registers
 */
stack_init:
    mov r1, lr
    ldr r0, =_heap_start
    msr cpsr_c, #MODE_FIQ | I_BIT | F_BIT /* no interrupts*/
    add sp, r0, #OFFSET_FIQ_STACK
    msr cpsr_c, #MODE_IRQ | I_BIT | F_BIT /* no interrupts */
    add sp, r0, #OFFSET_IRQ_STACK
    msr cpsr_c, #MODE_ABT | I_BIT | F_BIT /* no interrupts */
    add sp, r0, #OFFSET_ABT_STACK
    msr cpsr_c, #MODE_UND | I_BIT | F_BIT
    add sp, r0, #OFFSET_UND_STACK
    msr cpsr_c, #MODE_SVC | I_BIT | F_BIT /* no interrupts */
    add sp, r0, #OFFSET_SVC_STACK
    msr cpsr_c, #MODE_SYS | I_BIT | F_BIT /* no interrupts */
    add sp, r0, #OFFSET_SYS_STACK
    mov pc, r1

    .pool

/*
 * This function initializes all HW modules anebled in
 * current configuration. It goes throgh .hwinitcall section
 * containing addresses of HW initialization routines.
 */
hw_init:
	stmdb sp!,{r4-r6,lr}
	ldr	r4,=_hwinit_start
	ldr	r5,=_hwinit_end
	cmp	r4,r5
	beq hw_init_done
1:	ldr	r6,[r4],#4
	mov	lr,pc
	mov	pc,r6
	cmp	r4,r5
	blo	1b
hw_init_done:
	ldmia sp!,{r4-r6,lr}
	mov	pc,lr

	.pool
/*
 * This function clears out the .bss section.
 */
clear_bss:
	ldr	r0,=_bss_start
	ldr	r1,=_bss_end
	mov	r2,#0
1:	str	r2,[r0],#4
	cmp	r0,r1
	blo	1b
	mov	pc,lr

	.pool
/*
 * ARM EABI toolchain needs divide by zero handler to be implemented
 * externally.
 */
	.globl __div0
__div0:
	mov	pc,lr

	.globl __aeabi_unwind_cpp_pr0
__aeabi_unwind_cpp_pr0:
	mov	pc,lr

	.globl raise
raise:
	mov	pc,lr
