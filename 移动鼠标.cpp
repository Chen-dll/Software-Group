#include <iostream>
#include <windows.h>
#include <cstdio>
 
using namespace std;
 
int main(){
	POINT p; 
	while(1){
		GetCursorPos(&p);//��ȡ������� 
		printf("%d %d", p.x,p.y);
        system("pause");
        // SetCursorPos(p.x+3,p.y);//����������� 
		// Sleep(10);//�����ƶ�ʱ���� 
	}
	mouse_event (MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
	/*���ĵ�ǰλ�õ�����mouse_event(MOUSEEVENTF_XXXXXXX,0,0,0,0)��ǰ������0��x��y����
    �����û��ʹ��MOUSEEVENTF_ABSOLUTE������Ĭ�ϵ����������굱ǰλ�õĵ㣬���x����y����
    0��0��ʾ���⺯����Ϊ�ǵ�ǰ������ڵĵ�*/
    mouse_event (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 500, 500, 0, 0 )
    //�������ֱ꣬���趨�������겢����
    // mouse_event(MOUSEEVENTF_LEFTDOWN, X * 65536 / 1024, Y * 65536 / 768, 0, 0);
    // mouse_event(MOUSEEVENTF_LEFTUP, X * 65536 / 1024, Y * 65536 / 768, 0, 0);
    //����X��Y�ֱ�����Ҫ����ĵ�ĺ������������
    return 0;
}