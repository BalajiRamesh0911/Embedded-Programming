/*
 * STM32F407xx_gpiodriver.c
 *
 *  Created on: Jul 27, 2024
 *      Author: balaji
 */

#include "STM32F407xx_gpiodriver.h"

/********************************************************************************************
 * FUNCTION		-		GPIO_PeriClockControl
 * BRIEF		-		THIS FUNCTION ENABLES OR DISABLES THE CLOCK FOR THE GIVEN GPIO PORT
 * PARAMETER[1] -		BASE ADDRESS OF GPIO PERIPHERAL
 * PARAMETER[2] -		ENABLE OR DISABLE MACROS
 * RETURN VALUE - 		NONE
 *******************************************************************************************/
void GPIO_PeriClockControl (GPIO_RegDef_t *pGPIOx, uint8_t EnOrDis)
{
	if(EnOrDis == ENABLE)

	{
		if(pGPIOx == GPIOA)

		{
			GPIOA_PCLK_EN();
		}

		else if (pGPIOx == GPIOB)

		{
			GPIOB_PCLK_EN();
		}

		else if (pGPIOx == GPIOC)

				{
					GPIOC_PCLK_EN();
				}

		else if (pGPIOx == GPIOD)

				{
					GPIOD_PCLK_EN();
				}

		else if (pGPIOx == GPIOE)

				{
					GPIOE_PCLK_EN();
				}

		else if (pGPIOx == GPIOF)

				{
					GPIOF_PCLK_EN();
				}

		else if (pGPIOx == GPIOG)

				{
					GPIOG_PCLK_EN();
				}

		else if (pGPIOx == GPIOH)

				{
					GPIOH_PCLK_EN();
				}

		else if (pGPIOx == GPIOI)

				{
					GPIOI_PCLK_EN();
				}
	}

	else

	{
		if(pGPIOx == GPIOA)

		{
			GPIOA_PCLK_DI();
		}

		else if (pGPIOx == GPIOB)

		{
			GPIOB_PCLK_DI();
		}

		else if (pGPIOx == GPIOC)

				{
					GPIOC_PCLK_DI();
				}

		else if (pGPIOx == GPIOD)

				{
					GPIOD_PCLK_DI();
				}

		else if (pGPIOx == GPIOE)

				{
					GPIOE_PCLK_DI();
				}

		else if (pGPIOx == GPIOF)

				{
					GPIOF_PCLK_DI();
				}

		else if (pGPIOx == GPIOG)

				{
					GPIOG_PCLK_DI();
				}

		else if (pGPIOx == GPIOH)

				{
					GPIOH_PCLK_DI();
				}

		else if (pGPIOx == GPIOI)

				{
					GPIOI_PCLK_DI();
				}
	}
}

/********************************************************************************************
 * FUNCTION		-		GPIO_Init
 * BRIEF		-		THIS FUNCTION INITIALIZES THE GIVEN GPIO PORT
 * PARAMETER[1] -		pGPIO_Handle_t *pGPIOx
 * PARAMETER[2] -		NIL
 * PARAMETER[3] -		NIL
 * RETURN VALUE - 		NONE
 *******************************************************************************************/
void GPIO_Init (pGPIO_Handle_t *pGPIOHandle)

{
	uint32_t temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->MODER |= temp;

	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPUPDControl << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->ODR &= ~(0x3 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->ODR |= temp;

	uint8_t temp1, temp2;
	temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
	temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
	pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4*temp2));
	pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4*temp2));

}

/********************************************************************************************
 * FUNCTION		-		GPIO_DeInit
 * BRIEF		-		THIS FUNCTION DE-INITIALIZES THE GIVEN GPIO PORT
 * PARAMETER[1] -		pGPIO_Handle_t *pGPIOx
 * PARAMETER[2] -		NIL
 * PARAMETER[3] -		NIL
 * RETURN VALUE - 		NONE
 *******************************************************************************************/
void GPIO_DeInit (GPIO_RegDef_t *pGPIOx)

{
	if(pGPIOx == GPIOA)

	{
		GPIOA_RESET();
	}

	else if (pGPIOx == GPIOB)

	{
		GPIOB_RESET();
	}
	else if (pGPIOx == GPIOC)

		{
			GPIOC_RESET();
		}
	else if (pGPIOx == GPIOD)

		{
			GPIOD_RESET();
		}
	else if (pGPIOx == GPIOE)

		{
			GPIOE_RESET();
		}
	else if (pGPIOx == GPIOF)

		{
			GPIOB_RESET();
		}
	else if (pGPIOx == GPIOG)

		{
			GPIOG_RESET();
		}
	else if (pGPIOx == GPIOH)

		{
			GPIOH_RESET();
		}
	else if (pGPIOx == GPIOI)

		{
			GPIOI_RESET();
		}
}

/********************************************************************************************
 * FUNCTION		-		GPIO_WriteToOutputPin
 * BRIEF		-		THIS FUNCTION WRITES TO THE GIVEN GPIO OUTPUT PIN
 * PARAMETER[1] -		GPIO_RegDef_t *pGPIOx
 * PARAMETER[2] -		uint8_t PinNumber
 * PARAMETER[3] -		uint8_t Value
 * RETURN VALUE - 		NONE
 *******************************************************************************************/
void GPIO_WriteToOutputPin (GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)

{
	if (Value == 1)

	{
		pGPIOx->ODR |= ( 1 << PinNumber);

	}

	else

	{
		pGPIOx->ODR &= ~( 1 << PinNumber);
	}
}

/********************************************************************************************
 * FUNCTION		-		GPIO_WriteToOutputPort
 * BRIEF		-		THIS FUNCTION 	WRITES TO THE GIVEN GPIO OUTPUT PORT
 * PARAMETER[1] -		GPIO_RegDef_t *pGPIOx
 * PARAMETER[2] -		uint16_t Value
 * PARAMETER[3] -		NIL
 * RETURN VALUE - 		NONE
 *******************************************************************************************/
void GPIO_WriteToOutputPort (GPIO_RegDef_t *pGPIOx,  uint16_t Value)

{
	pGPIOx->ODR = Value;
}


/********************************************************************************************
 * FUNCTION		-		GPIO_ToggleOutputPin
 * BRIEF		-		THIS FUNCTION TOGGLES THE GIVEN OUTPUT PIN
 * PARAMETER[1] -		GPIO_RegDef_t *pGPIOx
 * PARAMETER[2] -		uint8_t PinNumber
 * PARAMETER[3] -		NIL
 * RETURN VALUE - 		NONE
 *******************************************************************************************/
void GPIO_ToggleOutputPin (GPIO_RegDef_t *pGPIOx,  uint8_t PinNumber)

{
	pGPIOx->ODR ^= ( 1 << PinNumber);
}

