/* 
 * File:   setup_and_shutdown.h
 * Author: Thomas Wetherill
 *
 * Created on 07 March 2025, 17:03
 */

#ifndef SETUP_AND_SHUTDOWN_H
#define	SETUP_AND_SHUTDOWN_H

#include <xc.h>

void setup_io(void);
void setup_pwm(void);
void setup_adc(void);
void setup_i2c(void);
void sleep(void);

#endif	/* SETUP_AND_SHUTDOWN_H */

