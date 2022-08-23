#include "GPIO.h"

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




