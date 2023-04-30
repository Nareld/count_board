#include <reg51.h>
#include "HC595.h"
#include "delay.h"
#include "display.h"

void Timer0Init(void);

void main()
{
    unsigned int i = 20000;//开机界面倒计时变量
    HC_595_INIT();
    Timer0Init();
    while(i--);
    while(1)
    {
        LEDBuf[0]=1;LEDBuf[1]=2;LEDBuf[2]=3;LEDBuf[3]=4;
        LEDBuf[4]=5;LEDBuf[5]=6;LEDBuf[6]=7;LEDBuf[7]=8;
    }
}

void Timer0Init(void)		//500微秒定时标记
{
//	AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x33;		//设置定时初始值
	TH0 = 0xFE;		//设置定时初始值
    ET0 = 1;
    EA = 1;
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}
 
void InterruptTimer0() interrupt 1
{
    TR0 = 0;     //定时器0关闭计时
    display();
//    scan1();
    TH0 = 0xFE;  //重新加载初值
	TL0 = 0x33; 
    TR0 = 1;     //定时器0开始计时
}