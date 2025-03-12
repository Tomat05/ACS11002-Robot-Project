/* 
 * File:   i2c.h
 * Author: Thomas Wetherill
 *
 * Created on 12 March 2025, 14:27
 */

#ifndef I2C_H
#define	I2C_H

#include <xc.h>

#include "types.h"

void i2c_checkFree(void);
void i2c_start(void);
void i2c_repeatStart(void);
void i2c_stop(void);
void i2c_write(ushort data);
void i2c_read(LineSensors* where);

#endif	/* I2C_H */

