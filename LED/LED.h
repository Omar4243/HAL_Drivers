#ifndef LED_H_
#define LED_H_
#include "GPIO.h"
/******************* App Configuration **************************/                   
typedef enum//add LED here
{
  Green_LED=0, 
  max_led_num     
}LED_id_t;
/****************************************************************/
//LED Status
typedef enum
 {
   LED_ON=0,
   LED_OFF,
 }LED_status_t;
//LED Active Mode
typedef enum
 {
   Active_Low=0,
   Active_High,
 }LED_active_t;
//LED type
typedef struct 
{
  GPIOx *      port;
  Pin_Num_Type pin;
  LED_active_t LED_active;
  LED_status_t LED_status;
  
}LED_t;
/*function prototype*/
 void LED_Init(void);
 void LED_Update(void);
 LED_status_t LED_GetStatus(LED_id_t id);
 void LED_SetStatus(LED_id_t id ,LED_status_t status);

#endif
