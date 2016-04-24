/*
 * main
 *
 * sanikoyes <sanikoyes@163.com>
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2.  This program  is licensed "as is" without any warranty of any
 * kind,whether express or implied.
 */
#include <stdarg.h>
#include <registers/regspinctrl.h>

int main() {

#ifdef IMX283A
	HW_PINCTRL_MUXSEL3_SET(BM_PINCTRL_MUXSEL3_BANK1_PIN22);
	HW_PINCTRL_DRIVE6_SET(
		BF_PINCTRL_DRIVE6_BANK1_PIN22_V(1) +
		BF_PINCTRL_DRIVE6_BANK1_PIN22_MA(1));
	HW_PINCTRL_PULL1_SET(1 << 22);
	HW_PINCTRL_DOE1_SET(1 << 22);
	HW_PINCTRL_DOUT1_SET(1 << 22);
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

	volatile int i = 0;
	for(;;) {

#ifdef IMX283A
		HW_PINCTRL_DOUT1_SET(1 << 22);
#else
		HW_PINCTRL_DOUT2_SET(1 << 7);
		HW_PINCTRL_DOUT3_CLR(1 << 20);
#endif
		i = 4000000;
		while(i--);
#ifdef IMX283A
		HW_PINCTRL_DOUT1_CLR(1 << 22);
#else
		HW_PINCTRL_DOUT2_CLR(1 << 7);
		HW_PINCTRL_DOUT3_SET(1 << 20);
#endif
		i = 4000000;
		while(i--);
	}
	return 0;
}
