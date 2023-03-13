/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-12 20:43:21                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-12 22:42:23                              *
 * @FilePath              : LED_priv.h                                       *
 ****************************************************************************/


#ifndef _LED_PRIV_
#define _LED_PRIV_

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






#endif