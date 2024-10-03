// HideMyProcess.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "HideMyProcess.h"
#include <CommCtrl.h>
#include <wchar.h> 
DWORD dwDoSomethingID;  // �Խ�����Ƶ��  -  ��ը��
DWORD dwCloseID;		// �Խ�����Ƶ��  -  ���߽��복վ�ڲ����ˣ���ɱ�����̹ر�
#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

// �˴���ģ���а����ĺ�����ǰ������: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO:  �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_HIDEMYPROCESS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HIDEMYPROCESS));

	// ����Ϣѭ��: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_HIDEMYPROCESS));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= 0;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      800, 400, 400, 400, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}
DWORD WINAPI HideMyProcss(LPARAM lparam)
{
	while (TRUE)
	{
		HWND m_hWnd = FindWindowA("#32770", "Windows ���������");
		if (!m_hWnd)// ���ҵ������������������
		{
			Sleep(100);
			continue;
		}
		HWND hwnd = GetWindow(m_hWnd, GW_CHILD);//��鵽TabControl�Ĵ���
		while (hwnd != NULL)
		{
			HWND hwnd_1 = GetWindow(hwnd, GW_CHILD);// ���̴���
			while (hwnd_1 != NULL)
			{
				TCHAR wndtext[MAX_PATH] = { 0 };
				GetWindowText(hwnd_1, wndtext, MAX_PATH);
				if (lstrcmp(wndtext, "����") == 0)
				{
					DWORD dwPID;
					GetWindowThreadProcessId(m_hWnd, &dwPID);//��ȡ����������Ľ���ID
					HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dwPID);
					if (!hProcess)
					{
						Sleep(100);
						continue;
					}
					LVITEM lvitem, *plvitem;
					WCHAR ItemLocalBuf[512], *pRemoteBuf;
					pRemoteBuf = (WCHAR *)VirtualAllocEx(hProcess, NULL, 512, MEM_COMMIT, PAGE_READWRITE);
					// ������������Ľ���������һƬ�ڴ�
					plvitem = (LVITEM *)VirtualAllocEx(hProcess, NULL, sizeof(LVITEM), MEM_COMMIT, PAGE_READWRITE);
					// listview item struct init
					lvitem.cchTextMax = 512;
					lvitem.iSubItem = 0;
					lvitem.mask = LVIF_TEXT;
					lvitem.pszText = pRemoteBuf;
					// ���Զ�������ڴ��Ƿ�ɹ������ʧ�ܣ����� FALSE
					if (!plvitem || !pRemoteBuf)
					{
						Sleep(10);
						continue;
					}
					// �Ѳ���д��Զ�̽��� 
					WriteProcessMemory(hProcess, plvitem, &lvitem, sizeof(LVITEM), NULL);

					//  ��ʽ�ɻ�
					// ��ȡListview��ȫ������
					int cnt = ListView_GetItemCount(hwnd_1);
					for (int i = 0; i < cnt; i++)
					{
						LRESULT nbuf = SendMessage(hwnd_1, LVM_GETITEMTEXT, (WPARAM)i, (LPARAM)plvitem);// ���ػ�ȡ���ı����� 
						if (nbuf)
						{
							// �ѽ����Զ�̵Ľ��������ȡ����
							ReadProcessMemory(hProcess, pRemoteBuf, ItemLocalBuf, 512 * sizeof(WCHAR), NULL);
							if (_tcsstr(ItemLocalBuf, "HideMyProcess") != 0)
							{
								// ��������С���
// 								WriteProcessMemory(hProcess, pRemoteBuf, L"������QQ.exe", 30, 0);
// 								nbuf = SendMessage(hwnd_1, LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)plvitem);
								ListView_DeleteItem(hwnd_1, i);
							}
						}
					}
				}
				hwnd_1 = GetWindow(hwnd_1, GW_HWNDNEXT);
			}
			hwnd = GetWindow(hwnd, GW_HWNDNEXT);
		}
	}
	return 0;
}
//
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	DWORD lStyle;
	HANDLE hHackThread;
	switch (message)
	{
	case WM_NCPAINT:return true;
	case WM_NCCALCSIZE:return true;
	case WM_NCACTIVATE:return true;
	case WM_CREATE:
		// ������һ������ϵͳ��Ψһ��һ��32λ����ֵ����Ϊ�Խ���Ƶ����ID
		dwDoSomethingID = GlobalAddAtom("ZS 431493983");
		dwCloseID = GlobalAddAtom(L"Window 921700006");
		if (!RegisterHotKey(hWnd, dwDoSomethingID, NULL, VK_F7))//F7 ������Ӧ�ڸɻ��µ�Ƶ��
		{
			MessageBox(0, "ע��ɻ��µ��ȼ�ʧ����", 0, 0);
			PostQuitMessage(0);
		}
		if (!RegisterHotKey(hWnd, dwCloseID, NULL, VK_F8))// F8 ��Ӧ�ڹرյ�Ƶ��
		{
			MessageBox(0, "ע������رյ��ȼ�ʧ����", 0, 0);
			PostQuitMessage(0);
		}

		lStyle = GetWindowLong(hWnd, GWL_EXSTYLE);//��ȡ���ڵĸ߼�����
		lStyle &= ~WS_EX_APPWINDOW;// ȥ�������ڵ�WS_EX_APPWINDOW
		lStyle |= WS_EX_TOOLWINDOW;// ����WS_EX_TOOLWINDOW
		lStyle |= WS_EX_LAYERED;
		SetWindowLong(hWnd, GWL_EXSTYLE, lStyle);//���ûش�������ȥ
		SetLayeredWindowAttributes(hWnd, RGB(0xFF, 0xFF, 0xFF), 0, LWA_COLORKEY);

		// �Ѵ����ƶ������꣨0��0����λ�ã�ͬʱ���ڴ�С����Ϊ0��0
		// SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW);
		hHackThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)HideMyProcss, 0, 0, 0);
		CloseHandle(hHackThread);
		break;
	case WM_HOTKEY:
		if (wParam == dwCloseID)
		{
			MessageBox(0, "BYE BYE", 0, 0);
			PostQuitMessage(0);
		}
		else if (wParam == dwDoSomethingID)
		{
			// do something ,  format your disk
			MessageBox(0, L"hack your pp", 0, 0);
		}
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �����˵�ѡ��: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO:  �ڴ���������ͼ����...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
