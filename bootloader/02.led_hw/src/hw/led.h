#pragma once

typedef enum {
	LED_Run,
	LED_Error,
} HW_LEDS;

int hw_led_get(HW_LEDS led);
void hw_led_set(HW_LEDS led, int on);
void hw_led_toggle(HW_LEDS led);
