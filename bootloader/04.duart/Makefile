################################################################################
# i.mx280A/283A beep
################################################################################

include ../Makefile.inc

################################################################################
# build settings
################################################################################
NAME = main
BASE_ADDR ?= 0x00000000

ASMS = ../mach-mx28/cstartup.S
SRCS = main.c \
	../mach-mx28/hw/led/led.c \
	../mach-mx28/hw/delay/delay.c \
	../mach-mx28/hw/beep/beep.c \
	../mach-mx28/hw/uart/duart.c \
	../mach-mx28/hw/sys/print.c

include ../Makefile.build
