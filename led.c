/* 
 * File:   led.h
 * Author: Thomas Wetherill
 *
 * Created on 07 March 2025, 17:54
 */

#include "led.h"

void _set_leds(ushort states) {
    LATBbits.LB2 = (bool)(states & LED_LL);
    LATBbits.LB3 = (bool)(states & LED_L);
    LATBbits.LB4 = (bool)(states & LED_R);
    LATBbits.LB5 = (bool)(states & LED_RR);
}
