#include "SSD.h"
#include "Macros.h"
/************************************ App Configuration *************************************/
// segment pins config
static pin_config_t seg_config[SSD_PIN_NUM]={
    {.port=GPIOA, .pin=PIN1 }//a
   ,{.port=GPIOA, .pin=PIN2 }//b
   ,{.port=GPIOA, .pin=PIN3 }//c
   ,{.port=GPIOA, .pin=PIN4 }//d
   ,{.port=GPIOA, .pin=PIN5 }//e
   ,{.port=GPIOA, .pin=PIN6 }//f
   ,{.port=GPIOA, .pin=PIN7 }//g
   ,{.port=GPIOB, .pin=PIN0 }//dot
};  
// seven segment enable pin
static pin_config_t digit_enable[MAX_DIGIT_NUM]=
{
   {.port=GPIOB , .pin=PIN12 }//SEG_0 enable pin
  ,{.port=GPIOB , .pin=PIN13 }
  ,{.port=GPIOB , .pin=PIN14 }
  ,{.port=GPIOB , .pin=PIN15 }
};
static uint8 seg_char[MAX_CHAR_NUM]=  // dot-g-f-e-d-c-b-a
                                     // 1>>ON LED    0>>OFF LED
                     {
                     0b00111111,//0
                     0b00000110,//1
                     0b01011011,//2
                     0b01001111,//3
                     0b01100110,//4
                     0b01101101,//5
                     0b01111100,//6
                     0b00000111,//7
                     0b01111111,//8
                     0b01101111,//9
                     };
/********************************************************************************************/ 
static uint8 segment_data[MAX_DIGIT_NUM]={0}; 

void SSD_init(void)
{
   uint8 i=0;
   for(i=0;i<SSD_PIN_NUM;i++)
   {
     vGPIO_Pin_Set_Mode(seg_config[i].port,seg_config[i].pin,Output_PushPull);//set pin mode 
     vGPIO_Pin_Write(seg_config[i].port,seg_config[i].pin,!SEGMENT_ENABLE);
    
   }
   for (i=0;i<MAX_DIGIT_NUM; i++)
   {
       vGPIO_Pin_Set_Mode(digit_enable[i].port,digit_enable[i].pin,Output_PushPull);
       vGPIO_Pin_Write(digit_enable[i].port,digit_enable[i].pin,!DIGIT_ENABLE);
   }
}
/*******************************************************************************************/
void SSD_update(void)
{
  static uint8 digit_num=0;
   uint8 i , ii;
     for(i=0;i<MAX_DIGIT_NUM;i++)
     {
       vGPIO_Pin_Write(digit_enable[i].port,digit_enable[i].pin,!DIGIT_ENABLE);
     }

      vGPIO_Pin_Write(digit_enable[digit_num].port,digit_enable[digit_num].pin,DIGIT_ENABLE);

     for (ii = 0; ii < SSD_PIN_NUM ; ii++)
     {
       vGPIO_Pin_Write(seg_config[ii].port,seg_config[ii].pin,CHECK_BIT(segment_data[digit_num],ii));
     }
     if(digit_num<(MAX_DIGIT_NUM-1))
     {
       digit_num ++;
     }
     else
     {
       digit_num=0;
     }
}
/********************************************************************************************/
void SSD_print_Num(uint16 Num)
{
  uint8 i;
  for (i = 0; i < MAX_DIGIT_NUM; i++)
  {
    //SSD_set_digit(i,num%10);
  }
  
}
/********************************************************************************************/
void SSD_set_digit(digit_no_t digit , ssd_symbol_t value,ssd_dot_t dot)
{
  if(SEGMENT_ENABLE)
  {
   segment_data[digit]=seg_char[value];
  }
  else
  {
   segment_data[digit]=~seg_char[value];
  }
}
/********************************************************************************************/
//void SSD_clear_digit(digit_no_t digit , ssd_symbol_t value);
/********************************************************************************************/
///void SSD_clear(void);
