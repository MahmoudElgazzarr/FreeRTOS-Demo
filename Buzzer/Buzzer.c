/*
 * Buzzer.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-040
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "Buzzer.h"


void buzzer_init()
{
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_3);
}
void buzzer_on()
{
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, GPIO_PIN_3);
}

void buzzer_off()
{
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);
}
