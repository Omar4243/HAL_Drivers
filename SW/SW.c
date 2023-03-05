#include "SW.h"
/************************************************************* APP Configuration ********************************************************/
static sw_t SW_Config[max_sw_num] = {
    // add sw config here

{.port = GPIOA, .pin = PIN0, .sw_active_state = Low_lvl, .sw_input_config = internal_pullup, .long_pressed_mul = 20, .short_pressed_mul = 2} // SW1
,{.port = GPIOB, .pin = PIN9, .sw_active_state = Low_lvl, .sw_input_config = internal_pullup, .long_pressed_mul = 20, .short_pressed_mul = 2} // SW1
};
/****************************************************************************************************************************************/
/*privet variable*/
static uint8 counter[max_sw_num] = {0};
/*function implementation*/
void SW_init(void)
{
        uint8 i;
        for (i = 0; i < max_sw_num; i++)
        {
                if (SW_Config[SW1].sw_input_config == internal_pullup)
                {
                        vGPIO_Pin_Set_Mode(SW_Config[i].port, SW_Config[i].pin, Input_PullUp);
                }
                else if (SW_Config[SW1].sw_input_config == floating)
                {
                        vGPIO_Pin_Set_Mode(SW_Config[i].port, SW_Config[i].pin, Input_Floating);
                }
                SW_Config[i].sw_state = released;
        }
}
void SW_update(void) // call every 20 : 50 ms
{

        uint8 i;
        for (i = 0; i < max_sw_num; i++)
        {
                if (SW_Config[i].sw_active_state == Low_lvl)
                {
                        if (!u8GPIO_Pin_Read(SW_Config[i].port, SW_Config[i].pin))
                        {
                                switch (SW_Config[i].sw_state)
                                {
                                case released:
                                        SW_Config[i].sw_state = pre_pressed;
                                        break;
                                case pre_pressed:
                                        if (counter[i] == (SW_Config[i].short_pressed_mul))
                                        {
                                                SW_Config[i].sw_state = short_pressed;
                                        }
                                        else
                                        {
                                                counter[i]++;
                                        }
                                        break;
                                case short_pressed:
                                        if (counter[i] == (SW_Config[i].long_pressed_mul))
                                        {
                                                SW_Config[i].sw_state = long_pressed;
                                        }
                                        else
                                        {
                                                counter[i]++;
                                        }
                                        break;
                                case long_pressed: /*do nothing*/
                                        break;
                                case pre_released: /*do nothing*/
                                        break;
                                }
                        }
                        else
                        {
                                SW_Config[i].sw_state = released;
                                counter[i] = 0;
                        }
                }
                else if (SW_Config[i].sw_active_state == High_lvl)
                {
                        if (!u8GPIO_Pin_Read(SW_Config[i].port, SW_Config[i].pin))
                        {
                                switch (SW_Config[i].sw_state)
                                {
                                case released:
                                        SW_Config[i].sw_state = pre_pressed;
                                        break;
                                case pre_pressed:
                                        if (counter[i] == (SW_Config[i].short_pressed_mul))
                                        {
                                                SW_Config[i].sw_state = short_pressed;
                                        }
                                        else
                                        {
                                                counter[i]++;
                                        }
                                        break;
                                case short_pressed:
                                        if (counter[i] == (SW_Config[i].long_pressed_mul))
                                        {
                                                SW_Config[i].sw_state = long_pressed;
                                        }
                                        else
                                        {
                                                counter[i]++;
                                        }
                                        break;
                                case long_pressed: /*do nothing*/
                                        break;
                                case pre_released: /*do nothing*/
                                        break;
                                }
                        }
                        else
                        {
                                if(SW_Config[i].sw_state != released)
                                {
                                        SW_Config[i].sw_state = pre_released;
                                }
                                else
                                {
                                        SW_Config[i].sw_state = released;
                                }
                                
                                counter[i] = 0;
                        }
                }
        }
}
sw_state_t SW_get_state(sw_id_t id)
{
        return SW_Config[id].sw_state;
}
