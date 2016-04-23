/*
 * Copyright 2008-2009 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

 * WARNING!  THIS FILE IS AUTOMATICALLY GENERATED FROM XML.
 *                DO NOT MODIFY THIS FILE DIRECTLY.
 *
 * Xml Revision: 1.11
 *
 * Template revision: 26195
 *
 *
 * The following naming conventions are followed in this file.
 *      XX_<module>_<regname>_<field>
 *
 * XX specifies the define / macro class
 *      HW pertains to a register
 *      BM indicates a Bit Mask
 *      BF indicates a Bit Field macro
 *
 * <module> is the hardware module name which can be any of the following...
 *      USB20 (Note when there is more than one copy of a given module, the
 *      module name includes a number starting from 0 for the first instance
 *      of that module)
 *
 * <regname> is the specific register within that module
 *
 * <field> is the specific bitfield within that <module>_<register>
 *
 * We also define the following...
 *      hw_<module>_<regname>_t is typedef of anonymous union
 *
 */

#ifndef _CAN_H
#define _CAN_H  1

#include "regs.h"

#ifndef REGS_CAN_BASE
#define REGS_CAN0_BASE (REGS_BASE + 0x32000)
#define REGS_CAN1_BASE (REGS_BASE + 0x34000)
#define REGS_CAN_BASE(x) ( x == 0 ? REGS_CAN0_BASE : x == 1 ? REGS_CAN1_BASE : 0xffff0000)
#endif

/*
 * HW_CAN_MCR - Module Configuration Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MAXMB     :  6;
        unsigned RSVD0     :  2;
        unsigned IDAM      :  2;
        unsigned RSVD1     :  2;
        unsigned AEN       :  1;
        unsigned LPRIO_EN  :  1;
        unsigned RSVD2     :  2;
        unsigned BCC       :  1;
        unsigned SRX_DIS   :  1;
        unsigned RSVD3     :  1;
        unsigned WAK_SRC   :  1;
        unsigned LPM_ACK   :  1;
        unsigned WRN_EN    :  1;
        unsigned SLF_WAK   :  1;
        unsigned SUPV      :  1;
        unsigned FRZ_ACK   :  1;
        unsigned SOFT_RST  :  1;
        unsigned WAK_MSK   :  1;
        unsigned NOT_RDY   :  1;
        unsigned HALT      :  1;
        unsigned FEN       :  1;
        unsigned FRZ       :  1;
        unsigned MDIS      :  1;
    } B;
} hw_can_mcr_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_MCR register
 */
#define HW_CAN_MCR_ADDR(x)      (REGS_CAN_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_MCR(x)           (*(volatile hw_can_mcr_t *) HW_CAN_MCR_ADDR(x))
#define HW_CAN_MCR_RD(x)      (HW_CAN_MCR(x).U)
#define HW_CAN_MCR_WR(x, v)     (HW_CAN_MCR(x).U = (v))
#define HW_CAN_MCR_SET(x, v)    (HW_CAN_MCR_WR(x, HW_CAN_MCR_RD(x) |  (v)))
#define HW_CAN_MCR_CLR(x, v)    (HW_CAN_MCR_WR(x, HW_CAN_MCR_RD(x) & ~(v)))
#define HW_CAN_MCR_TOG(x, v)    (HW_CAN_MCR_WR(x, HW_CAN_MCR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_MCR bitfields
 */
/* --- Register HW_CAN_MCR, field MDIS */

#define BP_CAN_MCR_MDIS      31
#define BM_CAN_MCR_MDIS      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_CAN_MCR_MDIS(v)   ((((reg32_t) v) << 31) & BM_CAN_MCR_MDIS)
#else
#define BF_CAN_MCR_MDIS(v)   (((v) << 31) & BM_CAN_MCR_MDIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_MDIS(n, v)   BFn_CS1(CAN_MCR, n, MDIS, v)
#endif

/* --- Register HW_CAN_MCR, field FRZ */

#define BP_CAN_MCR_FRZ      30
#define BM_CAN_MCR_FRZ      0x40000000

#define BF_CAN_MCR_FRZ(v)   (((v) << 30) & BM_CAN_MCR_FRZ)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_FRZ(n, v)   BFn_CS1(CAN_MCR, n, FRZ, v)
#endif

/* --- Register HW_CAN_MCR, field FEN */

#define BP_CAN_MCR_FEN      29
#define BM_CAN_MCR_FEN      0x20000000

#define BF_CAN_MCR_FEN(v)   (((v) << 29) & BM_CAN_MCR_FEN)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_FEN(n, v)   BFn_CS1(CAN_MCR, n, FEN, v)
#endif

/* --- Register HW_CAN_MCR, field HALT */

#define BP_CAN_MCR_HALT      28
#define BM_CAN_MCR_HALT      0x10000000

#define BF_CAN_MCR_HALT(v)   (((v) << 28) & BM_CAN_MCR_HALT)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_HALT(n, v)   BFn_CS1(CAN_MCR, n, HALT, v)
#endif

/* --- Register HW_CAN_MCR, field NOT_RDY */

#define BP_CAN_MCR_NOT_RDY      27
#define BM_CAN_MCR_NOT_RDY      0x08000000

#define BF_CAN_MCR_NOT_RDY(v)   (((v) << 27) & BM_CAN_MCR_NOT_RDY)
/* --- Register HW_CAN_MCR, field WAK_MSK */

#define BP_CAN_MCR_WAK_MSK      26
#define BM_CAN_MCR_WAK_MSK      0x04000000

#define BF_CAN_MCR_WAK_MSK(v)   (((v) << 26) & BM_CAN_MCR_WAK_MSK)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_WAK_MSK(n, v)   BFn_CS1(CAN_MCR, n, WAK_MSK, v)
#endif

/* --- Register HW_CAN_MCR, field SOFT_RST */

#define BP_CAN_MCR_SOFT_RST      25
#define BM_CAN_MCR_SOFT_RST      0x02000000

#define BF_CAN_MCR_SOFT_RST(v)   (((v) << 25) & BM_CAN_MCR_SOFT_RST)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_SOFT_RST(n, v)   BFn_CS1(CAN_MCR, n, SOFT_RST, v)
#endif

/* --- Register HW_CAN_MCR, field FRZ_ACK */

#define BP_CAN_MCR_FRZ_ACK      24
#define BM_CAN_MCR_FRZ_ACK      0x01000000

#define BF_CAN_MCR_FRZ_ACK(v)   (((v) << 24) & BM_CAN_MCR_FRZ_ACK)
/* --- Register HW_CAN_MCR, field SUPV */

#define BP_CAN_MCR_SUPV      23
#define BM_CAN_MCR_SUPV      0x00800000

#define BF_CAN_MCR_SUPV(v)   (((v) << 23) & BM_CAN_MCR_SUPV)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_SUPV(n, v)   BFn_CS1(CAN_MCR, n, SUPV, v)
#endif

/* --- Register HW_CAN_MCR, field SLF_WAK */

#define BP_CAN_MCR_SLF_WAK      22
#define BM_CAN_MCR_SLF_WAK      0x00400000

#define BF_CAN_MCR_SLF_WAK(v)   (((v) << 22) & BM_CAN_MCR_SLF_WAK)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_SLF_WAK(n, v)   BFn_CS1(CAN_MCR, n, SLF_WAK, v)
#endif

/* --- Register HW_CAN_MCR, field WRN_EN */

#define BP_CAN_MCR_WRN_EN      21
#define BM_CAN_MCR_WRN_EN      0x00200000

#define BF_CAN_MCR_WRN_EN(v)   (((v) << 21) & BM_CAN_MCR_WRN_EN)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_WRN_EN(n, v)   BFn_CS1(CAN_MCR, n, WRN_EN, v)
#endif

/* --- Register HW_CAN_MCR, field LPM_ACK */

#define BP_CAN_MCR_LPM_ACK      20
#define BM_CAN_MCR_LPM_ACK      0x00100000

#define BF_CAN_MCR_LPM_ACK(v)   (((v) << 20) & BM_CAN_MCR_LPM_ACK)
/* --- Register HW_CAN_MCR, field WAK_SRC */

#define BP_CAN_MCR_WAK_SRC      19
#define BM_CAN_MCR_WAK_SRC      0x00080000

#define BF_CAN_MCR_WAK_SRC(v)   (((v) << 19) & BM_CAN_MCR_WAK_SRC)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_WAK_SRC(n, v)   BFn_CS1(CAN_MCR, n, WAK_SRC, v)
#endif

/* --- Register HW_CAN_MCR, field RSVD3 */

#define BP_CAN_MCR_RSVD3      18
#define BM_CAN_MCR_RSVD3      0x00040000

#define BF_CAN_MCR_RSVD3(v)   (((v) << 18) & BM_CAN_MCR_RSVD3)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_RSVD3(n, v)   BFn_CS1(CAN_MCR, n, RSVD3, v)
#endif

/* --- Register HW_CAN_MCR, field SRX_DIS */

#define BP_CAN_MCR_SRX_DIS      17
#define BM_CAN_MCR_SRX_DIS      0x00020000

#define BF_CAN_MCR_SRX_DIS(v)   (((v) << 17) & BM_CAN_MCR_SRX_DIS)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_SRX_DIS(n, v)   BFn_CS1(CAN_MCR, n, SRX_DIS, v)
#endif

/* --- Register HW_CAN_MCR, field BCC */

#define BP_CAN_MCR_BCC      16
#define BM_CAN_MCR_BCC      0x00010000

#define BF_CAN_MCR_BCC(v)   (((v) << 16) & BM_CAN_MCR_BCC)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_BCC(n, v)   BFn_CS1(CAN_MCR, n, BCC, v)
#endif

/* --- Register HW_CAN_MCR, field RSVD2 */

#define BP_CAN_MCR_RSVD2      14
#define BM_CAN_MCR_RSVD2      0x0000C000

#define BF_CAN_MCR_RSVD2(v)   (((v) << 14) & BM_CAN_MCR_RSVD2)
/* --- Register HW_CAN_MCR, field LPRIO_EN */

#define BP_CAN_MCR_LPRIO_EN      13
#define BM_CAN_MCR_LPRIO_EN      0x00002000

#define BF_CAN_MCR_LPRIO_EN(v)   (((v) << 13) & BM_CAN_MCR_LPRIO_EN)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_LPRIO_EN(n, v)   BFn_CS1(CAN_MCR, n, LPRIO_EN, v)
#endif

/* --- Register HW_CAN_MCR, field AEN */

#define BP_CAN_MCR_AEN      12
#define BM_CAN_MCR_AEN      0x00001000

#define BF_CAN_MCR_AEN(v)   (((v) << 12) & BM_CAN_MCR_AEN)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_AEN(n, v)   BFn_CS1(CAN_MCR, n, AEN, v)
#endif

/* --- Register HW_CAN_MCR, field RSVD1 */

#define BP_CAN_MCR_RSVD1      10
#define BM_CAN_MCR_RSVD1      0x00000C00

#define BF_CAN_MCR_RSVD1(v)   (((v) << 10) & BM_CAN_MCR_RSVD1)
/* --- Register HW_CAN_MCR, field IDAM */

#define BP_CAN_MCR_IDAM      8
#define BM_CAN_MCR_IDAM      0x00000300

#define BF_CAN_MCR_IDAM(v)   (((v) << 8) & BM_CAN_MCR_IDAM)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_IDAM(n, v)   BFn_CS1(CAN_MCR, n, IDAM, v)
#endif

/* --- Register HW_CAN_MCR, field RSVD0 */

#define BP_CAN_MCR_RSVD0      6
#define BM_CAN_MCR_RSVD0      0x000000C0

#define BF_CAN_MCR_RSVD0(v)   (((v) << 6) & BM_CAN_MCR_RSVD0)
/* --- Register HW_CAN_MCR, field MAXMB */

#define BP_CAN_MCR_MAXMB      0
#define BM_CAN_MCR_MAXMB      0x0000003F

#define BF_CAN_MCR_MAXMB(v)   (((v) << 0) & BM_CAN_MCR_MAXMB)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MCR_MAXMB(n, v)   BFn_CS1(CAN_MCR, n, MAXMB, v)
#endif



/*
 * HW_CAN_CTRL - Control Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PROP_SEG  :  3;
        unsigned LOM       :  1;
        unsigned LBUF      :  1;
        unsigned TSYN      :  1;
        unsigned BOFF_REC  :  1;
        unsigned SMP       :  1;
        unsigned RSVD      :  2;
        unsigned RWRN_MSK  :  1;
        unsigned TWRN_MSK  :  1;
        unsigned LPB       :  1;
        unsigned CLK_SRC   :  1;
        unsigned ERR_MSK   :  1;
        unsigned BOFF_MSK  :  1;
        unsigned PSEG2     :  3;
        unsigned PSEG1     :  3;
        unsigned RJW       :  2;
        unsigned PRESDIV   :  8;
    } B;
} hw_can_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_CTRL register
 */
#define HW_CAN_CTRL_ADDR(x)      (REGS_CAN_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_CTRL(x)           (*(volatile hw_can_ctrl_t *) HW_CAN_CTRL_ADDR(x))
#define HW_CAN_CTRL_RD(x)      (HW_CAN_CTRL(x).U)
#define HW_CAN_CTRL_WR(x, v)     (HW_CAN_CTRL(x).U = (v))
#define HW_CAN_CTRL_SET(x, v)    (HW_CAN_CTRL_WR(x, HW_CAN_CTRL_RD(x) |  (v)))
#define HW_CAN_CTRL_CLR(x, v)    (HW_CAN_CTRL_WR(x, HW_CAN_CTRL_RD(x) & ~(v)))
#define HW_CAN_CTRL_TOG(x, v)    (HW_CAN_CTRL_WR(x, HW_CAN_CTRL_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_CTRL bitfields
 */
/* --- Register HW_CAN_CTRL, field PRESDIV */

#define BP_CAN_CTRL_PRESDIV      24
#define BM_CAN_CTRL_PRESDIV      0xFF000000

#ifndef __LANGUAGE_ASM__
#define BF_CAN_CTRL_PRESDIV(v)   ((((reg32_t) v) << 24) & BM_CAN_CTRL_PRESDIV)
#else
#define BF_CAN_CTRL_PRESDIV(v)   (((v) << 24) & BM_CAN_CTRL_PRESDIV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_PRESDIV(n, v)   (HW_CAN_CTRL(n).B.PRESDIV = (v))
#endif

/* --- Register HW_CAN_CTRL, field RJW */

#define BP_CAN_CTRL_RJW      22
#define BM_CAN_CTRL_RJW      0x00C00000

#define BF_CAN_CTRL_RJW(v)   (((v) << 22) & BM_CAN_CTRL_RJW)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_RJW(n, v)   BFn_CS1(CAN_CTRL, n, RJW, v)
#endif

/* --- Register HW_CAN_CTRL, field PSEG1 */

#define BP_CAN_CTRL_PSEG1      19
#define BM_CAN_CTRL_PSEG1      0x00380000

#define BF_CAN_CTRL_PSEG1(v)   (((v) << 19) & BM_CAN_CTRL_PSEG1)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_PSEG1(n, v)   BFn_CS1(CAN_CTRL, n, PSEG1, v)
#endif

/* --- Register HW_CAN_CTRL, field PSEG2 */

#define BP_CAN_CTRL_PSEG2      16
#define BM_CAN_CTRL_PSEG2      0x00070000

#define BF_CAN_CTRL_PSEG2(v)   (((v) << 16) & BM_CAN_CTRL_PSEG2)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_PSEG2(n, v)   BFn_CS1(CAN_CTRL, n, PSEG2, v)
#endif

/* --- Register HW_CAN_CTRL, field BOFF_MSK */

#define BP_CAN_CTRL_BOFF_MSK      15
#define BM_CAN_CTRL_BOFF_MSK      0x00008000

#define BF_CAN_CTRL_BOFF_MSK(v)   (((v) << 15) & BM_CAN_CTRL_BOFF_MSK)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_BOFF_MSK(n, v)   BFn_CS1(CAN_CTRL, n, BOFF_MSK, v)
#endif

/* --- Register HW_CAN_CTRL, field ERR_MSK */

#define BP_CAN_CTRL_ERR_MSK      14
#define BM_CAN_CTRL_ERR_MSK      0x00004000

#define BF_CAN_CTRL_ERR_MSK(v)   (((v) << 14) & BM_CAN_CTRL_ERR_MSK)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_ERR_MSK(n, v)   BFn_CS1(CAN_CTRL, n, ERR_MSK, v)
#endif

/* --- Register HW_CAN_CTRL, field CLK_SRC */

#define BP_CAN_CTRL_CLK_SRC      13
#define BM_CAN_CTRL_CLK_SRC      0x00002000

#define BF_CAN_CTRL_CLK_SRC(v)   (((v) << 13) & BM_CAN_CTRL_CLK_SRC)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_CLK_SRC(n, v)   BFn_CS1(CAN_CTRL, n, CLK_SRC, v)
#endif

/* --- Register HW_CAN_CTRL, field LPB */

#define BP_CAN_CTRL_LPB      12
#define BM_CAN_CTRL_LPB      0x00001000

#define BF_CAN_CTRL_LPB(v)   (((v) << 12) & BM_CAN_CTRL_LPB)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_LPB(n, v)   BFn_CS1(CAN_CTRL, n, LPB, v)
#endif

/* --- Register HW_CAN_CTRL, field TWRN_MSK */

#define BP_CAN_CTRL_TWRN_MSK      11
#define BM_CAN_CTRL_TWRN_MSK      0x00000800

#define BF_CAN_CTRL_TWRN_MSK(v)   (((v) << 11) & BM_CAN_CTRL_TWRN_MSK)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_TWRN_MSK(n, v)   BFn_CS1(CAN_CTRL, n, TWRN_MSK, v)
#endif

/* --- Register HW_CAN_CTRL, field RWRN_MSK */

#define BP_CAN_CTRL_RWRN_MSK      10
#define BM_CAN_CTRL_RWRN_MSK      0x00000400

#define BF_CAN_CTRL_RWRN_MSK(v)   (((v) << 10) & BM_CAN_CTRL_RWRN_MSK)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_RWRN_MSK(n, v)   BFn_CS1(CAN_CTRL, n, RWRN_MSK, v)
#endif

/* --- Register HW_CAN_CTRL, field RSVD */

#define BP_CAN_CTRL_RSVD      8
#define BM_CAN_CTRL_RSVD      0x00000300

#define BF_CAN_CTRL_RSVD(v)   (((v) << 8) & BM_CAN_CTRL_RSVD)
/* --- Register HW_CAN_CTRL, field SMP */

#define BP_CAN_CTRL_SMP      7
#define BM_CAN_CTRL_SMP      0x00000080

#define BF_CAN_CTRL_SMP(v)   (((v) << 7) & BM_CAN_CTRL_SMP)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_SMP(n, v)   BFn_CS1(CAN_CTRL, n, SMP, v)
#endif

/* --- Register HW_CAN_CTRL, field BOFF_REC */

#define BP_CAN_CTRL_BOFF_REC      6
#define BM_CAN_CTRL_BOFF_REC      0x00000040

#define BF_CAN_CTRL_BOFF_REC(v)   (((v) << 6) & BM_CAN_CTRL_BOFF_REC)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_BOFF_REC(n, v)   BFn_CS1(CAN_CTRL, n, BOFF_REC, v)
#endif

/* --- Register HW_CAN_CTRL, field TSYN */

#define BP_CAN_CTRL_TSYN      5
#define BM_CAN_CTRL_TSYN      0x00000020

#define BF_CAN_CTRL_TSYN(v)   (((v) << 5) & BM_CAN_CTRL_TSYN)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_TSYN(n, v)   BFn_CS1(CAN_CTRL, n, TSYN, v)
#endif

/* --- Register HW_CAN_CTRL, field LBUF */

#define BP_CAN_CTRL_LBUF      4
#define BM_CAN_CTRL_LBUF      0x00000010

#define BF_CAN_CTRL_LBUF(v)   (((v) << 4) & BM_CAN_CTRL_LBUF)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_LBUF(n, v)   BFn_CS1(CAN_CTRL, n, LBUF, v)
#endif

/* --- Register HW_CAN_CTRL, field LOM */

#define BP_CAN_CTRL_LOM      3
#define BM_CAN_CTRL_LOM      0x00000008

#define BF_CAN_CTRL_LOM(v)   (((v) << 3) & BM_CAN_CTRL_LOM)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_LOM(n, v)   BFn_CS1(CAN_CTRL, n, LOM, v)
#endif

/* --- Register HW_CAN_CTRL, field PROP_SEG */

#define BP_CAN_CTRL_PROP_SEG      0
#define BM_CAN_CTRL_PROP_SEG      0x00000007

#define BF_CAN_CTRL_PROP_SEG(v)   (((v) << 0) & BM_CAN_CTRL_PROP_SEG)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_CTRL_PROP_SEG(n, v)   BFn_CS1(CAN_CTRL, n, PROP_SEG, v)
#endif



/*
 * HW_CAN_TIMER - Free Running Timer
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TIMER  : 16;
        unsigned RSVD   : 16;
    } B;
} hw_can_timer_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_TIMER register
 */
#define HW_CAN_TIMER_ADDR(x)      (REGS_CAN_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_TIMER(x)           (*(volatile hw_can_timer_t *) HW_CAN_TIMER_ADDR(x))
#define HW_CAN_TIMER_RD(x)      (HW_CAN_TIMER(x).U)
#define HW_CAN_TIMER_WR(x, v)     (HW_CAN_TIMER(x).U = (v))
#define HW_CAN_TIMER_SET(x, v)    (HW_CAN_TIMER_WR(x, HW_CAN_TIMER_RD(x) |  (v)))
#define HW_CAN_TIMER_CLR(x, v)    (HW_CAN_TIMER_WR(x, HW_CAN_TIMER_RD(x) & ~(v)))
#define HW_CAN_TIMER_TOG(x, v)    (HW_CAN_TIMER_WR(x, HW_CAN_TIMER_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_TIMER bitfields
 */
/* --- Register HW_CAN_TIMER, field RSVD */

#define BP_CAN_TIMER_RSVD      16
#define BM_CAN_TIMER_RSVD      0xFFFF0000

#ifndef __LANGUAGE_ASM__
#define BF_CAN_TIMER_RSVD(v)   ((((reg32_t) v) << 16) & BM_CAN_TIMER_RSVD)
#else
#define BF_CAN_TIMER_RSVD(v)   (((v) << 16) & BM_CAN_TIMER_RSVD)
#endif
/* --- Register HW_CAN_TIMER, field TIMER */

#define BP_CAN_TIMER_TIMER      0
#define BM_CAN_TIMER_TIMER      0x0000FFFF

#define BF_CAN_TIMER_TIMER(v)   (((v) << 0) & BM_CAN_TIMER_TIMER)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_TIMER_TIMER(n, v)   (HW_CAN_TIMER(n).B.TIMER = (v))
#endif



/*
 * HW_CAN_RXGMASK - Rx Global Mask
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MI  : 32;
    } B;
} hw_can_rxgmask_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_RXGMASK register
 */
#define HW_CAN_RXGMASK_ADDR(x)      (REGS_CAN_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_RXGMASK(x)           (*(volatile hw_can_rxgmask_t *) HW_CAN_RXGMASK_ADDR(x))
#define HW_CAN_RXGMASK_RD(x)      (HW_CAN_RXGMASK(x).U)
#define HW_CAN_RXGMASK_WR(x, v)     (HW_CAN_RXGMASK(x).U = (v))
#define HW_CAN_RXGMASK_SET(x, v)    (HW_CAN_RXGMASK_WR(x, HW_CAN_RXGMASK_RD(x) |  (v)))
#define HW_CAN_RXGMASK_CLR(x, v)    (HW_CAN_RXGMASK_WR(x, HW_CAN_RXGMASK_RD(x) & ~(v)))
#define HW_CAN_RXGMASK_TOG(x, v)    (HW_CAN_RXGMASK_WR(x, HW_CAN_RXGMASK_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_RXGMASK bitfields
 */
/* --- Register HW_CAN_RXGMASK, field MI */

#define BP_CAN_RXGMASK_MI      0
#define BM_CAN_RXGMASK_MI      0xFFFFFFFF

#ifndef __LANGUAGE_ASM__
#define BF_CAN_RXGMASK_MI(v)   ((reg32_t) v)
#else
#define BF_CAN_RXGMASK_MI(v)   (v)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CAN_RXGMASK_MI(n, v)   (HW_CAN_RXGMASK(n).B.MI = (v))
#endif



/*
 * HW_CAN_RX14MASK - Rx 14 Mask
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MI  : 32;
    } B;
} hw_can_rx14mask_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_RX14MASK register
 */
#define HW_CAN_RX14MASK_ADDR(x)      (REGS_CAN_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_RX14MASK(x)           (*(volatile hw_can_rx14mask_t *) HW_CAN_RX14MASK_ADDR(x))
#define HW_CAN_RX14MASK_RD(x)      (HW_CAN_RX14MASK(x).U)
#define HW_CAN_RX14MASK_WR(x, v)     (HW_CAN_RX14MASK(x).U = (v))
#define HW_CAN_RX14MASK_SET(x, v)    (HW_CAN_RX14MASK_WR(x, HW_CAN_RX14MASK_RD(x) |  (v)))
#define HW_CAN_RX14MASK_CLR(x, v)    (HW_CAN_RX14MASK_WR(x, HW_CAN_RX14MASK_RD(x) & ~(v)))
#define HW_CAN_RX14MASK_TOG(x, v)    (HW_CAN_RX14MASK_WR(x, HW_CAN_RX14MASK_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_RX14MASK bitfields
 */
/* --- Register HW_CAN_RX14MASK, field MI */

#define BP_CAN_RX14MASK_MI      0
#define BM_CAN_RX14MASK_MI      0xFFFFFFFF

#ifndef __LANGUAGE_ASM__
#define BF_CAN_RX14MASK_MI(v)   ((reg32_t) v)
#else
#define BF_CAN_RX14MASK_MI(v)   (v)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CAN_RX14MASK_MI(n, v)   (HW_CAN_RX14MASK(n).B.MI = (v))
#endif



/*
 * HW_CAN_RX15MASK - Rx 15 Mask
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MI  : 32;
    } B;
} hw_can_rx15mask_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_RX15MASK register
 */
#define HW_CAN_RX15MASK_ADDR(x)      (REGS_CAN_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_RX15MASK(x)           (*(volatile hw_can_rx15mask_t *) HW_CAN_RX15MASK_ADDR(x))
#define HW_CAN_RX15MASK_RD(x)      (HW_CAN_RX15MASK(x).U)
#define HW_CAN_RX15MASK_WR(x, v)     (HW_CAN_RX15MASK(x).U = (v))
#define HW_CAN_RX15MASK_SET(x, v)    (HW_CAN_RX15MASK_WR(x, HW_CAN_RX15MASK_RD(x) |  (v)))
#define HW_CAN_RX15MASK_CLR(x, v)    (HW_CAN_RX15MASK_WR(x, HW_CAN_RX15MASK_RD(x) & ~(v)))
#define HW_CAN_RX15MASK_TOG(x, v)    (HW_CAN_RX15MASK_WR(x, HW_CAN_RX15MASK_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_RX15MASK bitfields
 */
/* --- Register HW_CAN_RX15MASK, field MI */

#define BP_CAN_RX15MASK_MI      0
#define BM_CAN_RX15MASK_MI      0xFFFFFFFF

#ifndef __LANGUAGE_ASM__
#define BF_CAN_RX15MASK_MI(v)   ((reg32_t) v)
#else
#define BF_CAN_RX15MASK_MI(v)   (v)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CAN_RX15MASK_MI(n, v)   (HW_CAN_RX15MASK(n).B.MI = (v))
#endif



/*
 * HW_CAN_ECR - Error Counter Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TX_ERR_COUNTER  :  8;
        unsigned RX_ERR_COUNTER  :  8;
        unsigned RSVD            : 16;
    } B;
} hw_can_ecr_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_ECR register
 */
#define HW_CAN_ECR_ADDR(x)      (REGS_CAN_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_ECR(x)           (*(volatile hw_can_ecr_t *) HW_CAN_ECR_ADDR(x))
#define HW_CAN_ECR_RD(x)      (HW_CAN_ECR(x).U)
#define HW_CAN_ECR_WR(x, v)     (HW_CAN_ECR(x).U = (v))
#define HW_CAN_ECR_SET(x, v)    (HW_CAN_ECR_WR(x, HW_CAN_ECR_RD(x) |  (v)))
#define HW_CAN_ECR_CLR(x, v)    (HW_CAN_ECR_WR(x, HW_CAN_ECR_RD(x) & ~(v)))
#define HW_CAN_ECR_TOG(x, v)    (HW_CAN_ECR_WR(x, HW_CAN_ECR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_ECR bitfields
 */
/* --- Register HW_CAN_ECR, field RSVD */

#define BP_CAN_ECR_RSVD      16
#define BM_CAN_ECR_RSVD      0xFFFF0000

#ifndef __LANGUAGE_ASM__
#define BF_CAN_ECR_RSVD(v)   ((((reg32_t) v) << 16) & BM_CAN_ECR_RSVD)
#else
#define BF_CAN_ECR_RSVD(v)   (((v) << 16) & BM_CAN_ECR_RSVD)
#endif
/* --- Register HW_CAN_ECR, field RX_ERR_COUNTER */

#define BP_CAN_ECR_RX_ERR_COUNTER      8
#define BM_CAN_ECR_RX_ERR_COUNTER      0x0000FF00

#define BF_CAN_ECR_RX_ERR_COUNTER(v)   (((v) << 8) & BM_CAN_ECR_RX_ERR_COUNTER)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_ECR_RX_ERR_COUNTER(n, v)   (HW_CAN_ECR(n).B.RX_ERR_COUNTER = (v))
#endif

/* --- Register HW_CAN_ECR, field TX_ERR_COUNTER */

#define BP_CAN_ECR_TX_ERR_COUNTER      0
#define BM_CAN_ECR_TX_ERR_COUNTER      0x000000FF

#define BF_CAN_ECR_TX_ERR_COUNTER(v)   (((v) << 0) & BM_CAN_ECR_TX_ERR_COUNTER)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_ECR_TX_ERR_COUNTER(n, v)   (HW_CAN_ECR(n).B.TX_ERR_COUNTER = (v))
#endif



/*
 * HW_CAN_ESR - Error and Status Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WAK_INT    :  1;
        unsigned ERR_INT    :  1;
        unsigned BOFF_INT   :  1;
        unsigned RSVD0      :  1;
        unsigned FLT_CONF   :  2;
        unsigned TXRX       :  1;
        unsigned IDLE       :  1;
        unsigned RX_WRN     :  1;
        unsigned TX_WRN     :  1;
        unsigned STF_ERR    :  1;
        unsigned FRM_ERR    :  1;
        unsigned CRC_ERR    :  1;
        unsigned ACK_ERR    :  1;
        unsigned BIT0_ERR   :  1;
        unsigned BIT1_ERR   :  1;
        unsigned RWRN_INT   :  1;
        unsigned TWRN_INT   :  1;
        unsigned RSVD1      : 14;
    } B;
} hw_can_esr_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_ESR register
 */
#define HW_CAN_ESR_ADDR(x)      (REGS_CAN_BASE(x) + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_ESR(x)           (*(volatile hw_can_esr_t *) HW_CAN_ESR_ADDR(x))
#define HW_CAN_ESR_RD(x)      (HW_CAN_ESR(x).U)
#define HW_CAN_ESR_WR(x, v)     (HW_CAN_ESR(x).U = (v))
#define HW_CAN_ESR_SET(x, v)    (HW_CAN_ESR_WR(x, HW_CAN_ESR_RD(x) |  (v)))
#define HW_CAN_ESR_CLR(x, v)    (HW_CAN_ESR_WR(x, HW_CAN_ESR_RD(x) & ~(v)))
#define HW_CAN_ESR_TOG(x, v)    (HW_CAN_ESR_WR(x, HW_CAN_ESR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_ESR bitfields
 */
/* --- Register HW_CAN_ESR, field RSVD1 */

#define BP_CAN_ESR_RSVD1      18
#define BM_CAN_ESR_RSVD1      0xFFFC0000

#ifndef __LANGUAGE_ASM__
#define BF_CAN_ESR_RSVD1(v)   ((((reg32_t) v) << 18) & BM_CAN_ESR_RSVD1)
#else
#define BF_CAN_ESR_RSVD1(v)   (((v) << 18) & BM_CAN_ESR_RSVD1)
#endif
/* --- Register HW_CAN_ESR, field TWRN_INT */

#define BP_CAN_ESR_TWRN_INT      17
#define BM_CAN_ESR_TWRN_INT      0x00020000

#define BF_CAN_ESR_TWRN_INT(v)   (((v) << 17) & BM_CAN_ESR_TWRN_INT)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_ESR_TWRN_INT(n, v)   BFn_CS1(CAN_ESR, n, TWRN_INT, v)
#endif

/* --- Register HW_CAN_ESR, field RWRN_INT */

#define BP_CAN_ESR_RWRN_INT      16
#define BM_CAN_ESR_RWRN_INT      0x00010000

#define BF_CAN_ESR_RWRN_INT(v)   (((v) << 16) & BM_CAN_ESR_RWRN_INT)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_ESR_RWRN_INT(n, v)   BFn_CS1(CAN_ESR, n, RWRN_INT, v)
#endif

/* --- Register HW_CAN_ESR, field BIT1_ERR */

#define BP_CAN_ESR_BIT1_ERR      15
#define BM_CAN_ESR_BIT1_ERR      0x00008000

#define BF_CAN_ESR_BIT1_ERR(v)   (((v) << 15) & BM_CAN_ESR_BIT1_ERR)
/* --- Register HW_CAN_ESR, field BIT0_ERR */

#define BP_CAN_ESR_BIT0_ERR      14
#define BM_CAN_ESR_BIT0_ERR      0x00004000

#define BF_CAN_ESR_BIT0_ERR(v)   (((v) << 14) & BM_CAN_ESR_BIT0_ERR)
/* --- Register HW_CAN_ESR, field ACK_ERR */

#define BP_CAN_ESR_ACK_ERR      13
#define BM_CAN_ESR_ACK_ERR      0x00002000

#define BF_CAN_ESR_ACK_ERR(v)   (((v) << 13) & BM_CAN_ESR_ACK_ERR)
/* --- Register HW_CAN_ESR, field CRC_ERR */

#define BP_CAN_ESR_CRC_ERR      12
#define BM_CAN_ESR_CRC_ERR      0x00001000

#define BF_CAN_ESR_CRC_ERR(v)   (((v) << 12) & BM_CAN_ESR_CRC_ERR)
/* --- Register HW_CAN_ESR, field FRM_ERR */

#define BP_CAN_ESR_FRM_ERR      11
#define BM_CAN_ESR_FRM_ERR      0x00000800

#define BF_CAN_ESR_FRM_ERR(v)   (((v) << 11) & BM_CAN_ESR_FRM_ERR)
/* --- Register HW_CAN_ESR, field STF_ERR */

#define BP_CAN_ESR_STF_ERR      10
#define BM_CAN_ESR_STF_ERR      0x00000400

#define BF_CAN_ESR_STF_ERR(v)   (((v) << 10) & BM_CAN_ESR_STF_ERR)
/* --- Register HW_CAN_ESR, field TX_WRN */

#define BP_CAN_ESR_TX_WRN      9
#define BM_CAN_ESR_TX_WRN      0x00000200

#define BF_CAN_ESR_TX_WRN(v)   (((v) << 9) & BM_CAN_ESR_TX_WRN)
/* --- Register HW_CAN_ESR, field RX_WRN */

#define BP_CAN_ESR_RX_WRN      8
#define BM_CAN_ESR_RX_WRN      0x00000100

#define BF_CAN_ESR_RX_WRN(v)   (((v) << 8) & BM_CAN_ESR_RX_WRN)
/* --- Register HW_CAN_ESR, field IDLE */

#define BP_CAN_ESR_IDLE      7
#define BM_CAN_ESR_IDLE      0x00000080

#define BF_CAN_ESR_IDLE(v)   (((v) << 7) & BM_CAN_ESR_IDLE)
/* --- Register HW_CAN_ESR, field TXRX */

#define BP_CAN_ESR_TXRX      6
#define BM_CAN_ESR_TXRX      0x00000040

#define BF_CAN_ESR_TXRX(v)   (((v) << 6) & BM_CAN_ESR_TXRX)
/* --- Register HW_CAN_ESR, field FLT_CONF */

#define BP_CAN_ESR_FLT_CONF      4
#define BM_CAN_ESR_FLT_CONF      0x00000030

#define BF_CAN_ESR_FLT_CONF(v)   (((v) << 4) & BM_CAN_ESR_FLT_CONF)
/* --- Register HW_CAN_ESR, field RSVD0 */

#define BP_CAN_ESR_RSVD0      3
#define BM_CAN_ESR_RSVD0      0x00000008

#define BF_CAN_ESR_RSVD0(v)   (((v) << 3) & BM_CAN_ESR_RSVD0)
/* --- Register HW_CAN_ESR, field BOFF_INT  */

#define BP_CAN_ESR_BOFF_INT       2
#define BM_CAN_ESR_BOFF_INT       0x00000004

#define BF_CAN_ESR_BOFF_INT (v)   (((v) << 2) & BM_CAN_ESR_BOFF_INT )
#ifndef __LANGUAGE_ASM__
#define BW_CAN_ESR_BOFF_INT (n, v)   BFn_CS1(CAN_ESR, n, BOFF_INT , v)
#endif

/* --- Register HW_CAN_ESR, field ERR_INT */

#define BP_CAN_ESR_ERR_INT      1
#define BM_CAN_ESR_ERR_INT      0x00000002

#define BF_CAN_ESR_ERR_INT(v)   (((v) << 1) & BM_CAN_ESR_ERR_INT)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_ESR_ERR_INT(n, v)   BFn_CS1(CAN_ESR, n, ERR_INT, v)
#endif

/* --- Register HW_CAN_ESR, field WAK_INT */

#define BP_CAN_ESR_WAK_INT      0
#define BM_CAN_ESR_WAK_INT      0x00000001

#define BF_CAN_ESR_WAK_INT(v)   (((v) << 0) & BM_CAN_ESR_WAK_INT)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_ESR_WAK_INT(n, v)   BFn_CS1(CAN_ESR, n, WAK_INT, v)
#endif



/*
 * HW_CAN_IMASK2 - Interrupt Masks 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BUFM  : 32;
    } B;
} hw_can_imask2_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_IMASK2 register
 */
#define HW_CAN_IMASK2_ADDR(x)      (REGS_CAN_BASE(x) + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_IMASK2(x)           (*(volatile hw_can_imask2_t *) HW_CAN_IMASK2_ADDR(x))
#define HW_CAN_IMASK2_RD(x)      (HW_CAN_IMASK2(x).U)
#define HW_CAN_IMASK2_WR(x, v)     (HW_CAN_IMASK2(x).U = (v))
#define HW_CAN_IMASK2_SET(x, v)    (HW_CAN_IMASK2_WR(x, HW_CAN_IMASK2_RD(x) |  (v)))
#define HW_CAN_IMASK2_CLR(x, v)    (HW_CAN_IMASK2_WR(x, HW_CAN_IMASK2_RD(x) & ~(v)))
#define HW_CAN_IMASK2_TOG(x, v)    (HW_CAN_IMASK2_WR(x, HW_CAN_IMASK2_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_IMASK2 bitfields
 */
/* --- Register HW_CAN_IMASK2, field BUFM */

#define BP_CAN_IMASK2_BUFM      0
#define BM_CAN_IMASK2_BUFM      0xFFFFFFFF

#ifndef __LANGUAGE_ASM__
#define BF_CAN_IMASK2_BUFM(v)   ((reg32_t) v)
#else
#define BF_CAN_IMASK2_BUFM(v)   (v)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CAN_IMASK2_BUFM(n, v)   (HW_CAN_IMASK2(n).B.BUFM = (v))
#endif



/*
 * HW_CAN_IMASK1 - Interrupt Masks 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BUFM  : 32;
    } B;
} hw_can_imask1_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_IMASK1 register
 */
#define HW_CAN_IMASK1_ADDR(x)      (REGS_CAN_BASE(x) + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_IMASK1(x)           (*(volatile hw_can_imask1_t *) HW_CAN_IMASK1_ADDR(x))
#define HW_CAN_IMASK1_RD(x)      (HW_CAN_IMASK1(x).U)
#define HW_CAN_IMASK1_WR(x, v)     (HW_CAN_IMASK1(x).U = (v))
#define HW_CAN_IMASK1_SET(x, v)    (HW_CAN_IMASK1_WR(x, HW_CAN_IMASK1_RD(x) |  (v)))
#define HW_CAN_IMASK1_CLR(x, v)    (HW_CAN_IMASK1_WR(x, HW_CAN_IMASK1_RD(x) & ~(v)))
#define HW_CAN_IMASK1_TOG(x, v)    (HW_CAN_IMASK1_WR(x, HW_CAN_IMASK1_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_IMASK1 bitfields
 */
/* --- Register HW_CAN_IMASK1, field BUFM */

#define BP_CAN_IMASK1_BUFM      0
#define BM_CAN_IMASK1_BUFM      0xFFFFFFFF

#ifndef __LANGUAGE_ASM__
#define BF_CAN_IMASK1_BUFM(v)   ((reg32_t) v)
#else
#define BF_CAN_IMASK1_BUFM(v)   (v)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CAN_IMASK1_BUFM(n, v)   (HW_CAN_IMASK1(n).B.BUFM = (v))
#endif



/*
 * HW_CAN_IFLAG2 - Interrupt Flags 2 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BUFI  : 32;
    } B;
} hw_can_iflag2_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_IFLAG2 register
 */
#define HW_CAN_IFLAG2_ADDR(x)      (REGS_CAN_BASE(x) + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_IFLAG2(x)           (*(volatile hw_can_iflag2_t *) HW_CAN_IFLAG2_ADDR(x))
#define HW_CAN_IFLAG2_RD(x)      (HW_CAN_IFLAG2(x).U)
#define HW_CAN_IFLAG2_WR(x, v)     (HW_CAN_IFLAG2(x).U = (v))
#define HW_CAN_IFLAG2_SET(x, v)    (HW_CAN_IFLAG2_WR(x, HW_CAN_IFLAG2_RD(x) |  (v)))
#define HW_CAN_IFLAG2_CLR(x, v)    (HW_CAN_IFLAG2_WR(x, HW_CAN_IFLAG2_RD(x) & ~(v)))
#define HW_CAN_IFLAG2_TOG(x, v)    (HW_CAN_IFLAG2_WR(x, HW_CAN_IFLAG2_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_IFLAG2 bitfields
 */
/* --- Register HW_CAN_IFLAG2, field BUFI */

#define BP_CAN_IFLAG2_BUFI      0
#define BM_CAN_IFLAG2_BUFI      0xFFFFFFFF

#ifndef __LANGUAGE_ASM__
#define BF_CAN_IFLAG2_BUFI(v)   ((reg32_t) v)
#else
#define BF_CAN_IFLAG2_BUFI(v)   (v)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CAN_IFLAG2_BUFI(n, v)   (HW_CAN_IFLAG2(n).B.BUFI = (v))
#endif



/*
 * HW_CAN_IFLAG1 - Interrupt Flags 1 Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BUFI  : 32;
    } B;
} hw_can_iflag1_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_IFLAG1 register
 */
#define HW_CAN_IFLAG1_ADDR(x)      (REGS_CAN_BASE(x) + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_IFLAG1(x)           (*(volatile hw_can_iflag1_t *) HW_CAN_IFLAG1_ADDR(x))
#define HW_CAN_IFLAG1_RD(x)      (HW_CAN_IFLAG1(x).U)
#define HW_CAN_IFLAG1_WR(x, v)     (HW_CAN_IFLAG1(x).U = (v))
#define HW_CAN_IFLAG1_SET(x, v)    (HW_CAN_IFLAG1_WR(x, HW_CAN_IFLAG1_RD(x) |  (v)))
#define HW_CAN_IFLAG1_CLR(x, v)    (HW_CAN_IFLAG1_WR(x, HW_CAN_IFLAG1_RD(x) & ~(v)))
#define HW_CAN_IFLAG1_TOG(x, v)    (HW_CAN_IFLAG1_WR(x, HW_CAN_IFLAG1_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_IFLAG1 bitfields
 */
/* --- Register HW_CAN_IFLAG1, field BUFI */

#define BP_CAN_IFLAG1_BUFI      0
#define BM_CAN_IFLAG1_BUFI      0xFFFFFFFF

#ifndef __LANGUAGE_ASM__
#define BF_CAN_IFLAG1_BUFI(v)   ((reg32_t) v)
#else
#define BF_CAN_IFLAG1_BUFI(v)   (v)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CAN_IFLAG1_BUFI(n, v)   (HW_CAN_IFLAG1(n).B.BUFI = (v))
#endif



/*
 * HW_CAN_GFWR - Glitch Filter Width Register
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GFWR   :  8;
        unsigned RSVD0  : 24;
    } B;
} hw_can_gfwr_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_GFWR register
 */
#define HW_CAN_GFWR_ADDR(x)      (REGS_CAN_BASE(x) + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_GFWR(x)           (*(volatile hw_can_gfwr_t *) HW_CAN_GFWR_ADDR(x))
#define HW_CAN_GFWR_RD(x)      (HW_CAN_GFWR(x).U)
#define HW_CAN_GFWR_WR(x, v)     (HW_CAN_GFWR(x).U = (v))
#define HW_CAN_GFWR_SET(x, v)    (HW_CAN_GFWR_WR(x, HW_CAN_GFWR_RD(x) |  (v)))
#define HW_CAN_GFWR_CLR(x, v)    (HW_CAN_GFWR_WR(x, HW_CAN_GFWR_RD(x) & ~(v)))
#define HW_CAN_GFWR_TOG(x, v)    (HW_CAN_GFWR_WR(x, HW_CAN_GFWR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_GFWR bitfields
 */
/* --- Register HW_CAN_GFWR, field RSVD0 */

#define BP_CAN_GFWR_RSVD0      8
#define BM_CAN_GFWR_RSVD0      0xFFFFFF00

#ifndef __LANGUAGE_ASM__
#define BF_CAN_GFWR_RSVD0(v)   ((((reg32_t) v) << 8) & BM_CAN_GFWR_RSVD0)
#else
#define BF_CAN_GFWR_RSVD0(v)   (((v) << 8) & BM_CAN_GFWR_RSVD0)
#endif
/* --- Register HW_CAN_GFWR, field GFWR */

#define BP_CAN_GFWR_GFWR      0
#define BM_CAN_GFWR_GFWR      0x000000FF

#define BF_CAN_GFWR_GFWR(v)   (((v) << 0) & BM_CAN_GFWR_GFWR)
#ifndef __LANGUAGE_ASM__
#define BW_CAN_GFWR_GFWR(n, v)   (HW_CAN_GFWR(n).B.GFWR = (v))
#endif



/*
 * HW_CAN_MBn - CAN Messager Buffer Registers
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MBn  : 32;
    } B;
} hw_can_mbn_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_MBn register
 */
#define HW_CAN_MBn_ADDR(x)      (REGS_CAN_BASE(x) + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_MBn(x)           (*(volatile hw_can_mbn_t *) HW_CAN_MBn_ADDR(x))
#define HW_CAN_MBn_RD(x)      (HW_CAN_MBn(x).U)
#define HW_CAN_MBn_WR(x, v)     (HW_CAN_MBn(x).U = (v))
#define HW_CAN_MBn_SET(x, v)    (HW_CAN_MBn_WR(x, HW_CAN_MBn_RD(x) |  (v)))
#define HW_CAN_MBn_CLR(x, v)    (HW_CAN_MBn_WR(x, HW_CAN_MBn_RD(x) & ~(v)))
#define HW_CAN_MBn_TOG(x, v)    (HW_CAN_MBn_WR(x, HW_CAN_MBn_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_MBn bitfields
 */
/* --- Register HW_CAN_MBn, field MBn */

#define BP_CAN_MBn_MBn      0
#define BM_CAN_MBn_MBn      0xFFFFFFFF

#ifndef __LANGUAGE_ASM__
#define BF_CAN_MBn_MBn(v)   ((reg32_t) v)
#else
#define BF_CAN_MBn_MBn(v)   (v)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CAN_MBn_MBn(n, v)   (HW_CAN_MBn(n).B.MBn = (v))
#endif



/*
 * HW_CAN_RXIMRn - Rx Individual Mask Registers
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MI  : 32;
    } B;
} hw_can_rximrn_t;
#endif

/*
 * constants & macros for entire multi-block HW_CAN_RXIMRn register
 */
#define HW_CAN_RXIMRn_ADDR(x)      (REGS_CAN_BASE(x) + 0x880)

#ifndef __LANGUAGE_ASM__
#define HW_CAN_RXIMRn(x)           (*(volatile hw_can_rximrn_t *) HW_CAN_RXIMRn_ADDR(x))
#define HW_CAN_RXIMRn_RD(x)      (HW_CAN_RXIMRn(x).U)
#define HW_CAN_RXIMRn_WR(x, v)     (HW_CAN_RXIMRn(x).U = (v))
#define HW_CAN_RXIMRn_SET(x, v)    (HW_CAN_RXIMRn_WR(x, HW_CAN_RXIMRn_RD(x) |  (v)))
#define HW_CAN_RXIMRn_CLR(x, v)    (HW_CAN_RXIMRn_WR(x, HW_CAN_RXIMRn_RD(x) & ~(v)))
#define HW_CAN_RXIMRn_TOG(x, v)    (HW_CAN_RXIMRn_WR(x, HW_CAN_RXIMRn_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual HW_CAN_RXIMRn bitfields
 */
/* --- Register HW_CAN_RXIMRn, field MI */

#define BP_CAN_RXIMRn_MI      0
#define BM_CAN_RXIMRn_MI      0xFFFFFFFF

#ifndef __LANGUAGE_ASM__
#define BF_CAN_RXIMRn_MI(v)   ((reg32_t) v)
#else
#define BF_CAN_RXIMRn_MI(v)   (v)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_CAN_RXIMRn_MI(n, v)   (HW_CAN_RXIMRn(n).B.MI = (v))
#endif


#endif /* _CAN_H */

////////////////////////////////////////////////////////////////////////////////
