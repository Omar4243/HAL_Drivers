#ifndef SW_H_
#define SW_H_
/*headers*/
#include "Std_Type.h"
#include "GPIO.h"
/*********** APP Configuration **************/
typedef enum // add sw id here
{
  SW1 = 0,
  SW2,
  max_sw_num,
} sw_id_t;
/********************************************/
/*fixed type define*/
typedef enum
{
  released = 0,
  pre_pressed,
  short_pressed, // factor * scan time
  long_pressed,  // factor * scan time
  pre_released,
} sw_state_t;

typedef enum
{
  Low_lvl = 0,
  High_lvl,
} sw_active_state_t;
typedef enum
{
  internal_pullup = 0,
  floating,
} sw_input_config_t;

typedef struct
{
  GPIOx *port;
  Pin_Num_Type pin;
  sw_active_state_t sw_active_state;
  sw_input_config_t sw_input_config;
  uint8 long_pressed_mul;
  uint8 short_pressed_mul;
  sw_state_t sw_state;
} sw_t;

/*function Prototype*/
void SW_init(void);
void SW_update(void);
sw_state_t SW_get_state(sw_id_t id);

#endif
