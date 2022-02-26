# ------------------------------------------------------------------------
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2022-01-16
# Description: compile parametes define
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : CMake
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc10.html
# Project    : HML_FwLib_STC10
# Version    : v0.0.2
# ------------------------------------------------------------------------

# Init variables
set(MCU_MODEL "")
set(CODE_SIZE 0)
set(XRAM_SIZE 0)

# [CLKFRE] frequency of MCU clock
if(CLKFRE MATCHES "^[0-9]+$")
    set(CLOCK_FREQUENCY ${CLKFRE})
else()
    message(FATAL_ERROR "invalid CLKFRE value")
endif()

# [MCU] MCU model
#   Default value of CODE and XRAM is ruled by MCU model. However, if user
#   specify them manually, value of related variables will be overridden.
if(DEFINED MCU)
    string(TOUPPER ${MCU} MCU_MODEL)
    if(${MCU_MODEL} STREQUAL STC10F04)
        set(CODE_SIZE 4096)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC10F04XE)
        set(CODE_SIZE 4096)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC10L04)
        set(CODE_SIZE 4096)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC10L04XE)
        set(CODE_SIZE 4096)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC10F06)
        set(CODE_SIZE 6144)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC10F06XE)
        set(CODE_SIZE 6144)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC10L06)
        set(CODE_SIZE 6144)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC10L06XE)
        set(CODE_SIZE 6144)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC10F08)
        set(CODE_SIZE 8192)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC10F08XE)
        set(CODE_SIZE 8192)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC10L08)
        set(CODE_SIZE 8192)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC10L08XE)
        set(CODE_SIZE 8192)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC10F10)
        set(CODE_SIZE 10240)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC10F10XE)
        set(CODE_SIZE 10240)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC10L10)
        set(CODE_SIZE 10240)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC10L10XE)
        set(CODE_SIZE 10240)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC10F12)
        set(CODE_SIZE 12288)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC10F12XE)
        set(CODE_SIZE 12288)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC10L12)
        set(CODE_SIZE 12288)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC10L12XE)
        set(CODE_SIZE 12288)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC10F14X)
        set(CODE_SIZE 14336)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC10L14X)
        set(CODE_SIZE 14336)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL IAP10F14X)
        set(CODE_SIZE 14336)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL IAP10L14X)
        set(CODE_SIZE 14336)
        set(XRAM_SIZE 256)
    else()
        message(FATAL_ERROR "unknow MCU model: ${MCU}")
    endif()
else()
    message(FATAL_ERROR "user must specify MCU model")
endif()

# [CODE] internal ROM
if(DEFINED CODE)
    math(EXPR CODE_SIZE "${CODE} * 1024")
endif()

# [IRAM] internal RAM
# for stc10, this value is fixed to 256
set(IRAM_SIZE 256)

# [XRAM] external RAM
if(DEFINED XRAM)
    math(EXPR XRAM_SIZE "${XRAM} * 1024")
endif()

# Compile parameters define
add_compile_options(
   --std-sdcc99
   --fsigned-char
   --opt-code-size
   "SHELL: --code-loc 0x0000 --code-size ${CODE_SIZE}"
   "SHELL: --iram-size ${IRAM_SIZE}"
   "SHELL: --xram-size ${XRAM_SIZE}"
)
add_definitions(
    -D__CONF_FRE_CLKIN=${CLOCK_FREQUENCY}UL
    -D__CONF_MCU_MODEL=MCU_MODEL_${MCU_MODEL}
)

# Print config information
message("model : ${MCU_MODEL}")
message("memory: code=${CODE_SIZE}B, iram=${IRAM_SIZE}B, xram=${XRAM_SIZE}B")
message("clock : ${CLOCK_FREQUENCY}Hz")
