#include <bits/stdc++.h>
using namespace std;
int main()
{
	time_t timer, ZK, GK;//�������� 
	time(&timer); 
	timer = time(NULL);		
//	time_t time (time_t* timer);//��ȡ��ǰʱ��,Ȼ��ֵ��ָ����� timer
//							    //ע�������ʱ��������ʱ���ȥ1900��1��1��0ʱ0��0���ʱ��
	char* ctime (const time_t * timer);//��time_tת�����ַ���
	cout << ctime(&timer);// �ַ����ĸ�ʽΪ: Www Mmm dd hh:mm:ss yyyy
    //����      ��     ��  ʱ   ��  ��  ��
	return 0; 
 } 
