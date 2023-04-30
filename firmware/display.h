#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "HC595.h"
#include "delay.h"

unsigned char code LEDdata[];
extern unsigned char LEDBuf[];

void display();
void clrALL();
void LED1_ADD();
void LED2_ADD();
void LED3_ADD();
void LED4_ADD();
void LED5_ADD();

#endif