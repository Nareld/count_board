#include <reg51.h>
#include "HC595.h"
#include "delay.h"
#include "display.h"

void Timer0Init(void);

void main()
{
    unsigned int i = 20000;//�������浹��ʱ����
    HC_595_INIT();
    Timer0Init();
    while(i--);
    while(1)
    {
        LEDBuf[0]=1;LEDBuf[1]=2;LEDBuf[2]=3;LEDBuf[3]=4;
        LEDBuf[4]=5;LEDBuf[5]=6;LEDBuf[6]=7;LEDBuf[7]=8;
    }
}

void Timer0Init(void)		//500΢�붨ʱ���
{
//	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x33;		//���ö�ʱ��ʼֵ
	TH0 = 0xFE;		//���ö�ʱ��ʼֵ
    ET0 = 1;
    EA = 1;
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}
 
void InterruptTimer0() interrupt 1
{
    TR0 = 0;     //��ʱ��0�رռ�ʱ
    display();
//    scan1();
    TH0 = 0xFE;  //���¼��س�ֵ
	TL0 = 0x33; 
    TR0 = 1;     //��ʱ��0��ʼ��ʱ
}