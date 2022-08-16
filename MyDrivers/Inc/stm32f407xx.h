/*
 * stm32f407xx.h
 *
 *  Created on: Dec 1, 2021
 *      Author: fatih
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>



#define __IO volatile

#define SET_BITS(REG,BIT)         ( (REG) |=  (BIT) )
#define RESET_BITS(REG,BIT)       ( (REG) &= ~(BIT) )
#define READ_BITS(REG,BIT)        ( (REG) &    (BIT) )
#define UNUSED(x)                 (void)x

/*
 *               Memory Base Address
 *
 */

#define  FLASH_BASE_ADDR          (0x08000000UL) /*  Flash Base Address (up to 1MB)    */
#define  SRAM1_BASE_ADDR          (0x20000000UL) /*  SRAM1 Base Address   112KB        */
#define  SRAM2_BASE_ADDR          (0X2001C000UL) /*  SRAM2 Base Address 16 KB          */





/*
 *               Peripheral Base Address
 *
 */

#define  PERIPH_BASE_ADDR         (0x40000000UL)                      /*  Peripheral Base All Address   */


#define  APB1_BASE_ADDR            PERIPH_BASE_ADDR                   /*  APB1 Bus Domain Base Address   */
#define  APB2_BASE_ADDR           (PERIPH_BASE_ADDR + 0x00010000UL)   /*  APB2 Bus Domain Base Address   */
#define  AHB1_BASE_ADDR           (PERIPH_BASE_ADDR + 0x00020000UL)   /*  AHB1 Bus Domain Base Address   */
#define  AHB2_BASE_ADDR           (PERIPH_BASE_ADDR + 0x10000000UL)   /*  AHB2 Bus Domain Base Address   */




/*
 *               APB1 Peripherals Base Address
 *
 */

#define  TIM2_BASE_ADDR            (APB1_BASE_ADDR + 0x0000UL)     /*  TIM 2 Base Address     */
#define  TIM3_BASE_ADDR            (APB1_BASE_ADDR + 0x0400UL)     /*  TIM 3 Base Address     */
#define  TIM4_BASE_ADDR            (APB1_BASE_ADDR + 0x0800UL)     /*  TIM 4 Base Address     */
#define  TIM5_BASE_ADDR            (APB1_BASE_ADDR + 0x4000UL)     /*  TIM 5 Base Address     */
#define  TIM6_BASE_ADDR            (APB1_BASE_ADDR + 0x1000UL)     /*  TIM 6 Base Address     */
#define  TIM7_BASE_ADDR            (APB1_BASE_ADDR + 0x1400UL)     /*  TIM 7 Base Address     */

#define  TIM12_BASE_ADDR           (APB1_BASE_ADDR + 0x1800UL)     /*  TIM 12 Base Address    */
#define  TIM13_BASE_ADDR           (APB1_BASE_ADDR + 0x1C00UL)     /*  TIM 13 Base Address    */
#define  TIM14_BASE_ADDR           (APB1_BASE_ADDR + 0x2000UL)     /*  TIM 12 Base Address    */

#define  I2C1_BASE_ADDR            (APB1_BASE_ADDR + 0x5400UL)     /*  I2C 1 Base Address     */
#define  I2C2_BASE_ADDR            (APB1_BASE_ADDR + 0x5800UL)     /*  I2C 2 Base Address     */
#define  I2C3_BASE_ADDR            (APB1_BASE_ADDR + 0x5C00UL)     /*  I2C 3 Base Address     */

#define  USART2_BASE_ADDR          (APB1_BASE_ADDR + 0x4400UL)     /*  USART 2 Base Address   */
#define  USART3_BASE_ADDR          (APB1_BASE_ADDR + 0x4800UL)     /*  USART 3 Base Address   */
#define  UART4_BASE_ADDR           (APB1_BASE_ADDR + 0x4C00UL)     /*  UART 4 Base Address    */
#define  UART5_BASE_ADDR           (APB1_BASE_ADDR + 0x5000UL)     /*  UART 5 Base Address    */

#define  UART7_BASE_ADDR           (APB1_BASE_ADDR + 0x7800UL)     /*  UART 7 Base Address    */
#define  UART8_BASE_ADDR           (APB1_BASE_ADDR + 0x7C00UL)     /*  UART 8 Base Address    */

#define  SPI2_BASE_ADDR            (APB1_BASE_ADDR + 0x3800UL)     /*  SPI 2 Base Address     */
#define  SPI3_BASE_ADDR            (APB1_BASE_ADDR + 0x3C00UL)     /*  SPI 3 Base Address     */




/*
 *                APB2 Peripherals Base Address
 *
 */

#define TIM1_BASE_ADDR             (APB2_BASE_ADDR + 0x0000UL)      /*  TIM 1 Base Address      */
#define TIM8_BASE_ADDR             (APB2_BASE_ADDR + 0x0400UL)      /*  TIM 8 Base Address      */
#define TIM9_BASE_ADDR             (APB2_BASE_ADDR + 0x43FFUL)      /*  TIM 9 Base Address      */
#define TIM10_BASE_ADDR            (APB2_BASE_ADDR + 0x47FFUL)      /*  TIM 10 Base Address     */
#define TIM11_BASE_ADDR            (APB2_BASE_ADDR + 0x4BFFUL)      /*  TIM 11 Base Address     */

#define USART1_BASE_ADDR           (APB2_BASE_ADDR + 0x13FFUL)      /*  USART 1 Base Address   */
#define USART6_BASE_ADDR           (APB2_BASE_ADDR + 0x17FFUL)      /*  USART 6 Base Address   */

#define SPI1_BASE_ADDR             (APB2_BASE_ADDR + 0x33FFUL)      /*  SPI 1 Base Address     */
#define SPI4_BASE_ADDR             (APB2_BASE_ADDR + 0x37FFUL)      /*  SPI 4 Base Address     */
#define SPI5_BASE_ADDR             (APB2_BASE_ADDR + 0x5000UL)      /*  SPI 5 Base Address     */
#define SPI6_BASE_ADDR             (APB2_BASE_ADDR + 0x5400UL)      /*  SPI 6 Base Address     */

#define SYSCFG_BASE_ADDR           (APB2_BASE_ADDR + 0x3800UL)      /*  SYSCFG Base Address    */
#define EXTI_BASE_ADDR             (APB2_BASE_ADDR + 0x3C00UL)      /*  EXTI Base Address      */




/*
 *               AHB1 Peripherals Base Address
 *
 */

#define GPIOA_BASE_ADDR             (AHB1_BASE_ADDR + 0x0000UL)      /*  GPIOA Base Address    */
#define GPIOB_BASE_ADDR             (AHB1_BASE_ADDR + 0x0400UL)      /*  GPIOB Base Address    */
#define GPIOC_BASE_ADDR             (AHB1_BASE_ADDR + 0x0800UL)      /*  GPIOC Base Address    */
#define GPIOD_BASE_ADDR             (AHB1_BASE_ADDR + 0x0C00UL)      /*  GPIOD Base Address    */
#define GPIOE_BASE_ADDR             (AHB1_BASE_ADDR + 0x1000UL)      /*  GPIOE Base Address    */

#define RCC_BASE_ADDR               (AHB1_BASE_ADDR + 0x3800UL)      /*  RCC Base Address      */




/*
 *               Peripheral Structure Definitions
 *
 */

typedef struct{

	__IO uint32_t MODER;                   /*!< GPIO port mode register                        Address Offset = 0x0000  */
	__IO uint32_t OTYPER;                  /*!< GPIO port output type register                 Address Offset = 0x0004  */
	__IO uint32_t OSPEEDR;                 /*!< GPIO port output speed register                Address Offset = 0x0008  */
	__IO uint32_t PUPDR;                   /*!< GPIO port pull-up/pull-down register           Address Offset = 0x000C  */
	__IO uint32_t IDR;                     /*!< GPIO port input data register                  Address Offset = 0x0010  */
	__IO uint32_t ODR;                     /*!< GPIO port output data register                 Address Offset = 0x0014  */
	__IO uint32_t BSRR;                    /*!< GPIO port bit set/reset register               Address Offset = 0x0018  */
	__IO uint32_t LCKR;                    /*!< GPIO port configuration lock register          Address Offset = 0x001C  */
	__IO uint32_t AFR[2];                  /*!< GPIO alternate function low - high register    Address Offset = 0x0020  */

}GPIO_TypeDef_t;



typedef struct{

	__IO uint32_t CR;                      /*!< RCC clock control register                                      Address Offset = 0x0000  */
	__IO uint32_t PLLCFGR;                 /*!< RCC PLL configuration register                                  Address Offset = 0x0004  */
	__IO uint32_t CFGR;                    /*!< RCC clock configuration register                                Address Offset = 0x0008  */
	__IO uint32_t CIR;                     /*!< RCC clock interrupt register                                    Address Offset = 0x000C  */
	__IO uint32_t AHB1RSTR;                /*!< RCC AHB1 peripheral reset register                              Address Offset = 0x0010  */
	__IO uint32_t AHB2RSTR;                /*!< RCC AHB2 peripheral reset register                              Address Offset = 0x0014  */
	__IO uint32_t AHB3RSTR;                /*!< RCC AHB3 peripheral reset register                              Address Offset = 0x0018  */
	__IO uint32_t RESERVED0;               /*!< RESERVED AREA                                                   Address Offset = 0x001C  */
	__IO uint32_t APB1RSTR;                /*!< RCC APB1 peripheral reset register                              Address Offset = 0x0020  */
	__IO uint32_t APB2RSTR;                /*!< RCC APB2 peripheral reset register                              Address Offset = 0x0024  */
	__IO uint32_t RESERVED1[2];            /*!< RESERVED AREA                                                   Address Offset = 0x0028  */
    __IO uint32_t AHB1ENR;                 /*!< RCC AHB1 peripheral clock enable register                       Address Offset = 0x0030  */
    __IO uint32_t AHB2ENR;                 /*!< RCC AHB2 peripheral clock enable register                       Address Offset = 0x0034  */
    __IO uint32_t AHB3ENR;                 /*!< RCC AHB3 peripheral clock enable register                       Address Offset = 0x0038  */
    __IO uint32_t RESERVED2;               /*!< RESERVED AREA                                                   Address Offset = 0x003C  */
    __IO uint32_t APB1ENR;                 /*!< RCC APB1 peripheral clock enable register                       Address Offset = 0x0040  */
    __IO uint32_t APB2ENR;                 /*!< RCC APB2 peripheral clock enable register                       Address Offset = 0x0044  */
    __IO uint32_t RESERVED3[2];            /*!< RESERVED AREA                                                   Address Offset = 0x0048  */
    __IO uint32_t AHB1LPENR;               /*!< RCC AHB1 peripheral clock enable in low power mode register     Address Offset = 0x0050  */
    __IO uint32_t AHB2LPENR;               /*!< RCC AHB2 peripheral clock enable in low power mode register     Address Offset = 0x0054  */
    __IO uint32_t AHB3LPENR;               /*!< RCC AHB3 peripheral clock enable in low power mode register     Address Offset = 0x0058  */
    __IO uint32_t RESERVED4;               /*!< RESERVED AREA                                                   Address Offset = 0x005C  */
    __IO uint32_t APB1LPENR;               /*!< RCC APB1 peripheral clock enable in low power mode register     Address Offset = 0x0060  */
    __IO uint32_t APB2LPENR;               /*!< RCC APB2 peripheral clock enable in low power mode register     Address Offset = 0x0064  */
    __IO uint32_t RESERVED5[2];            /*!< RESERVED AREA                                                   Address Offset = 0x0068  */
    __IO uint32_t BDCR;                    /*!< RCC Backup domain control register                              Address Offset = 0x0070  */
    __IO uint32_t CSR;                     /*!< RCC clock control & status register                             Address Offset = 0x0074  */
    __IO uint32_t RESERVED6[2];            /*!< RESERVED AREA                                                   Address Offset = 0x0078  */
    __IO uint32_t SSCGR;                   /*!< RCC spread spectrum clock generation register                   Address Offset = 0x0080  */
    __IO uint32_t PLLI2SCFGR;              /*!< RCC PLLI2S configuration register                               Address Offset = 0x0084  */


}RCC_TypeDef_t;


#define GPIOA             					   ( (GPIO_TypeDef_t*)(GPIOA_BASE_ADDR) )
#define GPIOB             					   ( (GPIO_TypeDef_t*)(GPIOB_BASE_ADDR) )
#define GPIOC           				       ( (GPIO_TypeDef_t*)(GPIOC_BASE_ADDR) )
#define GPIOD              					   ( (GPIO_TypeDef_t*)(GPIOD_BASE_ADDR) )
#define GPIOE               				   ( (GPIO_TypeDef_t*)(GPIOE_BASE_ADDR) )

#define RCC                 				   ( (RCC_TypeDef_t*)(RCC_BASE_ADDR   ) )


/*
 *
 *    Bit Definitions
 *
 */


#define RCC_AHB1ENR_GPIOAEN_Pos                (0U)                                 // RCC AHB1ENR register GPIOAEN Bit Position
#define RCC_AHB1ENR_GPIOAEN_Msk                (0x1 << RCC_AHB1ENR_GPIOAEN_Pos)     // RCC AHB1ENR register GPIOAEN Bit Mask
#define RCC_AHB1ENR_GPIOAEN                     RCC_AHB1ENR_GPIOAEN_Msk             // RCC AHB1ENR register GPIOAEN Macro

#define RCC_AHB1ENR_GPIOBEN_Pos                (1U)                                 // RCC AHB1ENR register GPIOBEN Bit Position
#define RCC_AHB1ENR_GPIOBEN_Msk                (0x1 << RCC_AHB1ENR_GPIOBEN_Pos)     // RCC AHB1ENR register GPIOBEN Bit Mask
#define RCC_AHB1ENR_GPIOBEN                     RCC_AHB1ENR_GPIOBEN_Msk             // RCC AHB1ENR register GPIOBEN Macro

#define RCC_AHB1ENR_GPIOCEN_Pos                (2U)                                 // RCC AHB1ENR register GPIOCEN Bit Position
#define RCC_AHB1ENR_GPIOCEN_Msk                (0x1 << RCC_AHB1ENR_GPIOCEN_Pos)     // RCC AHB1ENR register GPIOCEN Bit Mask
#define RCC_AHB1ENR_GPIOCEN                     RCC_AHB1ENR_GPIOCEN_Msk             // RCC AHB1ENR register GPIOCEN Macro

#define RCC_AHB1ENR_GPIODEN_Pos                (3U)                                 // RCC AHB1ENR register GPIODEN Bit Position
#define RCC_AHB1ENR_GPIODEN_Msk                (0x1 << RCC_AHB1ENR_GPIODEN_Pos)     // RCC AHB1ENR register GPIODEN Bit Mask
#define RCC_AHB1ENR_GPIODEN                     RCC_AHB1ENR_GPIODEN_Msk             // RCC AHB1ENR register GPIODEN Macro



#include "RCC.h"

#endif /* INC_STM32F407XX_H_ */
