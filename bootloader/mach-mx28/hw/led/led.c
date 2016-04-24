/*
 * Low-level led driver
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
#include "led.h"
#include <arch/init.h>
#include <registers/regspinctrl.h>

int hw_led_get(HW_LEDS led) {

#ifdef IMX283A
	// TODO:
#else
	switch(led) {
	case LED_Run: {
		return (HW_PINCTRL_DOUT2_RD() & (1 << 7)) == 0;
	}
	break;
	case LED_Error: {
		return (HW_PINCTRL_DOUT3_RD() & (1 << 20)) == 0;
	}
	break;
	}
#endif
	return 0;
}

void hw_led_set(HW_LEDS led, int on) {

#ifdef IMX283A
	// TODO:
	// HW_PINCTRL_DOUT1_SET(1 << 22);
#else
	switch(led) {
	case LED_Run: {
		if(on)
			HW_PINCTRL_DOUT2_CLR(1 << 7);
		else
			HW_PINCTRL_DOUT2_SET(1 << 7);
	}
	break;
	case LED_Error: {
		if(on)
			HW_PINCTRL_DOUT3_CLR(1 << 20);
		else
			HW_PINCTRL_DOUT3_SET(1 << 20);
	}
	break;
	}
#endif
}

void hw_led_toggle(HW_LEDS led) {

#ifdef IMX283A
	// TODO:
#else
	switch(led) {
	case LED_Run: {
		HW_PINCTRL_DOUT2_TOG(1 << 7);
	}
	break;
	case LED_Error: {
		HW_PINCTRL_DOUT3_TOG(1 << 20);
	}
	break;
	}
#endif
}

static void hw_led_init(void) {

#ifdef IMX283A
	// TODO:
	HW_PINCTRL_MUXSEL3_SET(BM_PINCTRL_MUXSEL3_BANK1_PIN22);
	HW_PINCTRL_DRIVE6_SET(
		BF_PINCTRL_DRIVE6_BANK1_PIN22_V(1) +
		BF_PINCTRL_DRIVE6_BANK1_PIN22_MA(1));
	HW_PINCTRL_PULL1_SET(1 << 22);
	HW_PINCTRL_DOE1_SET(1 << 22);
	HW_PINCTRL_DOUT1_CLR(1 << 22);
#else
	HW_PINCTRL_MUXSEL4_SET(BM_PINCTRL_MUXSEL4_BANK2_PIN07);
	HW_PINCTRL_DRIVE8_SET(
		BF_PINCTRL_DRIVE8_BANK2_PIN07_V(1) +
		BF_PINCTRL_DRIVE8_BANK2_PIN07_MA(1)
	);
	HW_PINCTRL_PULL2_SET(1 << 7);
	HW_PINCTRL_DOE2_SET(1 << 7);
	HW_PINCTRL_DOUT2_SET(1 << 7);

	HW_PINCTRL_MUXSEL7_SET(BM_PINCTRL_MUXSEL7_BANK3_PIN20);
	HW_PINCTRL_DRIVE14_SET(
		BF_PINCTRL_DRIVE14_BANK3_PIN20_V(1) +
		BF_PINCTRL_DRIVE14_BANK3_PIN20_MA(1)
	);
	HW_PINCTRL_PULL3_SET(1 << 20);
	HW_PINCTRL_DOE3_SET(1 << 20);
	HW_PINCTRL_DOUT3_SET(1 << 20);
#endif
}

hw_initcall(hw_led_init);
