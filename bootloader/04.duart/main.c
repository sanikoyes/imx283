/*
 * main
 *
 * sanikoyes <sanikoyes@163.com>
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2.  This program  is licensed "as is" without any warranty of any
 * kind,whether express or implied.
 */
#include "led/led.h"
#include "beep/beep.h"
#include "sys/print.h"

int main() {

	hw_beep();

	hw_led_set(LED_Run, 1);
	hw_led_set(LED_Error, 0);

    printf("Please input char to test UART input function\n");
    for(;;) {

    	int ch = getch();
    	if(ch == -1)
    		continue;
    	putch(ch);

    	// printhex(ch);
    	// printf("\n");

		hw_led_toggle(LED_Run);
		hw_led_toggle(LED_Error);
    }
	return 0;
}
