# STM32-FreeRTOS-Dual-LED-Tasks
# STM32 FreeRTOS Dual LED Tasks

A basic FreeRTOS task scheduling project developed on the STM32 Nucleo-F401RE using native FreeRTOS APIs and register-level GPIO configuration.

## Hardware

- STM32 Nucleo-F401RE
- External LED
- Resistor (220–330 Ω)
- Breadboard
- Jumper wires

## Project Overview
<img width="738" height="1600" alt="WhatsApp Image 2026-09-12 at 12 14 30" src="https://github.com/user-attachments/assets/688e581b-52c8-41b5-a913-bb2816acc464" />


This project demonstrates how FreeRTOS can manage multiple independent tasks on an STM32 microcontroller.

Two LED tasks are created with the same priority. Each task controls one LED and uses `vTaskDelay()` to periodically turn the LED ON and OFF without blocking the other task.

## Tasks

| Task | GPIO | ON Time | OFF Time | Priority |
|------|------|---------|----------|----------|
| LED_Task1 | PA5 | 500 ms | 500 ms | 1 |
| LED_Task2 | PA6 | 1000 ms | 1000 ms | 1 |

- PA5 controls the onboard LED.
- PA6 controls an external LED connected through a resistor.

## FreeRTOS Concepts Demonstrated

- Task creation
- Task scheduling
- Task priorities
- Task delays
- Ready / Running / Blocked task states
- Preemptive scheduling
- FreeRTOS tick
- Multiple tasks running independently

## APIs Used

- `xTaskCreate()`
- `vTaskDelay()`
- `vTaskStartScheduler()`
- `pdMS_TO_TICKS()`

## STM32 Implementation

GPIO configuration is performed using STM32F4 memory-mapped registers rather than HAL GPIO APIs.

The project uses:

- RCC register for GPIOA clock enable
- GPIOA MODER for output configuration
- GPIOA BSRR for LED control

## Project Structure

```text
RTOS_01/
├── Core/
│   ├── Inc/
│   └── Src/
│       ├── main.c
│       └── freertos.c
├── Drivers/
├── RTOS_01.ioc
└── FreeRTOSConfig.h

##Result

Both LED tasks execute independently under the FreeRTOS scheduler. The onboard LED connected to PA5 toggles every 500 ms, while the external LED connected to PA6 toggles every 1000 ms.

##Learning Outcome

This project provided practical understanding of FreeRTOS task creation, scheduling, priorities, blocking through task delays, and separation of application functions into independent tasks on an STM32 microcontroller.
