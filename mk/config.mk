#!/usr/bin/make

# ------------------------------------------------------------------------
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2020-02-26
# Description: config Makefile
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : GNU Make (http://www.gnu.org/software/make/manual/make.html)
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc10.html
# Project    : HML_FwLib_STC10
# Version    : v0.4.2
# ------------------------------------------------------------------------

# @Note: Specify value of config variable via command line has higher priority

# Options for print format
#  [VERBOSE] Print control option, when its value is "1", Makefile will print
#   more details, or it will only print brief
VERBOSE   ?= 0

# Options for MCU configurations
#  [MCU] MCU model option, user can get model support list via reading Makefile.mcu.
#   This parameters is case-insensitive.
MCU       ?= stc10f04xe
#  [CLKFRE] Specify frequency of MCU clock, the unit is Hz.
CLKFRE    ?= 11059200
#  [CODE] Specify total size of ROM(external+ on-chip) during compilation
#    manually (unit: KB)
#  [XRAM] Specify total size of external RAM during compilation manually (unit: KB)
CODE      ?=
XRAM      ?=

# Options for build target
#  [EXE_C] Specify user source file or Makefile will fill it with "test.c".
#    It's noticed that once use this option to compile specified .c file,
#    user should add this option when do all targets related to build operation,
#    such as clean and rebuild.
EXE_C     ?= usr/test.c

# Options for number of parallel build jobs
# [JOBS] Specify number of parallel build jobs, this variable only works
#    during run <rebuild> target
JOBS      ?= $(shell $(NPROC))

