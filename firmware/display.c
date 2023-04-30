#include "display.h"

//��̬��ʾ��
//1.�Ͷ���
//2.��λѡ
//3.��ʱ
//4.����
unsigned char code LEDdata[] = {  //�������ʾ�ַ�ת����0-9�ӿհס���ܡ�
    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
    0x80, 0x90, 0xff, 0xBF};
unsigned char LEDBuf[] = {11,11,11,11,11,11,11,11}; //���ݻ�����
unsigned char code place_code[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //λѡ�б�

void display()
{
    static unsigned char i;//��֧ѡ�����
    unsigned char temp;//�м�����Ͷ���
    switch(i)
    {
        case 0:
            LED_595_DRIVE(0xff,0x00);//����
            temp = LEDdata[LEDBuf[0]];//�Ͷ���
            LED_595_DRIVE(temp,place_code[0]);//���롢λѡ
//            delayms(1);//��ʱ1ms��ʾ
            i++;
            break;
        case 1:
            LED_595_DRIVE(0xff,0x00);//����
            temp = LEDdata[LEDBuf[1]];//�Ͷ���
            LED_595_DRIVE(temp,place_code[1]);
//            delayms(1);
            i++;
            break;
         case 2:
            LED_595_DRIVE(0xff,0x00);//����
            temp = LEDdata[LEDBuf[2]];//�Ͷ���
            LED_595_DRIVE(temp,place_code[2]);
//            delayms(1);
            i++;
            break;
         case 3:
            LED_595_DRIVE(0xff,0x00);//����
            temp = LEDdata[LEDBuf[3]];//�Ͷ���
            LED_595_DRIVE(temp,place_code[3]);
//            delayms(1);
            i++;
            break; 
         case 4:
            LED_595_DRIVE(0xff,0x00);//����
            temp = LEDdata[LEDBuf[4]];//�Ͷ���
            LED_595_DRIVE(temp,place_code[4]);
//           delayms(1);
            i++;
            break; 
         case 5:
            LED_595_DRIVE(0xff,0x00);//����
            temp = LEDdata[LEDBuf[5]];//�Ͷ���
            LED_595_DRIVE(temp,place_code[5]);
//           delayms(1);
            i++;
            break; 
         case 6:
            LED_595_DRIVE(0xff,0x00);//����
            temp = LEDdata[LEDBuf[6]];//�Ͷ���
            LED_595_DRIVE(temp,place_code[6]);
//            delayms(1);
            i++;
            break; 
         case 7:
            LED_595_DRIVE(0xff,0x00);//����
            temp = LEDdata[LEDBuf[7]];//�Ͷ���
            LED_595_DRIVE(temp,place_code[7]);
//            delayms(1);
            i=0;
//         case 8:
//            LED_595_DRIVE(0xff,0x00);//����
//            temp = LEDdata[LEDBuf[8]];//�Ͷ���
//            LED_595_DRIVE(temp,place_code[8]);
////            delayms(1);
//            i=0;
//         case 9:
//            LED_595_DRIVE(0xff,0x00);//����
//            temp = LEDdata[LEDBuf[9]];//�Ͷ���
//            LED_595_DRIVE(temp,place_code[9]);
////            delayms(1);
//            i=0;
//            break; 
         default:break;
    }   
}

//�������
void clrALL()
{
    unsigned char i;
    for(i=0;i<10;i++)
    {
        LEDBuf[i] = 0;
    }
}

//�����ۼӲ��������ں������
void LED1_ADD()
{
    unsigned char temp;
    unsigned char num;
    
    if(LEDBuf[0]>=10)
    {
        temp = 0;
    }
    else
    {
        temp = LEDBuf[0];
    }
    num = 10*temp;
    
    if(LEDBuf[1]>=10)
    {
        temp = 0;
    }
    else
    {
        temp = LEDBuf[1];
    }
    num += temp;//�õ�LED��ʾʮ������
    
    num++;//���ּ�һ
    
    LEDBuf[0] = num/10;//���ֵ�LED
    LEDBuf[1] = num%10;
}

//void LED2_ADD()
//{
//    unsigned char temp;
//    unsigned char num;
//    
//    if(LEDBuf[2]>=10)
//    {
//        temp = 0;
//    }
//    else
//    {
//        temp = LEDBuf[2];
//    }
//    num = 10*temp;
//    
//    if(LEDBuf[3]>=10)
//    {
//        temp = 0;
//    }
//    else
//    {
//        temp = LEDBuf[3];
//    }
//    num += temp;//�õ�LED��ʾʮ������
//    
//    num++;//���ּ�һ
//    
//    LEDBuf[2] = num/10;//���ֵ�LED
//    LEDBuf[3] = num%10;
//}

//void LED3_ADD()
//{
//    unsigned char temp;
//    unsigned char num;
//    
//    if(LEDBuf[4]>=10)
//    {
//        temp = 0;
//    }
//    else
//    {
//        temp = LEDBuf[4];
//    }
//    num = 10*temp;
//    
//    if(LEDBuf[5]>=10)
//    {
//        temp = 0;
//    }
//    else
//    {
//        temp = LEDBuf[5];
//    }
//    num += temp;//�õ�LED��ʾʮ������
//    
//    num++;//���ּ�һ
//    
//    LEDBuf[4] = num/10;//���ֵ�LED
//    LEDBuf[5] = num%10;
//}

//void LED4_ADD()
//{
//    unsigned char temp;
//    unsigned char num;
//    
//    if(LEDBuf[6]>=10)
//    {
//        temp = 0;
//    }
//    else
//    {
//        temp = LEDBuf[6];
//    }
//    num = 10*temp;
//    
//    if(LEDBuf[7]>=10)
//    {
//        temp = 0;
//    }
//    else
//    {
//        temp = LEDBuf[7];
//    }
//    num += temp;//�õ�LED��ʾʮ������
//    
//    num++;//���ּ�һ
//    
//    LEDBuf[6] = num/10;//���ֵ�LED
//    LEDBuf[7] = num%10;
//}

//void LED5_ADD()
//{
//    unsigned char temp;
//    unsigned char num;
//    
//    if(LEDBuf[8]>=10)
//    {
//        temp = 0;
//    }
//    else
//    {
//        temp = LEDBuf[8];
//    }
//    num = 10*temp;
//    
//    if(LEDBuf[9]>=10)
//    {
//        temp = 0;
//    }
//    else
//    {
//        temp = LEDBuf[9];
//    }
//    num += temp;//�õ�LED��ʾʮ������
//    
//    num++;//���ּ�һ
//    
//    LEDBuf[8] = num/10;//���ֵ�LED
//    LEDBuf[9] = num%10;
//}