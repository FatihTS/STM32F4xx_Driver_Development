

#include "stm32f407xx.h"



static void GPIO_LedConfig();
static void GPIO_Lock();

int main(void)
{
	GPIO_LedConfig();

GPIO_LockPin(GPIOA, GPIO_PIN_0);

//GPIO_Lock();

while(1){

if(GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET){

	GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_SET);

}else{

	GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);

}



}

}


static void GPIO_LedConfig(){

	RCC_GPIOD_CLK_ENABLE();
	RCC_GPIOA_CLK_ENABLE();

GPIO_InitTypeDef_t GPIO_InitStruct = { 0 };

GPIO_InitStruct.pinNumber = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
GPIO_InitStruct.Pupd = GPIO_PUPD_NOPULL;
GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;


GPIO_Init(GPIOD, &GPIO_InitStruct);

memset(&GPIO_InitStruct,0,sizeof(GPIO_InitStruct));

GPIO_InitStruct.pinNumber = GPIO_PIN_0;
GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
GPIO_InitStruct.Pupd = GPIO_PUPD_PULLDOWN;

GPIO_Init(GPIOA, &GPIO_InitStruct);


}


static void GPIO_Lock(){


	GPIO_InitTypeDef_t GPIO_InitStruct = {0};

	GPIO_InitStruct.pinNumber = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Pupd = GPIO_PUPD_NOPULL;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

	GPIO_Init(GPIOA,&GPIO_InitStruct);

}
