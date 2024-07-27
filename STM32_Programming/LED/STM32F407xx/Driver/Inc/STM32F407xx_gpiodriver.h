/*
 * STM32F407xx_gpiodriver.h
 *
 *  Created on: Jul 27, 2024
 *      Author: balaji
 */

#ifndef INC_STM32F407XX_GPIODRIVER_H_
#define INC_STM32F407XX_GPIODRIVER_H_

#include "STM32F407xx_driver.h"

typedef struct

{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPUPDControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;

}	GPIO_PinConfig_t;


typedef struct

{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;

}	pGPIO_Handle_t;


/*
 * GPIO PIN NUMBER
 */

#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15


/*
 * GPIO PIN MODE
 */

#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3

/*
 * GPIO PIN SPEED
 */

#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPIO_SPEED_HIGH			3

/*
 * GPIO OP TYPE
 */

#define GPIO_OP_TYPE_PP		0
#define GPIO_OP_TYPE_OD		1

/*
 * GPIO PUPD CONTROL
 */

#define GPIO_NO_PUPD		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2


/*
 * GPIO FFUNCTION DEINITION
 */

void GPIO_Init (pGPIO_Handle_t *pGPIOx);

void GPIO_DeInit (GPIO_RegDef_t *pGPIOx);

void GPIO_PeriClockControl (GPIO_RegDef_t *pGPIOx, uint8_t EnOrDis);

uint8_t GPIO_ReadFromInputPin (GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

uint16_t GPIO_ReadFromInputPort (GPIO_RegDef_t *pGPIOx);

void GPIO_WriteToOutputPin (GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);

void GPIO_WriteToOutputPort (GPIO_RegDef_t *pGPIOx,  uint16_t Value);

void GPIO_ToggleOutputPin (GPIO_RegDef_t *pGPIOx,  uint8_t PinNumber);



#endif /* INC_STM32F407XX_GPIODRIVER_H_ */
