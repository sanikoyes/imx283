################################################################################
# cross compile toolchain defines
################################################################################
CROSS_COMPILE ?= arm-none-eabi-

AS = $(CROSS_COMPILE)as
CC = $(CROSS_COMPILE)gcc -std=gnu99
CPP = $(CROSS_COMPILE)cpp
LD = $(CROSS_COMPILE)ld
STRIP = $(CROSS_COMPILE)strip
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
RANLIB = $(CROSS_COMPILE)ranlib
NM = $(CROSS_COMPILE)nm
RM = rm -f

################################################################################
# build settings
################################################################################
BOARD ?= IMX280A
DEBUG ?= YES

CURRENTDIR = .
SRCDIR = $(CURRENTDIR)
OUTPUTDIR = $(CURRENTDIR)/output-target
# COMMONSRCDIR	= $(CURRENTDIR)/../mach-$(ARCH)
BOOT_LAYOUT	= $(SRCDIR)/link.lds

################################################################################
# compiler/linker flags
################################################################################
INCLUDE = -I../mach-mx28/includes -I../mach-mx28/hw
CFLAGS = -g -Wall $(INCLUDE) -I./ -I./src -D$(BOARD) -fdata-sections -ffunction-sections

ifeq ($(DEBUG),YES)
CFLAGS += -O0 -DDEBUG
else
CFLAGS += -O3
endif

LDFLAGS = -static -gc-sections -nostdlib -T $(BOOT_LAYOUT) -Map $(MAP)
LIBS =
