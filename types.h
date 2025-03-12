/* 
 * File:   types.h
 * Author: Thomas Wetherill
 *
 * Created on 07 March 2025, 17:07
 */

#ifndef TYPES_H
#define	TYPES_H

// Alias some types so they are more succinct and make more semantic sense
typedef unsigned char ushort;
typedef unsigned int uint;


// Allow for storage of all line sensors in one 8b number
typedef union {
    struct {
        bool a  :1;
        bool b  :1;
        bool c  :1;
        bool d  :1;
        bool e  :1;
        bool f  :1;
        bool g  :1;
        bool h  :1;
    };
    ushort val;
} LineSensors;

#endif	/* TYPES_H */

