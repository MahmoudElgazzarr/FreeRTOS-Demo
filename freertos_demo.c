

#include <Buzzer_Task.h>
#include <led_task.h>
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "switch_task.h"
#include "LCD_Task.h"
#include "FreeRTOS.h"
#include "Task.h"

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}

#endif

void
vApplicationStackOverflowHook(xTaskHandle *pxTask, char *pcTaskName)
{
    //
    // This function can not return, so loop forever.  Interrupts are disabled
    // on entry to this function, so no processor interrupts will interrupt
    // this loop.
    //
    while(1)
    {
    }
}

//*****************************************************************************
//
// Initialize FreeRTOS and start the initial set of tasks.
//
//*****************************************************************************
int main(void)
{
    //
    // Set the clocking to run at 50 MHz from the PLL.
    //
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |
                       SYSCTL_OSC_MAIN);

    /*Create Init Task For Led*/
    xTaskCreate(LEDS_Task_init, (const portCHAR *)"LED_Init", 128, NULL, 15 , NULL);
    /*Create Init Task for Buzzer*/
    xTaskCreate(Buzzer_init_Task, (const portCHAR *)"Buzzer_Init", 128, NULL, 14 , NULL);
    /*Create Init Task for Switch*/
    xTaskCreate(Switch_Init_Task, (const portCHAR *)"Switch_Init", 128, NULL, 13 , NULL);
    /*Create Init Task for Switch*/
    xTaskCreate(LCD_init_Task, (const portCHAR *)"LCD_Init", 128, NULL, 12 , NULL);

    /*add Task 1 for led1*/
    xTaskCreate(LED1_Blink, (const portCHAR *)"LED1", 50, NULL, 3 , NULL);
    /*add Task 2 for led2*/
    xTaskCreate(LED2_Blink, (const portCHAR *)"LED2", 50, NULL, 4 , NULL);
    /*add Task 3 for led3*/
    xTaskCreate(LED3_Blink, (const portCHAR *)"LED3", 50, NULL, 5 , NULL);
    /*add Task Four For Buzzer*/
    xTaskCreate(Buzzer_Task, (const portCHAR *)"Buzzer", 50, NULL, 6 , NULL);
    /*add Task For LCD To Print Random String*/
    xTaskCreate(LCD_Print_String_Task, (const portCHAR *)"LCD_Print", 50, NULL, 6 , NULL);

    //
    // Start the scheduler.  This should not return.
    //
    vTaskStartScheduler();

    //
    // In case the scheduler returns for some reason, print an error and loop
    // forever.
    //

    while(1)
    {
    }
}
