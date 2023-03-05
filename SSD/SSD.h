#ifndef SSD_H_
#define SSD_H_
#include "Std_Type.h"
#include "gpio.h"
#define SSD_PIN_NUM (8U) // 7seg + dot
/************************ App Configuration *****************************/
#define DIGIT_ENABLE   (1U) //one digit enable 
#define SEGMENT_ENABLE (0U) //segment active pin
typedef enum
{
  SEG0=0,
  SEG1,
  SEG2,
  SEG3,
  MAX_DIGIT_NUM
}digit_no_t;
typedef enum 
{            
  _0_=0,
  _1_,
  _2_,
  _3_,
  _4_,
  _5_,
  _6_,
  _7_,
  _8_,
  _9_,
  MAX_CHAR_NUM
}ssd_symbol_t;
/***********************************************************************/
typedef enum
{
 dot_EN,
 dot_DS,
}ssd_dot_t;
typedef struct 
{
  GPIOx * port;
  Pin_Num_Type pin;
}pin_config_t;

void SSD_init(void);
void SSD_update(void);
void SSD_set_digit(digit_no_t digit , ssd_symbol_t value ,ssd_dot_t dot);
//void SSD_clear_digit(digit_no_t digit);
//void SSD_clear(void);

#endif
