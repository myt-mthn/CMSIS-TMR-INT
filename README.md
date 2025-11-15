# CMSIS-TMR-INT

A bare-metal demonstration of timer-based delays and LED blinking on ARM Cortex-M3 microcontroller (STM32F103xx) using the CMSIS driver model and timer interrupt routines.

## Table of Contents

- [Introduction](#introduction)  
- [Why Use Timer Interrupts](#why-use-timer-interrupts)  
- [Features](#features)  
- [Supported Hardware](#supported-hardware)  
- [Getting Started](#getting-started)  
- [Building the Project](#building-the-project)  
- [Running & Testing](#running-&-testing)  
- [Code Structure](#code-structure)  
- [Customization](#customization)  
- [Contributing](#contributing)  
- [License](#license)  
- [Acknowledgements](#acknowledgements)

## Introduction

In embedded systems, generating accurate time delays and periodic events is fundamental — for toggling LEDs, blinking indicators, scheduling tasks, or driving periodic sensors. This project implements timer-based delay using the CMSIS (Cortex Microcontroller Software Interface Standard) layer on the ARM Cortex-M3 (STM32F103xx) family, leveraging timer interrupts to toggle an LED.

## Why Use Timer Interrupts

- Allows non-blocking delays (i.e., CPU can perform other tasks while timer runs).  
- Ensures consistent timing irrespective of code path.  
- Ideal for periodic tasks, blinking LEDs, generating PWM base timing, etc.  
- Teaches fundamentals of NVIC, timer peripheral configuration, and interrupt handling.

## Features

- Configure a general purpose timer to produce periodic interrupts.  
- Toggle onboard LED (or external LED) inside the interrupt callback.  
- Minimalistic, easy-to-understand code — suitable for learning embedded systems.  
- Example project using the CMSIS standardized API.

## Supported Hardware

- Target microcontroller: STM32F103 (ARM Cortex-M3)  
- E.g., on board such as a “Blue Pill” STM32F103C8T6.  
- Development environment: Use any toolchain supporting CMSIS + ARM GCC, e.g., STM32CubeIDE, Keil uVision, or Makefile+GCC.

## Getting Started

1. Clone or download this repository.  
2. Open the project in your IDE or import into your build system.  
3. Ensure you have the correct CMSIS headers and startup code for your STM32F103xx.  
4. Connect an LED (if not already onboard) to a GPIO pin defined in `main.c`.

## Building the Project

- Use the included `main.c` file (and others) to compile.  
- Ensure the correct device header `stm32f1xx.h` (or equivalent) is present.  
- Confirm `SystemCoreClock` is configured correctly for your board (typically 72 MHz for STM32F103).  
- Build and link appropriately to produce a `.hex` or `.bin` file.  
- Flash the resulting image to your board.

## Running & Testing

- After flashing, power the board.  
- The LED should blink at the configured interval (set inside `main.c`, e.g., toggle every 500 ms).  
- You can modify the interval or logic inside the timer-interrupt callback to experiment.  
- Use a logic analyzer or oscilloscope to verify accurate timing if needed.

## Code Structure

