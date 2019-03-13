
#include "switch_task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Switch_Driver.h"
#include "led_task.h"

void Switch_Init_Task()
{
    // Enable the GPIO port that is used for the on-board LED.
    //
    while(1)
    {
        Switch_init();
        vTaskSuspend(NULL);
    }

}

void Switch_Pressed_Task()
{

}

