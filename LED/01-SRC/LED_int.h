/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-09 00:47:43                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-12 22:42:05                              *
 * @FilePath              : LED_int.h                                        *
 ****************************************************************************/

#ifndef _LED_INT_
#define _LED_INT_

/******************* App Configuration **************************/                   
typedef enum//add LED here
{
  Green_LED=0, 
  max_led_num     
}LED_id_t;
/****************************************************************/

/*function prototype*/
 void LED_init(void);
 void LED_update(void);
 LED_status_t LED_get_Status(LED_id_t id);
 void LED_set_status(LED_id_t id ,LED_status_t status);

#endif
