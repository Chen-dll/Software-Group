//#This program is coded by Chen Sixiang#// 
#include <bits/stdc++.h>
#include <conio.h>//getch() 
#include <windows.h>//Sleep()
#include <winuser.h>//HWND and so on 
#include <Cstring>
#include <tchar.h>
#include <ShlObj.h>
#include "FUCKING CRAZY.h" 
#include "SET REG.h"
#include "Administrator.h"
#include "PATH.h"
#include "HIDE.h" 
//#include "Service.h"
//#include "CHECKWINDOWS.h"
//#include "DON'T TRY TO CLOSE.h"
//#include "HOOK.h"
// #include <future>

using namespace std;//cout

HWND hwndFound;
HWND GetConsoleHwnd(void);
BOOL bIsAdmin = IsUserAnAdmin();
string name = GetProgramName();
LPCSTR str = name.c_str();

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType)//�����򽫹ر�ʱ 
{
    if(CTRL_CLOSE_EVENT == dwCtrlType)
    {
//	    bIsAdmin = false;//Ӱ��������� 
		ShellExecuteA(NULL,"open",str,0,0,0);//�ٴδ� 
    }
    return true;
}  

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    SetConsoleCtrlHandler(HandlerRoutine, TRUE);//���߳�,���ú��� 
	return 0L;
}

DWORD WINAPI WINDOWSTEXT(LPVOID lpParameter)
{
    while(1) 
	{
        SetWindowText(hwndFound, "��У����ʱ");//���ô��ڱ��� 
		Sleep(2000);
	}
	return 0L;
}

//DWORD WINAPI SERVICE(LPVOID lpParameter)
//{
//	char str[1000];
//	string PATH = path();
//	for(int i = 0; i < PATH.length(); i++) str[i] = PATH[i];
//    system(str);
//    Sleep(3000);
//	return 0L;
//}

//DWORD WINAPI REG(LPVOID lpParameter)
//{
//    SET_REG();
//	return 0L;
//}

//DWORD WINAPI ADMINISTRATOR(LPVOID lpParameter)
//{
//	if(bIsAdmin == false) GetPrivilege(); 
//	return 0L;
//}

DWORD HIDE(LPVOID lpParameter)//���ش��� 
{
	hwndFound = GetConsoleHwnd();
    HIDE(hwndFound);
	return 0L;
}

string int2string(int i);
string s1 = int2string(10), s2 = "2021-02-21 13:00:00";//���÷�Уʱ�� 

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

//string get_time_str() //return a string of time
//{
//    time_t ts = time(NULL); //nowTime 
//    tm time = *localtime(&ts);
//    int year = time.tm_year + 1900;
//    int month = time.tm_mon + 1;
//    int day = time.tm_mday;
//    int hour = time.tm_hour;
//    int min = time.tm_min;
//    int sec = time.tm_sec;
//    int week = time.tm_wday ;
//
//    stringstream s;
//    s <<year<<"-"<<month<<"-"<<day<<" "<<hour<<":"<<min<<":"<<sec; //write
//    string s1 = s.str();
//    return s1;
//}

string get_time_str()
{
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );
    return tmp;
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

int main(int argc,char *argv[])//�����ȡ·�����˴�û�� 
{	
//    if(bIsAdmin == false)
    string fake = "";
    ifstream infile; 
    SetFileAttributes("Administrator.dat", FILE_ATTRIBUTE_NORMAL);
    infile.open("Administrator.dat");   
    infile >> fake;
    infile.close();
    if(fake != "1")
	{
		ofstream outfile;
    	outfile.open("Administrator.dat");
        GetPrivilege();
		SET_REG();  
        bIsAdmin = IsUserAnAdmin();
        outfile << bIsAdmin;
        outfile.close(); 
    }
	hwndFound = GetConsoleHwnd();//��ȡ��ǰ����hWnd
    ShowWindow(hwndFound, SW_HIDE);
    TCHAR tc[200] = _T("��У����ʱ");
    TCHAR TC[200] = _T("��У����ʱ����������!");
    TCHAR WAR[200] = _T("WARNING"); 
	HANDLE hMutex = CreateMutex(NULL, TRUE, tc);
	if(GetLastError() == ERROR_ALREADY_EXISTS)//�ж��Ƿ���ͬ���ĳ����������� 
	{
		if(hMutex) 
		{
            CloseHandle(hMutex);//�رոó��� 
            MessageBox(NULL, TC, WAR, 0);//���ڱ��� 
  			return 0;//�������� 
	    }
	} 
	HANDLE thread[5];  
//    thread[1] = CreateThread(NULL, 0, ADMINISTRATOR, NULL, 0, NULL);//��ù���ԱȨ�� 
//	::SetThreadPriority(thread[1],THREAD_PRIORITY_IDLE); 
//    ::ResumeThread(thread[1]);
//	WaitForSingleObject(thread[1],INFINITE);    
	thread[2] = CreateThread(NULL, 0, WINDOWSTEXT, NULL, 0, NULL);//���ô��ڱ��� 
	thread[3] = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);//���ڹر�ǰִ�к��� 
	thread[4] = CreateThread(NULL, 0, HIDE, NULL, 0, NULL);//������Ƶ����������� 
//	thread[5] = CreateThread(NULL, 0, REG, NULL, 0, NULL);//����ע��� 
//	thread[6] = CreateThread(NULL, 0, SERVICE, NULL, 0, NULL);//ע����� 
    DWORD dwExStyle = ::GetWindowLong(hwndFound, GWL_EXSTYLE); 
    dwExStyle |=  WS_EX_TOOLWINDOW;
    ::SetWindowLong(hwndFound, GWL_EXSTYLE, dwExStyle & ~WS_EX_APPWINDOW);
	SetWindowLong(hwndFound, GWL_EXSTYLE, dwExStyle & ~WS_EX_APPWINDOW);
	SetWindowPos(hwndFound,HWND_TOPMOST,-5,0,310,150,SWP_SHOWWINDOW);//���ô�����ǰ�����Ĵ���λ�úʹ�С 
    FUCKING_CRAZY(hwndFound);//���ùرպ���С����ť hhh 
    while(1)
	{
        print();//��ӡʱ�� 
 	    SetWindowPos(hwndFound,HWND_TOPMOST,-5,0,310,150,SWP_SHOWWINDOW);//������ʾ����ǰ�� 
	}
//    CloseHandle(thread[1]);//�ر��߳�
    CloseHandle(thread[2]);
    CloseHandle(thread[3]);
	CloseHandle(thread[4]);
//	CloseHandle(thread[5]);
	return 0;
}
/*#This program is coded by Chen Sixiang#*/ 
