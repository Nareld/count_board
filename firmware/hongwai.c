#include "hongwai.h"
#include "display.h"

void scan1()
{

    key1buf = (key1buf<<1) | hongwai1;
    if (key1buf == 0x10)//����4��ɨ��ֵΪ0,�ѵ���
    {
        key1sta = 0;
    }
    else if (key1buf == 0x0f)//����4��ɨ��ֵΪ1���Ѿ���
    {
        key1sta = 1;
    }
    else //���಻�ȶ���������
    {}       
}

void hongwaidrive1()
{
    if (key1sta != key1backup)//����״̬�����˱仯
    {
        if (key1backup == 0)//�ϴ�Ϊ0������
        {
            LED1_ADD();
        }
        key1backup = key1sta;
    } 
}