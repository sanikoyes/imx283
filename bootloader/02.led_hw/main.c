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
#include "hw/led.h"

int main() {

	volatile int i = 0;
	hw_led_set(LED_Run, 1);
	hw_led_set(LED_Error, 0);
	for(;;) {

		hw_led_toggle(LED_Run);
		// hw_led_set(LED_Error, !hw_led_get(LED_Error));
		hw_led_toggle(LED_Error);
		i = 4000000;
		while(i--);
	}
	return 0;
}
