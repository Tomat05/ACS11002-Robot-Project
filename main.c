/*
 * File:   main.c
 * Author: Thomas Wetherill
 *
 * Created on 07 March 2025, 17:02
 */


#include <xc.h>
#include <stdio.h>
#include <stdbool.h>

#pragma config OSC = HS    //High speed resonator
#pragma config WDT = OFF  //Watchdog timer off
#pragma config LVP = OFF   //Low voltage programming disabled
#pragma config PWRT = ON   //Power up timer on
#define _XTAL_FREQ 10000000

#include "setup_and_shutdown.h"

void main(void) {
    
    for (;;) {
        // TODO: Main Loop
        break;
    }
    sleep();
}
