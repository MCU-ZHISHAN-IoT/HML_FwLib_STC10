#!/usr/bin/make

# ------------------------------------------------------------------------
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2020-02-26
# Description: MCU parameters config Makefile
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : GNU Make (http://www.gnu.org/software/make/manual/make.html)
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc10.html
# Project    : HML_FwLib_STC10
# Version    : v0.4.2
# ------------------------------------------------------------------------

# Print note information
$(info $(SPACE)- Collect MCU config information)

# Configuration parameter translation
# [CLKFRE] frequency of MCU clock
ifneq ($(CLKFRE),)
    ifeq ($(shell $(ECHO) $(CLKFRE) | $(GREP) '^[[:digit:]]*$$'),)
        $(error invalid CLKFRE value)
    else
        CLOCK_FREQUENCY := $(CLKFRE)
    endif
else
    CLOCK_FREQUENCY := 11059200
endif

# [CODE] internal ROM
ifneq ($(CODE),)
    export CODE_SIZE := $(shell $(ECHO) $(CODE) | $(AWK) '{printf("%d",$$1*1024)}')
endif
# [IRAM] internal RAM
# for stc10, this value is fixed to 256
export IRAM_SIZE := 256
# [XRAM] external RAM
ifneq ($(XRAM),)
    export XRAM_SIZE := $(shell $(ECHO) $(XRAM) | $(AWK) '{printf("%d",$$1*1024)}')
endif

# [MCU] MCU model enumeration
ifneq ($(MCU),)
    mcu_model := $(shell $(ECHO) $(MCU) | $(TR) '[a-z]' '[A-Z]')
    MCU_MACRO := MCU_MODEL_$(mcu_model)
    ifeq ($(mcu_model), STC10F04)
        CODE_SIZE ?= 4096
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC10F04XE)
        CODE_SIZE ?= 4096
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC10L04)
        CODE_SIZE ?= 4096
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC10L04XE)
        CODE_SIZE ?= 4096
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC10F06)
        CODE_SIZE ?= 6144
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC10F06XE)
        CODE_SIZE ?= 6144
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC10L06)
        CODE_SIZE ?= 6144
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC10L06XE)
        CODE_SIZE ?= 6144
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC10F08)
        CODE_SIZE ?= 8192
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC10F08XE)
        CODE_SIZE ?= 8192
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC10L08)
        CODE_SIZE ?= 8192
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC10L08XE)
        CODE_SIZE ?= 8192
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC10F10)
        CODE_SIZE ?= 10240
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC10F10XE)
        CODE_SIZE ?= 10240
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC10L10)
        CODE_SIZE ?= 10240
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC10L10XE)
        CODE_SIZE ?= 10240
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC10F12)
        CODE_SIZE ?= 12288
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC10F12XE)
        CODE_SIZE ?= 12288
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC10L12)
        CODE_SIZE ?= 12288
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC10L12XE)
        CODE_SIZE ?= 12288
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC10F14X)
        CODE_SIZE ?= 14336
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC10L14X)
        CODE_SIZE ?= 14336
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), IAP10F14X)
        CODE_SIZE ?= 14336
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), IAP10L14X)
        CODE_SIZE ?= 14336
        XRAM_SIZE ?= 256
    else
        $(error unknow or unsupport MCU model $(MCU))
    endif
else
    $(error unspecify MCU model!)
endif

# Generate and export CFLAGS
#   Details:
#    --fsigned-char     Make "char" signed by default
#    -mmcs51            Generate code for the Intel MCS51 family of processors.
#                       This is the default processor target.
#    --std-sdcc99       Use ISO C99 standard with SDCC extensions
#    --opt-code-size    Optimize for code size rather than speed
#    --code-loc         Code Segment Location
#    --code-size        Code Segment size
#    --iram-size        Internal Ram size
#    --xram-size        External Ram size
#    --Werror           Treat the warnings as errors
export CFLAGS := -c -I$(INCDIR) \
-mmcs51 -D__CONF_MCU_MODEL=$(MCU_MACRO) \
-D__CONF_FRE_CLKIN=$(CLOCK_FREQUENCY)UL \
--std-sdcc99 --fsigned-char --Werror \
--opt-code-size \
--code-loc 0x0000 --code-size $(CODE_SIZE) \
--iram-size $(IRAM_SIZE) \
--xram-size $(XRAM_SIZE)

# Generate and export AFLAGS
#     -c      do not warn if the library had to be created
#     -s      act as ranlib
#     -r      replace existing or insert new file(s) into the archive
AFLAGS        := -rcs

# Print final MCU information according to all configurations
$(info [mcu-model] $(mcu_model) (code=$(CODE_SIZE)B, iram=$(IRAM_SIZE)B, xram=$(XRAM_SIZE)B))
$(info [mcu-clock] $(shell $(ECHO) $(CLOCK_FREQUENCY) | $(AWK) '{printf("%.6f",$$1/1000000)}') MHz)
