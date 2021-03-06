/*
 * Low-level beep driver
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

#include "beep.h"
#include "delay/delay.h"

#include <arch/init.h>
#include <registers/regspinctrl.h>

void hw_beep() {

	for(int i = 0; i < 100; i++) {

#ifdef IMX283A
		HW_PINCTRL_DOUT1_SET(1 << 21);
		hw_delay_us(500);
		HW_PINCTRL_DOUT1_CLR(1 << 21);
		hw_delay_us(50);
#else
		HW_PINCTRL_DOUT2_SET(1 << 6);
		hw_delay_us(500);
		HW_PINCTRL_DOUT2_CLR(1 << 6);
		hw_delay_us(50);
#endif
	}
}

static void hw_beep_init() {

#ifdef IMX283A
	HW_PINCTRL_MUXSEL3_SET(BM_PINCTRL_MUXSEL3_BANK1_PIN21);
	HW_PINCTRL_DOE1_SET(1 << 21);
#else
	HW_PINCTRL_MUXSEL4_SET(BM_PINCTRL_MUXSEL4_BANK2_PIN06);
	HW_PINCTRL_DOE2_SET(1 << 6);
#endif
}

hw_initcall(hw_beep_init);
