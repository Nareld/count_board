#include "HC595.h"

void HC_595_INIT()
{
    HC595_SH_CP = 0;
    HC595_ST_CP = 0;
    HC595_DS = 0;
}

void LED_595_DRIVE(unsigned char datL,unsigned char datH)
{
    unsigned char i;
    unsigned char temp;
    temp = datH;
    HC595_ST_CP = 0;
    for (i = 0; i < 8; i++)
    {   
        HC595_DS = temp & 0x80;
        HC595_SH_CP = 1;//´æÈëÒÆÎ»¼Ä´æÆ÷
        temp <<= 1;
        HC595_SH_CP = 0;        
    }
    temp = datL;
    for (i = 0; i < 8; i++)
    {   
        HC595_DS = temp & 0x80;
        HC595_SH_CP = 1;//´æÈëÒÆÎ»¼Ä´æÆ÷
        temp <<= 1;
        HC595_SH_CP = 0;  
    }
    HC595_ST_CP = 1;//´æÈëÊý¾ÝËø´æÆ÷  
}

