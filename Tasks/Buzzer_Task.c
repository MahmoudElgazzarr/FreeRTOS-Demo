

#include <stdint.h>
#include "Buzzer_Task.h"
#include "FreeRTOS.h"
#include "Buzzer.h"

void Buzzer_Task()
{
    while(1)
    {
    buzzer_on();
    vTaskDelay(10);
    buzzer_off();
    vTaskDelay(10);
    }
}
void Buzzer_init_Task()
{
    while(1)
    {
    buzzer_init();
    vTaskSuspend(NULL);
    }
}
