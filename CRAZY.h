#ifndef FUCKING_CRAZY_H
#define FUCKING_CRAZY_H
#include <windows.h>

COLORREF col;
UINT r=GetRValue(col), g=GetGValue(col),b=GetBValue(col);//RGB() 

void FUCKING_CRAZY(HWND hwnd)
{ 
    HMENU hmenu = GetSystemMenu(hwnd, false);
    RemoveMenu(hmenu, SC_CLOSE, MF_BYCOMMAND);
    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    style &= ~(WS_MINIMIZEBOX);//���ιرպ���С�� 
    DWORD dwExStyle = GetWindowLong(hwnd, GWL_EXSTYLE);  
	dwExStyle |=  WS_EX_TOOLWINDOW;//ALT+TAB����ʾ 
	LONG styleValue = ::GetWindowLong(hwnd, GWL_EXSTYLE); //������չ�������� 
    styleValue |= WS_EX_LAYERED; 
    dwExStyle |= WS_EX_TRANSPARENT;//����괩͸���ڵ�� 
    SetWindowLong(hwnd,GWL_EXSTYLE,styleValue);
    SetLayeredWindowAttributes(hwnd,RGB(r,g,b), 180, LWA_ALPHA);//���ô��ڰ�͸��									   
	SetWindowLong(hwnd, GWL_EXSTYLE, dwExStyle & ~WS_EX_APPWINDOW);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    SetWindowLong(hwnd, GWL_STYLE, style);//���ô������� 
    ShowWindow(hwnd, SW_SHOWNORMAL);//������ʾ 
    DestroyMenu(hmenu);
    ReleaseDC(hwnd, NULL);
}
#endif
