#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <tchar.h>
#include <windows.h>

bool GetPrivilege(void)
{
    // ��Ȩ�ɹ� �ǵùرոý��̣�
    CreateEvent(NULL, FALSE, FALSE, _T("{29544E05-024F-4BC1-A272-452DBC8E17A4}"));
    if (ERROR_SUCCESS != GetLastError())
    {
        return false;
    }
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
    Sleep(100);        // ��ֹ�˳���̫��
    return true;
}

#endif 
