#include "GPIO.h"



void GPIO_WritePin(GPIO_TypeDef_t *GPIOx,uint16_t pinNumber,GPIO_PinState_t pinState){

if(pinState == GPIO_PIN_SET){

	GPIOx->BSRR = pinNumber;
}else{


}


}
