/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-12 21:10:50                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-14 00:43:38                              *
 * @FilePath              : MCAL_wrp.h                                       *
 ****************************************************************************/

#ifndef _MCAL_WRP_
#define _MCAL_WRP_

/*heders include*/
#include "GPIO_int.h"
#include "EXTI_int.h"
#include "NVIC_int.h"
#include "SysTick_int.h"
#include "UART_int.h"
/*port wrapper configuration*/
#define MGPIOA  GPIOA  
#define MGPIOB  GPIOB  
#define MGPIOC  GPIOC  
#define MGPIOD  GPIOD  
#define MGPIOE  GPIOE  
#define MGPIOF  GPIOF  
#define MGPIOG  GPIOG  
#define MGPIOH  GPIOH  

/*pin wrapper configuration*/
#define MPIN0   PIN0    
#define MPIN1   PIN1    
#define MPIN2   PIN2    
#define MPIN3   PIN3    
#define MPIN4   PIN4    
#define MPIN5   PIN5    
#define MPIN6   PIN6    
#define MPIN7   PIN7    

/*GPIO Api Wrapper configuration*/
#define MCAL_GPIO_set_pin_mode     vGPIO_Pin_Set_Mode      
#define MCAL_GPIO_set_pin_level    vGPIO_Pin_Write     
#define MCAL_GPIO_get_pin_level    u8GPIO_Pin_Read 
    
#define MCAL_GPIO_toggle           GPIO_toggle_pin  //TODO:stil not implemented 


#endif





