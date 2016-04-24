/*
 * Low-level debug uart driver
 *
 * sanikoyes <sanikoyes@163.com>
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2.  This program  is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */
#include "duart.h"
#include <arch/init.h>

#include <registers/regspinctrl.h>
#include <registers/regsclkctrl.h>
#include <registers/regsuartdbg.h>

void hw_duart_putch(int ch) {

    // Wait for Tx FIFO not full
    while(HW_UARTDBGFR_RD() & (1 << 5)) // tx fifo not full
    	;

	HW_UARTDBGDR_WR(ch);
}

int hw_duart_getch() {

    // If receive fifo is empty, return false
    if(HW_UARTDBGFR_RD() & (1 << 4))
    	return -1;

	return HW_UARTDBGDR_RD(); // & 0xFF;
}

// Initialize debug uart
static void hw_duart_init() {

    unsigned int val;
    /* Configure IOMUX */

    /*
       ;;  setup pinmux for primary:
       ;;
       ;;
       ;;  3:2 BANK3_PIN02 RW 0x3 PWM1 pin function selection:
       ;;     00= pwm1;
       ;;     01= rotaryB;
       ;;     10= uart1_tx;
       ;;     11= GPIO.
       ;;  1:0 BANK3_PIN03 RW 0x3 PWM0 pin function selection:
       ;;     00= pwm0;
       ;;     01= rotaryA;
       ;;     10= uart1_rx;
       ;;     11= GPIO

     */

    // REG 0x80018168,0x000000F0
    HW_PINCTRL_MUXSEL6_CLR(
    	BF_PINCTRL_MUXSEL6_BANK3_PIN02(3) +
    	BF_PINCTRL_MUXSEL6_BANK3_PIN03(3)
    );
    // REG 0x80018164,0x000000A0
    HW_PINCTRL_MUXSEL6_SET(
    	BF_PINCTRL_MUXSEL6_BANK3_PIN02(2) +
    	BF_PINCTRL_MUXSEL6_BANK3_PIN03(2)
    );
    // REG 0x80018178,0x0000000F
    HW_PINCTRL_MUXSEL7_CLR(
    	BF_PINCTRL_MUXSEL7_BANK3_PIN16(3) +
    	BF_PINCTRL_MUXSEL7_BANK3_PIN17(3)
    );
    // REG 0x80018174,0x00000005
    HW_PINCTRL_MUXSEL7_SET(
    	BF_PINCTRL_MUXSEL7_BANK3_PIN16(1) +
    	BF_PINCTRL_MUXSEL7_BANK3_PIN17(1)
    );

	// /* check clocks */
	if(HW_CLKCTRL_XTAL_RD() & 0x80000000)
		HW_CLKCTRL_XTAL_CLR(0x80000000);

    /* make sure divider is 1 (24mhz), i.e. easiest to just set it.. */
    val = HW_CLKCTRL_XTAL_RD();
    val &= ~0x3;
    val |= 0x1;
    HW_CLKCTRL_XTAL_WR(val);

    /* Wait for UART to finish transmitting */
	while (!(HW_UARTDBGFR_RD() & (1 << 7))) ;

    // Now that we have clocks, disable debug UART
    HW_UARTDBGCR_WR(0); //Control Reg

    /* Baud rate @115200 baud  */
    HW_UARTDBGIBRD_WR(13);
    HW_UARTDBGFBRD_WR(1);

    // NOTE: This must happen AFTER setting the baud rate!
    // Set for 8 bits, 1 stop, no parity, enable fifo
    HW_UARTDBGLCR_H_WR((0x3 << 5) | 0x10); // 8-bit word, Enable FIFOs

    // Start it up
    HW_UARTDBGCR_WR((0x3 << 8) | 0x1); // enable Tx, Rx and UART
}

hw_initcall(hw_duart_init);
