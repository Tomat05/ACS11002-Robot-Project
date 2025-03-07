/* 
 * File:   setup_and_shutdown.c
 * Author: Thomas Wetherill
 *
 * Created on 07 March 2025, 17:03
 */

#include "setup_and_shutdown.h"

void setup_io(void) {
    // Set I/O
    TRISA = 0b00000000;
    TRISB = 0b00000000;
    TRISC = 0b00000000;
    
    // Clear the I/O registers in case there are left-over values from the last run
    // which seems to happen sometimes without this
    LATA = 0;
    LATB = 0;
    LATC = 0;
    
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
}

void setup_pwm(void) {
    PR2 = 255; // Set period of PW
    T2CON = 0b00000111; // Timer 2 on, Prescaler = 1
    
    CCP1CON = 0x0c;
    CCP2CON = 0x0c;
}

void setup_adc(void) {
    ADCON2bits.ADCS = 0b010; // Set conversion clock
    ADCON2bits.ADFM = 1;
    ADCON1 = 0b00001101; // Set ref voltage & set AN0, AN1 to A/D
    ADCON0bits.ADON = 1; // Turn on ADC
}

void sleep(void) {
    // Turn off ADC just in case as it's capable of waking the PIC via an interrupt
    ADCON0bits.ADON = 0;

    /*
     * The SLEEP instruction essentially halts all execution until a reset or one of a few
     * criteria are met (see specsheet). For our purposes it's functionally just a  convenient
     * way to stop the programme restarting by the PC looping back around to the start of the
     * memory, that has the added bonus of drawing less power than an infinite loop.
    */ 
#asm
    SLEEP; // Send the little PIC to its comfy little bed after its hard day's work
#endasm
}
