#include "hongwai.h"
#include "display.h"

void scan1()
{

    key1buf = (key1buf<<1) | hongwai1;
    if (key1buf == 0x10)//连续4次扫描值为0,已到达
    {
        key1sta = 0;
    }
    else if (key1buf == 0x0f)//连续4次扫描值为1，已经过
    {
        key1sta = 1;
    }
    else //其余不稳定，不更新
    {}       
}

void hongwaidrive1()
{
    if (key1sta != key1backup)//红外状态发生了变化
    {
        if (key1backup == 0)//上次为0，经过
        {
            LED1_ADD();
        }
        key1backup = key1sta;
    } 
}