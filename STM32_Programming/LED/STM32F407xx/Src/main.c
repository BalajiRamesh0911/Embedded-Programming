/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 * @written by	   : Balaji
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include "STM32F407xx_driver.h"
#include "STM32F407xx_gpiodriver.h"

void delay (void)

	{
		for (uint32_t i=0; i < 50000; i++);
	}

int main (void)

	{
		pGPIO_Handle_t	GPIOLed;

		GPIOLed.pGPIOx = GPIOD;


		GPIOLed.GPIO_PinConfig.GPIO_PinNumber		= 	GPIO_PIN_NO_12;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode			= 	GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed		=	GPIO_SPEED_HIGH;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType 		= 	GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPUPDControl	=	GPIO_PIN_PU;

		GPIO_PeriClockControl(GPIOD, ENABLE);
		GPIO_Init(&GPIOLed);

		while(1)

		{
					GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
					delay();
		}



	}
