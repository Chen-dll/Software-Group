#include <windows.h>
#include <stdio.h>
#include <TlHelp32.h>
#include <iostream>
#include <tchar.h>
#include <bits/stdc++.h>
//#include "DELETE REG.h" 
#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")//����ʾ����

using namespace std;

string name = "�򿪷�У����ʱ.exe";

bool GetPrivilege()
{
    // ��Ȩ�ɹ� �ǵùرոý��̣�
    CreateEvent(NULL, FALSE, FALSE, _T("{29544E05-024F-4BA1-A272-452DBC8E17A4}"));
    if (ERROR_SUCCESS != GetLastError()) return false;
    else
    {
        TCHAR strPath[MAX_PATH] = { 0 };
        HMODULE hModule = NULL;
        GetModuleFileName(hModule, strPath, MAX_PATH);

        SHELLEXECUTEINFO sei = { sizeof(SHELLEXECUTEINFO) };
        sei.lpVerb = TEXT("runas");
        sei.lpFile = strPath;
        sei.nShow = SW_SHOWNORMAL;
        if (!ShellExecuteEx(&sei))
        {
            DWORD dwStatus = GetLastError();
            if (dwStatus == ERROR_CANCELLED)
            {
                return false;
            }
            else if (dwStatus == ERROR_FILE_NOT_FOUND)
            {
                return false;
            }
        }
    }
    Sleep(300);// ��ֹ�˳���̫��        
    return true;
}

void CloseProcess( DWORD dwpid )
{
	HANDLE hProcess = OpenProcess( PROCESS_TERMINATE, FALSE, dwpid );
	if ( hProcess )
		TerminateProcess( hProcess, -1 );
	return;
}

int main()
{
//	HWND hwndFound = GetConsoleHwnd();
//  ShowWindow(hwndFound, SW_HIDE);
    GetPrivilege(); 
    HKEY hKEY;//ע��� 
    RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKEY);
    RegDeleteValue(hKEY, "��У����ʱ"); 
   	RegCloseKey(hKEY);
	HANDLE hProceessnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	if (hProceessnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(pe32);
		BOOL	hProcess = Process32First( hProceessnap, &pe32 );
		char	buff[1024];
		while ( hProcess )
		{//�ҵ���������ͬ�ģ�ǿ�ƹص� 
			if (pe32.szExeFile == name) CloseProcess( pe32.th32ProcessID );
			hProcess = Process32Next( hProceessnap, &pe32 );
		}
	}
    CloseHandle(hProceessnap);
	ofstream outfile;
	int zero = 0;
	outfile.open("Administrator.dat");
    outfile << zero;//detail
    outfile.close(); 
    SetFileAttributes("Administrator.dat", FILE_ATTRIBUTE_HIDDEN);
	return 0;
}
//This program is coded by Chen Sixiang// 