/*
 * LCD_Task.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-040
 */
#include <stdint.h>
#include "LCD.h"
#include "LCD_Cfg.h"
#include "LCD_Task.h"
#include "FreeRTOS.h"
#include "Task.h"


uint8_t *string[] = {"HELLO","WORLD"};

void LCD_init_Task()
{
    while(1)
    {
        if(LCD_INT_COMPLETE != LCD_InitState)
          {
            LCD_init();
            vTaskDelay(2);
          }
        else
        {
            vTaskSuspend(NULL);
        }
    }
}
void LCD_Print_String_Task()
{
    uint8_t index;
    while(1)
    {
        /*Flag to control when LCD prints something*/
        Write_Flag_LCD = 1;
         /*print arr of char*/
        LCD_displayChar('A');
        vTaskDelay(3);
         //for(index=0;index<sizeof(string);index++)
         //{
             //LCD_displayString(string[1],sizeof(string[1]));
             //vTaskDelay(1000);
             //LCD_sendCommand(LCD_CMD_ClearDisplayScreen_e);

         //}
    }
}





