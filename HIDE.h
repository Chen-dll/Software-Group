#ifndef HIDE_H
#define HIDE_H
#include <iostream>
#include <windows.h>          //���� 0 0 ���� 300 0 ���� 0 145 ���� 300 145 
#include <cstdio>
 
using namespace std;
 
void HIDE(HWND hwnd)
{
	POINT p; 
	while(1)
	{
		GetCursorPos(&p);//��ȡ������� 
		if((p.x >= 0 && p.x <= 300) && (p.y >= 0 && p.y <= 145)) ShowWindow(hwnd, SW_HIDE);//�ж�����Ƿ��ڴ����� 
		else ShowWindow(hwnd, SW_SHOW);//��ʾ����
	}
	return;
}
#endif 
