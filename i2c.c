/* 
 * File:   i2c.h
 * Author: Thomas Wetherill
 *
 * Created on 12 March 2025, 14:27
 */

#include "types.h"


void i2c_checkFree(void) {
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F)); // Wait until I2C bus is free
}

void i2c_start(void) {
    i2c_checkFree();
    SEN = 1;
}

void i2c_repeatStart(void) {
    i2c_checkFree();
    RSEN = 1;
}

void i2c_stop(void) {
    i2c_checkFree();
    PEN = 1;
}

void i2c_write(ushort data) {
    i2c_checkFree();
    SSPBUF = data;
}

void i2c_read(LineSensors* sensors) {
    i2c_checkFree();
    RCEN = 1;
    i2c_checkFree();
    sensors->val = SSPBUF;
    i2c_checkFree();
    ACKEN = 1;
}
