#include "display.h"

//动态显示：
//1.送段码
//2.送位选
//3.延时
//4.消隐
unsigned char code LEDdata[] = {  //数码管显示字符转换表，0-9加空白、横杠。
    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
    0x80, 0x90, 0xff, 0xBF};
unsigned char LEDBuf[] = {11,11,11,11,11,11,11,11}; //数据缓冲区
unsigned char code place_code[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //位选列表。

void display()
{
    static unsigned char i;//分支选择变量
    unsigned char temp;//中间变量送段码
    switch(i)
    {
        case 0:
            LED_595_DRIVE(0xff,0x00);//消隐
            temp = LEDdata[LEDBuf[0]];//送段码
            LED_595_DRIVE(temp,place_code[0]);//段码、位选
//            delayms(1);//延时1ms显示
            i++;
            break;
        case 1:
            LED_595_DRIVE(0xff,0x00);//消隐
            temp = LEDdata[LEDBuf[1]];//送段码
            LED_595_DRIVE(temp,place_code[1]);
//            delayms(1);
            i++;
            break;
         case 2:
            LED_595_DRIVE(0xff,0x00);//消隐
            temp = LEDdata[LEDBuf[2]];//送段码
            LED_595_DRIVE(temp,place_code[2]);
//            delayms(1);
            i++;
            break;
         case 3:
            LED_595_DRIVE(0xff,0x00);//消隐
            temp = LEDdata[LEDBuf[3]];//送段码
            LED_595_DRIVE(temp,place_code[3]);
//            delayms(1);
            i++;
            break; 
         case 4:
            LED_595_DRIVE(0xff,0x00);//消隐
            temp = LEDdata[LEDBuf[4]];//送段码
            LED_595_DRIVE(temp,place_code[4]);
//           delayms(1);
            i++;
            break; 
         case 5:
            LED_595_DRIVE(0xff,0x00);//消隐
            temp = LEDdata[LEDBuf[5]];//送段码
            LED_595_DRIVE(temp,place_code[5]);
//           delayms(1);
            i++;
            break; 
         case 6:
            LED_595_DRIVE(0xff,0x00);//消隐
            temp = LEDdata[LEDBuf[6]];//送段码
            LED_595_DRIVE(temp,place_code[6]);
//            delayms(1);
            i++;
            break; 
         case 7:
            LED_595_DRIVE(0xff,0x00);//消隐
            temp = LEDdata[LEDBuf[7]];//送段码
            LED_595_DRIVE(temp,place_code[7]);
//            delayms(1);
            i=0;
//         case 8:
//            LED_595_DRIVE(0xff,0x00);//消隐
//            temp = LEDdata[LEDBuf[8]];//送段码
//            LED_595_DRIVE(temp,place_code[8]);
////            delayms(1);
//            i=0;
//         case 9:
//            LED_595_DRIVE(0xff,0x00);//消隐
//            temp = LEDdata[LEDBuf[9]];//送段码
//            LED_595_DRIVE(temp,place_code[9]);
////            delayms(1);
//            i=0;
//            break; 
         default:break;
    }   
}

//结果清零
void clrALL()
{
    unsigned char i;
    for(i=0;i<10;i++)
    {
        LEDBuf[i] = 0;
    }
}

//五组累加操作，用于红外计数
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
    num += temp;//得到LED显示十进制数
    
    num++;//数字加一
    
    LEDBuf[0] = num/10;//数字到LED
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
//    num += temp;//得到LED显示十进制数
//    
//    num++;//数字加一
//    
//    LEDBuf[2] = num/10;//数字到LED
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
//    num += temp;//得到LED显示十进制数
//    
//    num++;//数字加一
//    
//    LEDBuf[4] = num/10;//数字到LED
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
//    num += temp;//得到LED显示十进制数
//    
//    num++;//数字加一
//    
//    LEDBuf[6] = num/10;//数字到LED
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
//    num += temp;//得到LED显示十进制数
//    
//    num++;//数字加一
//    
//    LEDBuf[8] = num/10;//数字到LED
//    LEDBuf[9] = num%10;
//}