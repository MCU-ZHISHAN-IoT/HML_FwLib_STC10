# HML_FwLib_STC10
[![Jenkins](https://img.shields.io/jenkins/build?jobUrl=http%3A%2F%2Fjenkins.zhishan-iot.tk%3A12463%2Fjob%2FHML_FwLib_STC10)](http://jenkins.zhishan-iot.tk:12463/job/HML_FwLib_STC10/)
[![GitHub repo size](https://img.shields.io/github/repo-size/MCU-ZHISHAN-IoT/HML_FwLib_STC10)](https://github.com/MCU-ZHISHAN-IoT/HML_FwLib_STC10)
[![GitHub](https://img.shields.io/github/license/MCU-ZHISHAN-IoT/HML_FwLib_STC10)](https://github.com/MCU-ZHISHAN-IoT/HML_FwLib_STC10/blob/master/LICENSE)
[![GitHub tag (latest by date)](https://img.shields.io/github/v/tag/MCU-ZHISHAN-IoT/HML_FwLib_STC10?color=26a69a)](https://github.com/MCU-ZHISHAN-IoT/HML_FwLib_STC10/tags)

## What is HML_FwLib_STC10
HML_FwLib_STC10 is a member component of HML firmware library, **providing a group of interface functions for users to operate on-chip resource of STC10 MCUs**, including GPIO, IAP, timer, UART, external interrupt, power management and watchdog. The STC10 MCU is a kind of Intel MCS-51 based MCU which released by [STC Micro](http://www.stcmcu.com/)(*宏晶*). This series MCU have more on-chip resource and higher running speed. There is a document record difference STC10 & MCS-51 under doc directory.

We intend to provide a lite and easy-use firmware library that can help future developers to complete projects based on STC10 MCUs more easily and quickly. All source codes are written in C language and for [SDCC compiler](http://sdcc.sourceforge.net/), i.e., it can only be compiled by SDCC. This choice is motivated by the fact that SDCC is free and highly efficient, while there are very few examples of application about SDCC on the Internet. We hope that, as one of the early attempts to develop MCU projects using SDCC, this work will make SDCC become more popular among MCU developers.<br>

Please visit [detail page](https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc10.html) for more information to get started it!

## Feature
+ :dart:Based on [SDCC compiler](http://sdcc.sourceforge.net/).
+ Cover all on-chip resource of STC10 series MCUs.
+ Open all source code on [Github](https://github.com) and licensed under the [WTFPL2](https://wtfpl2.com/).
+ Readable code and provide examples to help you get started it.

## What's working
Here is a list of the all on-chip peripheral drivers and examples that need to be ported.

| Peripheral | Description | Status |
| --- | --- | --- |
| extended bus | Intel 8080 bus receiver/transmitter | supported |
| EXTI | extern interrupt | supported |
| GPIO | I/O peripheral | supported  |
| IAP | in application programming | supported |
| PWR | power management | supported |
| RCC | reset & clock control | supported |
| TIM | timer | supported |
| UART | universal asynchronous receiver/transmitter | supported |
| WDT | watchdog | supported |

## Config
There are several parameters need to be configured by user manually.
### \_\_CONF\_COMPILE\_xxx (for conditional compilation)
In order to ensure the projects based on HML_FwLib_STC10 can be downloaded into the limited on-chip flash space of STC10 MCUs, the developers can modify the macro definition named `__CONF_COMPILE_xxx` in *conf.h* to specify which piece of codewill take part in compilation, then it will reduce size of final .hex file. If user only use GPIO module, then user just need to enable `__CONF_COMPILE_GPIO` macro in *conf.h*. Some macros for conditional compilation rely on others. For example, before you define the macro definition `__CONF_COMPILE_RCC`, the macro `__CONF_COMPILE_UTIL` should be defined, otherwise the compilation would be failed.
### \_\_CONF\_FRE\_CLKIN
The macro mark frequency of clock source, including extern crystal oscillator or internal RC oscillating circuit, and it's defined in *hml/conf.h*.
### \_\_CONF\_HML\_POW
Enable function pow() which provided by HML. SDCC builtin library doesn't have this function.
### \_\_CONF\_MCU\_MODEL
The macro mark the model of target MCU and is defined in *hml/conf.h*.

## Building
We provide two kinds of build system support:
* cmake
* gmake

### cmake
Run this command for initialization. Add option `-GNinja` if you expect to build project via Ninja.
```
$ cmake -S . -B build
```
Run this command for building project. Add option `--clean-first` if you want to execute clean operation before building.
```
$ cmake --build build -j$(nproc)
```
You can execute command `cmake --build build -t usage` for usage. If you want to adjust build details, please modify `cmake/config.cmake`.
### gmake
Execute this command for building HML_FwLib_STC10 with GNU Make.
```
$ make -j$(nproc)
```
You can execute command `make help` for usage. If you want to adjust build details, please modify `mk/config.mk`.

## Contributing
Welcome suggestions and contribution from you! You can fork it or contact us via *[mcu@zhishan-iot.tk](mailto:mcu@zhishan-iot.tk)*.

## License
HML_FwLib_STC10 is licensed under the [WTFPL2](https://wtfpl2.com/).

## Team
|member        | role              |e-mail                        |
|--------------|-------------------|------------------------------|
| Amy Chung    | Testing           |[zhongliguo@zhishan-iot.tk](mailto:zhongliguo@zhishan-iot.tk) |
| Jiabin Hsu   | MCU developer     |[zsiothsu@zhishan-iot.tk](mailto:zsiothsu@zhishan-iot.tk) |
| Weilun Fong  | **Director**      |[wlf@zhishan-iot.tk](mailto:wlf@zhishan-iot.tk) |
