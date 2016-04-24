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
#pragma once

int putch(int ch);
int getch();
void printhex(int data);
int puts(const char *fmt);
int printf(const char *fmt, ...);
