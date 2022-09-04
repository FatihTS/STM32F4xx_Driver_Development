#include "GPIO.h"

/**
 *
 *
 * @brief GPIO_Init, Configures the port and pin
 *
 * @param GPIOx = GPIO Port Base Address
 *
 * @param GPIO_InitTypeDef_t = User Config structures
 *
 *
 * @retval Void
 */

void GPIO_Init(GPIO_TypeDef_t* GPIOx,GPIO_InitTypeDef_t* GPIO_ConfigStruct){

	uint32_t position;
	uint32_t fakePosition = 0;
	uint32_t lastPosition = 0;

	for(position = 0;position <16;position++){


		fakePosition = (0x1U << position);
		lastPosition = (uint32_t)(GPIO_ConfigStruct->pinNumber) & fakePosition;

		if(fakePosition == lastPosition){

			/* MODE CONFIG */
			uint32_t tempValue = GPIOx->MODER;
			tempValue &= ~(0x3U << (position * 2));
			tempValue |= ((GPIO_ConfigStruct->Mode) << (position * 2));

			GPIOx->MODER = tempValue;

			if(GPIO_ConfigStruct->Mode == GPIO_MODE_OUTPUT || GPIO_ConfigStruct->Mode == GPIO_MODE_AF){


			/* OUPUT Type CONFIG */
			 tempValue = GPIOx->OTYPER;
			tempValue &= ~(0x1U << position);
			tempValue |= ((GPIO_ConfigStruct->Otype) << position);
			GPIOx->OTYPER = tempValue;


			/* OUTPUT SPEED CONFIG */
			 tempValue = GPIOx->OSPEEDR;
			tempValue &= ~(0x3U << (position * 2));
			tempValue |= ((GPIO_ConfigStruct->Speed) << (position * 2 ));
			GPIOx->OSPEEDR = tempValue;

			}


		/* Push Pull CONFIG */
			 tempValue = GPIOx->PUPDR;
			tempValue &= ~(0x3U << (position * 2 ));
			tempValue |= ((GPIO_ConfigStruct->Pupd) << (position * 2));
			GPIOx->PUPDR = tempValue;



		}

	}
}


/**
 *
 *
 * @brief GPIO_Write_Pin, makes pin High or Low
 *
 * @param GPIOx = GPIO Port Base Address
 *
 * @param pinNumber = GPIO Pin Numbers 0 - 15
 *
 * @param pinState,GPIO_PIN_SET or GPIO_PIN_RESET
 *
 * @retval Void
 */

void GPIO_WritePin(GPIO_TypeDef_t *GPIOx,uint16_t pinNumber,GPIO_PinState_t pinState){

if(pinState == GPIO_PIN_SET){

	GPIOx->BSRR = pinNumber;
}else{

GPIOx->BSRR = (pinNumber << 16U);
}

}


/**
 *
 *
 * @brief GPIO_ReadPin, reads the pin of GPIOx Port
 *
 * @param GPIOx = GPIO Port Base Address
 *
 * @param pinNumber = GPIO Pin Numbers 0 - 15
 *
 * @retval GPIO_PinState_t
 */

GPIO_PinState_t GPIO_ReadPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber){


	GPIO_PinState_t bitStatus = GPIO_PIN_RESET;

	if((GPIOx->IDR & pinNumber) != GPIO_PIN_RESET){

	bitStatus = GPIO_PIN_SET;

	}
	return bitStatus;
}



/**
 *
 *
 * @brief GPIO_LockPin, Locks the pin of GPIOx Port
 *
 * @param GPIOx = GPIO Port Base Address
 *
 * @param pinNumber = GPIO Pin Numbers 0 - 15
 *
 * @retval Void
 */

void GPIO_LockPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber){

     uint32_t tempValue = (0x1U << 16U) | pinNumber;

	GPIOx->LCKR = tempValue;                        	   // 	LCKR[16] = ‘1’ 	 		LCKR[DATA]
	GPIOx->LCKR = pinNumber;							   // 	LCKR[16] = ‘0’ 			LCKR[DATA]
	GPIOx->LCKR = tempValue;							   // 	LCKR[16] = ‘1’ 			LCKR[DATA]
	tempValue = GPIOx->LCKR;                               //   Read Lock register

}




