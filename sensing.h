/* 
 * File:   sensing.h
 * Author: Thomas Wetherill
 *
 * Created on 10 March 2025, 11:02
 */

#ifndef SENSING_H
#define	SENSING_H

#include <xc.h>

#include "types.h"
#include "i2c.h"

int read_adc(ushort sensor);

#endif	/* SENSING_H */

