/*
 * Low-level delay driver
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
#include "delay.h"
#include <registers/regsdigctl.h>

void hw_delay_us(int us) {
	
	unsigned int start , cur;
	start = cur = HW_DIGCTL_MICROSECONDS_RD();

	while (cur < start+us) {

		cur = HW_DIGCTL_MICROSECONDS_RD();
		/*printf("0x%x\r\n",cur);*/
	}
}

void hw_delay_ms(int ms) {

	hw_delay_us(ms * 1000);
}
