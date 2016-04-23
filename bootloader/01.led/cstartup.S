/*
 * main entry code.
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2.  This program  is licensed "as is" without any warranty of any
 * kind,whether express or implied.
 */

	.code 32
	.section ".start","ax"

	.global _start
////////////////////////////////////////////////////////////////////////////////
// initialize vector
////////////////////////////////////////////////////////////////////////////////
__vector:
    ldr	pc,[pc,#24]	// Absolute jump can reach 4 GByte
    // b ?cstartup	// Relative branch allows remap,limited to 32 MByte
__undef_handler:
    ldr	pc,[pc,#24]	// Branch to undef_handler
__swi_handler:
    ldr	pc,[pc,#24]	// Branch to swi_handler
__prefetch_handler:
    ldr	pc,[pc,#24]	// Branch to prefetch_handler
__data_handler:
    ldr	pc,[pc,#24]	// Branch to data_handler
    .int 0xFFFFFFFF
__irq_handler:
    ldr	pc,[pc,#24]	// Branch to irq_handler
__fiq_handler:
    ldr	pc,[pc,#24]	// Branch to fiq_handler

// Constant table entries (for ldr pc) will be placed at 0x20
    .int _start
    .int __undef_handler
    .int __swi_handler
    .int __prefetch_handler
    .int __data_handler
    .int 0xFFFFFFFF
    .int __irq_handler
    .int __fiq_handler

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

	.pool

/*
 * Initialize stack registers
 */
stack_init:

// --------------------
// Mode,correspords to bits 0-5 in CPSR

#define MODE_MSK 0x1F            // Bit mask for mode bits in CPSR

#define USR_MODE 0x10            // User mode
#define FIQ_MODE 0x11            // Fast Interrupt Request mode
#define IRQ_MODE 0x12            // Interrupt Request mode
#define SVC_MODE 0x13            // Supervisor mode
#define ABT_MODE 0x17            // Abort mode
#define UND_MODE 0x1B            // Undefined Instruction mode
#define SYS_MODE 0x1F            // System mode

// Size in byte of stacks
#define IRQ_STACK 64
#define FIQ_STACK 64
#define SVC_STACK 64
#define ABT_STACK 64
#define UND_STACK 64
#define CSTACK 1024

	ldr r2,=_heap_start

    mov r1,lr
    mrs r0,cpsr                             // Original PSR value
    bic r0,r0,#MODE_MSK                     // Clear the mode bits
    orr r0,r0,#SVC_MODE                     // Set Supervisor mode bits
    msr cpsr_c,r0                           // Change the mode
    add r2,#SVC_STACK
    mov sp,r2                               // End of SVC_STACK

    bic r0,r0,#MODE_MSK                     // Clear the mode bits
    orr r0,r0,#ABT_MODE                     // Set Abort mode bits
    msr cpsr_c,r0                           // Change the mode
    add r2,#ABT_STACK
    mov sp,r2                               // End of ABT_STACK

    bic r0,r0,#MODE_MSK                     // Clear the mode bits
    orr r0,r0,#UND_MODE                     // Set Undefined mode bits
    msr cpsr_c,r0                           // Change the mode
    add r2,#UND_STACK
    mov sp,r2                               // End of UND_STACK

    bic r0,r0,#MODE_MSK                     // Clear the mode bits
    orr r0,r0,#FIQ_MODE                     // Set FIR mode bits
    msr cpsr_c,r0                           // Change the mode
    add r2,#FIQ_STACK
    mov sp,r2                               // End of FIQ_STACK

    bic r0,r0,#MODE_MSK                     // Clear the mode bits
    orr r0,r0,#IRQ_MODE                     // Set IRQ mode bits
    msr cpsr_c,r0                           // Change the mode
    add r2,#IRQ_STACK
    mov sp,r2                               // End of IRQ_STACK

    bic r0,r0,#MODE_MSK                     // Clear the mode bits
    orr r0,r0,#SYS_MODE                     // Set System mode bits
    msr cpsr_c,r0                           // Change the mode
    add r2,#CSTACK
    mov sp,r2                               // End of CSTACK

    mov pc,r1
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
