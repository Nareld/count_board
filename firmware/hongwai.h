#ifndef __HONGWAI_H__
#define __HONGWAI_H__

#include <reg51.h>

sbit hongwai1 = P2^1;
sbit hongwai2 = P2^2;
sbit hongwai3 = P2^3;
sbit hongwai4 = P2^4;
sbit hongwai5 = P2^5;

unsigned char key1buf = 0xff;//���⻺����
bit key1backup = 1;//������һ��
bit key1sta = 1;//���εĺ���ɨ��ֵ

void scan1();
void hongwaidrive1();
#endif