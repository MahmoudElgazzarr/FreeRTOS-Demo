/*
 * Switch_Driver.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-040
 */


#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"

void Switch_init()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

    //
    // Check if the peripheral access is enabled.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB))
    {}
    /*Enable Port D*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    /*Wait while Peripheral ready*/
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD))
        {}
}
