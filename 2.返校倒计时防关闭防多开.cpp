//#This program is coded by Chen Sixiang#// 
#include <bits/stdc++.h>
#include <conio.h>//getch() 
#include <windows.h>//Sleep()
#include <winuser.h>//HWND and so on 
#include "FUCKING CRAZY.h" 
#include <Cstring>
#include <tchar.h>
//#include "CHECKWINDOWS.h"
//#include "DON'T TRY TO CLOSE.h"
//#include "HOOK.h"

using namespace std;//cout

HWND hwndFound;
HWND GetConsoleHwnd(void);

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType)//�����򽫹ر�ʱ 
{
    if(CTRL_CLOSE_EVENT == dwCtrlType)
    {
	    ShellExecuteA(NULL,"open","��У����ʱ.exe",0,0,0);//�ٴδ� 
    }
}   

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    SetConsoleCtrlHandler(HandlerRoutine, TRUE);//���߳�,���ú��� 
	return 0L;
}

string int2string(int i);
string s1 = int2string(10), s2 = "2020-8-30 18:00:00";//���÷�Уʱ�� 

time_t convert_string_to_time_t(const std::string & time_string)  //string to time_t 
{  
	struct tm tm1;  
	time_t time1;  
    sscanf(time_string.c_str(), "%d-%d-%d %d:%d:%d" ,&(tm1.tm_year), &(tm1.tm_mon),&(tm1.tm_mday),&(tm1.tm_hour), &(tm1.tm_min),&(tm1.tm_sec));          
    tm1.tm_year -= 1900;  
    tm1.tm_mon --;  
	tm1.tm_isdst=-1;  
	time1 = mktime(&tm1);     
    return time1;  
}  

string get_time_str() //return a string of time
{
    time_t ts = time(NULL); //nowTime 
    tm time = *localtime(&ts);
    int year = time.tm_year + 1900;
    int month = time.tm_mon + 1;
    int day = time.tm_mday;
    int hour = time.tm_hour;
    int min = time.tm_min;
    int sec = time.tm_sec;
    int week = time.tm_wday ;

    stringstream s;
    s <<year<<"-"<<month<<"-"<<day<<" "<<hour<<":"<<min<<":"<<sec; //write
    string s1 = s.str();
    return s1;
}

string int2string(int i)
{
    stringstream s;
    s << i;
    string ss = s.str();
    return ss;
}

void print()
{	//too lazy to code 
    s1=get_time_str();//��ǰʱ��
    time_t start,end;
	start = time(NULL);  
    end = convert_string_to_time_t(s2);
	int dif = difftime (end,start);  
    int days = (dif)/(24*3600);
    int hours = (dif)%(24*3600)/(3600);
    int minutes = (dif)%(3600)/(60);
    int seconds = (dif)%(60);
	system("cls"); 
	cout << "��ǰʱ��:      " << s1 << endl;
	for(int i = 0; i <= s2.length(); i++)//ϸ�� 
	{
		if(s2[i] == '-') break;
		cout << s2[i];
	}
	cout << "��Уʱ��:  " << s2 << endl << "ʣ������:      " << dif;
	cout << "\n\n" << "\t\t\t\t\t\t\t" << days << "��" << hours << "Сʱ" << minutes << "����" 
	<< seconds << "��";
    Sleep(1000); 
}

HWND GetConsoleHwnd(void)//��ȡ����hWnd 
{
    #define MY_BUFSIZE 1024 // Buffer size for console window titles.
    HWND hwndFound;         // This is what is returned to the caller.
    char pszNewWindowTitle[MY_BUFSIZE]; // Contains fabricated
                                           // WindowTitle.
    char pszOldWindowTitle[MY_BUFSIZE]; // Contains original
                                           // WindowTitle.
       // Fetch current window title.
    GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);

	// Format a "unique" NewWindowTitle.

    wsprintf(pszNewWindowTitle,"%d/%d",               
	GetTickCount(),
    GetCurrentProcessId());
       // Change current window title.
    SetConsoleTitle(pszNewWindowTitle);
       // Ensure window title has been updated.
    Sleep(40);
       // Look for NewWindowTitle.
       hwndFound=FindWindow(NULL, pszNewWindowTitle);
       // Restore original window title.
       SetConsoleTitle(pszOldWindowTitle);
       return(hwndFound);
}

int main()
{	
	hwndFound = GetConsoleHwnd();//��ȡ��ǰ����hWnd 
    TCHAR tc[200] = _T("��У����ʱ");
    TCHAR TC[200] = _T("��У����ʱ������!");
    TCHAR WAR[200] = _T("WARNING");
	HANDLE hMutex = CreateMutex(NULL, TRUE, tc);	 
    ShowWindow(hwndFound, SW_HIDE);
	if(GetLastError() == ERROR_ALREADY_EXISTS)
	{
		if (hMutex) 
		{
            CloseHandle(hMutex);
            MessageBox(NULL, TC, WAR, 0);
  			return 0;
	    }
	}
    HANDLE thread1 = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);//����һ���߳� 
    SetWindowPos(hwndFound,HWND_TOPMOST,-5,0,310,150,SWP_SHOWWINDOW);//���ô�����ǰ�����Ĵ���λ�úʹ�С 
    FUCKING_CRAZY(hwndFound);//���ùرպ���С����ť hhh 
    SetWindowText(hwndFound, "��У����ʱ"); //���ô��ڱ��� 
    while(1)
	{
        print();//��ӡʱ�� 
 	    SetWindowPos(hwndFound,HWND_TOPMOST,-5,0,310,150,SWP_SHOWWINDOW);//������ʾ����ǰ�� 
	}
    CloseHandle(thread1);//�ر��߳�  
	return 0;
}
/*#This program is coded by Chen Sixiang#*/ 
