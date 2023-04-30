#include "delay.h"

void delayms(unsigned int ms)
{
    unsigned int i,j;
    for(i=ms;i>0;i--)
        for(j=124;j>0;j--);
}