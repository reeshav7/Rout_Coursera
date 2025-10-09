#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material.
#
#******************************************************************************

#------------------------------------------------------------------------------
# Makefile for C1M2 Assignment
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      build		- Builds and links all source files
#      compile-all	- Compiles all source files, no linking
#      clean		- Removes all generated files
#
# Platform Overrides:
#      PLATFORM=HOST	- Builds for native host (gcc)
#      PLATFORM=MSP432  - Builds for MSP432 using ARM GCC
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST

# Architecture Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Target name
TARGET = c1m2

# Compiler and platform flags
ifeq ($(PLATFORM),HOST)
	CC = gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -DHOST
	LDFLAGS = -Wl,-Map=$(TARGET).map
	SOURCES = $(HOST_SOURCES)
	INCLUDES = -Iinclude/common
	SIZE = size
else ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
	CPPFLAGS = -DMSP432
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	SOURCES = $(MSP432_SOURCES)
	INCLUDES = -Iinclude/common -Iinclude/msp432 -Iinclude/CMSIS
	SIZE = arm-none-eabi-size
endif

# Object, dependency, preprocessed, and assembly files
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
PREPRO = $(SOURCES:.c=.i)
ASM = $(SOURCES:.c=.asm)

#------------------------------------------------------------------------------
# Build Rules
#------------------------------------------------------------------------------

.PHONY: build compile-all clean all-files

# Default build target: compile and link
build: $(TARGET).out
	@$(SIZE) $(TARGET).out
	@echo "Build complete for $(PLATFORM)"

# Link executable
$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(OBJS) $(LDFLAGS) -o $@

# Compile all object files only
compile-all: $(OBJS)
	@echo "All files compiled (no linking performed)."

# Generate all files: .o, .i, .asm
all-files: $(OBJS) $(PREPRO) $(ASM)
	@echo "All object, preprocessed, and assembly files generated."

# Pattern rules
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

%.i: %.c
	$(CC) -E $< $(CPPFLAGS) $(INCLUDES) -o $@

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

# Clean generated files
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET).out $(TARGET).map $(PREPRO) $(ASM)
	@echo "Cleanup complete."

