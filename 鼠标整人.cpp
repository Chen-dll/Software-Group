#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	POINT p; 
	while(1)
    {
		GetCursorPos(&p);//��ȡ������� 
		SetCursorPos(p.x + 5, p.y);//����������� 
		Sleep(10); 
		//�����ƶ�ʱ���� 
        cout << p.x << " " << p.y << endl;
        // �����ǰ���(x,y)����
	}
	return 0;
} 
