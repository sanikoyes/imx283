/*
 * Low-level debug library
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
#include "print.h"
#include "uart/duart.h"

#include <stdarg.h>

int putch(int ch) {

    // Replace line feed with '\r'
    if(ch == '\n')
    	hw_duart_putch('\r');
    hw_duart_putch(ch);
	// Append line return with '\n'
    if(ch == '\r')
    	hw_duart_putch('\n');
    return 0;
}

int getch() {

	return hw_duart_getch();
}

void printhex(int data) {

	int i = 0;
	char c;
	for (i = sizeof(int)*2-1; i >= 0; i--) {
		c = data>>(i*4);
		c &= 0xf;
		if (c > 9)
			putch(c-10+'A');
		else
			putch(c+'0');
	}
}

int puts(const char *fmt) {

	while (*fmt) {

		putch(*fmt);
		fmt++;
	}
	putch('\n');
	return 0;
}

int printf(const char *fmt, ...) {

	va_list args;
	va_start(args, fmt);
	while (*fmt) {

		if (*fmt == '%') {
			fmt++;
			switch (*fmt) {

			case 'x':
			case 'X':
				printhex(va_arg(args, int));
				break;
			case '%':
				putch('%');
				break;
			default:
				break;
			}

		} else {
			putch(*fmt);
		}
		fmt++;
	}
	va_end(args);
	return 0;
}
