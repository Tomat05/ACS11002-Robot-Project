/* 
 * File:   sensing.h
 * Author: Thomas Wetherill
 *
 * Created on 10 March 2025, 11:02
 */

#include "sensing.h"

int read_adc(ushort sensor) {
    // Set the channel to the correct sensor
    ADCON0bits.CHS = sensor;
    ADCON0bits.GO = 1;
    
    while (ADCON0bits.GO); // Do nothing for the duration of the conversion
    return ((ADRESH << 8) + ADRESL); // Concatenate returned values into one 16b number
}

void read_i2c(LineSensors* sensor) {
    i2c_start();
    i2c_write(0x7C); // Send 7b address & write to slave
    i2c_write(0x11); // Write data, select RegdataA & send to slave
    i2c_repeatStart();
    i2c_write(0x7D); // Send 7 bit address
    i2c_read(sensor);
    i2c_stop();
}