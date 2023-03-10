/*headers*/
#include "LED.h"
#include "Std_Type.h"
/***************************** App Configuration **********************************/
static LED_t LED_config[max_led_num] = { // add led config here
    {.port = GPIOC, .pin = PIN13, .LED_active = Active_Low, .LED_status=LED_OFF},
    };
/*********************************************************************************/
/*function implementation*/
void LED_Init(void)
{
  uint8 i;
  for (i = 0; i < max_led_num; i++)
  {
    if (LED_config[i].LED_active == Active_High)
    {
      vGPIO_Pin_Set_Mode(LED_config[i].port, LED_config[i].pin, Output_PushPull);
      vGPIO_Pin_Write(LED_config[i].port, LED_config[i].pin, Low);
    }
    else if (LED_config[i].LED_active == Active_Low)
    {
      vGPIO_Pin_Set_Mode(LED_config[i].port, LED_config[i].pin, Output_PushPull);
      vGPIO_Pin_Write(LED_config[i].port, LED_config[i].pin, High);
    }
  }
}

void LED_Update(void)
{
  uint8 i;
  for (i = 0; i < max_led_num; i++)
  {
    if (LED_config[i].LED_status == LED_ON)
    {
      if (LED_config[i].LED_active == Active_High)
      {
        vGPIO_Pin_Write(LED_config[i].port, LED_config[i].pin, High);
      }
      else if (LED_config[i].LED_active == Active_Low)
      {
        vGPIO_Pin_Write(LED_config[i].port, LED_config[i].pin, Low);
      }
    }
    else if (LED_config[i].LED_status == LED_OFF)
    {
      if (LED_config[i].LED_active == Active_High)
      {
        vGPIO_Pin_Write(LED_config[i].port, LED_config[i].pin, Low);
      }
      else if (LED_config[i].LED_active == Active_Low)
      {
        vGPIO_Pin_Write(LED_config[i].port, LED_config[i].pin, High);
      }
    }
  }
}
LED_status_t LED_GetStatus(LED_id_t id)
{
  return LED_config[id].LED_status;
}
void LED_SetStatus(LED_id_t id, LED_status_t status)
{
  LED_config[id].LED_status = status;
}
