/* 
 * File:   led.h
 * Author: Thomas Wetherill
 *
 * Created on 07 March 2025, 17:54
 */

#ifndef LED_H
#define	LED_H

#include <stdbool.h>

#include "types.h"

// LEDs as viewed from the LHS of the robot
#define LED_LL 0b1000
#define LED_L 0b0100
#define LED_R 0b0010
#define LED_RR 0b0001

void _set_leds(ushort leds);

// Allow us to set the LEDs using a single value rather than having to use 4x the memory
// while still setting them as if we were using four separate values
#define set_leds(ll, lr, rl, rr) (_set_leds( \
    ((bool)ll << 3) | \
    ((bool)lr << 2) | \
    ((bool)rl << 1) | \
    (bool)rr))

#endif
#endif	/* LED_H */

