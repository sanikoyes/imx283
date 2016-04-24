################################################################################
# i.mx280A/283A led
################################################################################

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
NAME = main
BOARD ?= IMX280A
DEBUG ?= YES
BASE_ADDR ?= 0x00000000

CURRENTDIR = .
SRCDIR = $(CURRENTDIR)
OUTPUTDIR = $(CURRENTDIR)/output-target
TARGET = $(OUTPUTDIR)/$(NAME).elf
MAP = $(OUTPUTDIR)/$(NAME).map
BIN = $(OUTPUTDIR)/$(NAME).bin
# COMMONSRCDIR	= $(CURRENTDIR)/../mach-$(ARCH)
BOOT_LAYOUT	= $(SRCDIR)/link.lds

################################################################################
# compiler/linker flags
################################################################################
INCLUDE = -I../mach-mx28/includes
CFLAGS = -g -Wall $(INCLUDE) -I./ -I./src -D$(BOARD) -fdata-sections -ffunction-sections

ifeq ($(DEBUG),YES)
CFLAGS += -O0 -DDEBUG
else
CFLAGS += -O3
endif

LDFLAGS = -static -gc-sections -nostdlib -T $(BOOT_LAYOUT) -Map $(MAP)
LIBS =

ASMS = cstartup.S

SRCS = main.c

OBJS = $(ASMS:.S=.o)
OBJS += $(SRCS:.c=.o)

vpath %.o $(OUTPUTDIR)

%.o: %.S
	@mkdir -p $(OUTPUTDIR)/$(dir $@)
	$(CC) -c $(CFLAGS) -D__LANGUAGE_ASM__ -o $(OUTPUTDIR)/$@ $<

%.o: %.arm
	@mkdir -p $(OUTPUTDIR)/$(dir $@)
	$(CC) -c $(CFLAGS) -D__LANGUAGE_ASM__ -o $(OUTPUTDIR)/$@ $<

%.o: %.c
	@mkdir -p $(OUTPUTDIR)/$(dir $@)
	$(CC) -c $(CFLAGS) -o $(OUTPUTDIR)/$@ $<

#
# Make targets
#
.PHONY: build main clean
all: echo libs main
rebuild: clean all

main: $(OBJS)
	$(MAKE) link

link: $(OBJS)
	$(LD) -o $(TARGET) $(LIBS) $(LDFLAGS) $^
	$(NM) -n $(TARGET) > $(MAP).txt
	$(OBJCOPY) -O binary $(TARGET) $(BIN)

libs:
	@echo Make librarys...

clean:
	@echo Cleaning...
	$(RM) -r $(OUTPUTDIR)/*

echo:
	@echo "CURRENTDIR= $(CURRENTDIR)"
	@echo "CC= $(CC)"
	@echo "RANLIB= $(RANLIB)"
	@echo "AR= $(AR)"
	@echo "CFLAGS= $(CFLAGS)"
	@echo "LDFLAGS= $(SYSLDFLAGS)"
	@echo "LIBS= $(LIBS)"
	@echo "TARGET= $(TARGET)"
	@echo "RM= $(RM)"
