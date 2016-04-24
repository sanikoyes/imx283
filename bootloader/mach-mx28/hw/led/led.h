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
#pragma once

typedef enum {
	LED_Run,
	LED_Error,
} HW_LEDS;

int hw_led_get(HW_LEDS led);
void hw_led_set(HW_LEDS led, int on);
void hw_led_toggle(HW_LEDS led);
