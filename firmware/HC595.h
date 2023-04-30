#ifndef __HC595_H__
#define __HC595_H__

#include <reg51.h>

sbit HC595_SH_CP = P1^2;
sbit HC595_DS = P1^3;
sbit HC595_ST_CP = P1^4;

void HC_595_INIT();
void LED_595_DRIVE(unsigned char datL,unsigned char datH);

#endif