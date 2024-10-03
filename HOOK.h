#ifndef HOOK_H
#define HOOK_H
#include <assert.h>
#include <windows.h> 
// ȫ��Hook ID
HHOOK g_HookHwnd = NULL ;

// WH_KEYBOARD_LL������Ҫ��ʵ�����ӳ���ȥ
// �����Լ���MSDN��
HINSTANCE hInst;

LRESULT CALLBACK Wndproc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK MyHookFun(int nCode, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  WNDCLASSEX ws;  // ����ṹ ע��:�����õ���WNDCLASSEX

  ws.cbSize = sizeof(WNDCLASSEX);  // ���ؽṹ��С ���ѡ����Ex�ṹ��������
  ws.hbrBackground = (HBRUSH)COLOR_BACKGROUND;  // ������ɫ
  ws.hCursor = LoadCursor(NULL,IDC_ARROW);  // ���ָ����ʽ
  ws.hIcon = LoadIcon(NULL,IDI_APPLICATION);  // ͼ����ʽ
  ws.hIconSm = LoadIcon(NULL,IDI_APPLICATION);  // Сͼ��  ͬ����Ex������
  ws.hInstance = hInstance;  // ��ǰʵ�����
  ws.lpfnWndProc = Wndproc;  // �ص�����ָ��
  ws.lpszClassName = "MyWindows";  // ��������
  ws.lpszMenuName = NULL;   // �˵���
  ws.style = CS_DBLCLKS;  // ����˫��������Ϣ  //CS_HREDRAW | CS_VREDRAW;
  ws.cbClsExtra = 0;  // �޶�����洢
  ws.cbWndExtra = 0;  // �޶��ⴰ��洢

  if (!RegisterClassEx(&ws))  // Ex�Ľṹ����ҪEx��ע�ắ��
  {
    return 0;  // ע��ʧ��ֱ�ӷ���0
  } 

  hInst = hInstance;

  HWND hWnd;

  hWnd = CreateWindowEx(
    0,  // ��չ��ʽ
    "MyWindows",  // ����,����ע��ʱ������
    "For Example",  // ����������
    WS_OVERLAPPEDWINDOW,  // ��ʽ �����Ծ���Ĭ��ֵ
    CW_USEDEFAULT,  // ����Xֵ
    CW_USEDEFAULT,  // ����Yֵ
    CW_USEDEFAULT,  // ������
    CW_USEDEFAULT,  // ����߶�
    NULL,  // �����ھ��
    NULL,  // ���ܲ˵����
    hInstance,  // Ӧ�ó���ʵ�����
    NULL  // ��������
    );

  if (!hWnd)
  {
    return 0;  // ʧ�ܷ���
  }
  
  ShowWindow(hWnd, SW_SHOWNORMAL);  // ��ʾ����
  UpdateWindow(hWnd);  //���´���

  MSG msg;

  // ��Ϣ��ѭ��
  while(GetMessage(&msg,NULL,0,0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return (int)msg.wParam;
}

// ���ص�������
LRESULT CALLBACK Wndproc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
  // �������������ڲ���Hook��װ��ж�صķ���ֵ
  BOOL bL = NULL;
  BOOL bLresult = NULL;

  switch(uMsg)
  {
    case WM_DESTROY:
      // ����ж�ع�����
      // ��������SetWindowsHookEx���ص�ID
      bLresult = UnhookWindowsHookEx(g_HookHwnd);
      // ASSERT����
      // ��expΪFalse,���������
      // ��Ҫafx.h֧��
      assert(bLresult);
      PostQuitMessage(0);
      break;

    case WM_CREATE:
      // ��װ����
      g_HookHwnd = SetWindowsHookEx(WH_KEYBOARD_LL, MyHookFun, hInst, 0);
      // ����.ͬ��
      assert(g_HookHwnd);
      break;

    case WM_LBUTTONDBLCLK:
      MessageBox(hwnd,"Um...KingsamChen is a Fucker","Fuker",MB_OK);
      break;

    default:
      return DefWindowProc(hwnd,uMsg,wParam,lParam);
      break;
  }
  
  return 0;
}

// �����ӳ�
LRESULT CALLBACK MyHookFun(int nCode, WPARAM wParam, LPARAM lParam)
{
  // ���Structure�����˼��̵���Ϣ
  /*typedef struct {
      DWORD vkCode;
      DWORD scanCode;
      DWORD flags;
      DWORD time;
      ULONG_PTR dwExtraInfo;
  } KBDLLHOOKSTRUCT, *PKBDLLHOOKSTRUCT;*/
  // ����ֻ��Ҫ�Ǹ�vkCode
  PKBDLLHOOKSTRUCT pVirKey = (PKBDLLHOOKSTRUCT)lParam;
  
  // MSDN˵��,nCode < 0��ʱ�����
  if (nCode >= 0)
  {
    // ������Ϣ
    switch(wParam) 
    {
      case WM_KEYDOWN:
      case WM_SYSKEYDOWN: 
      case WM_KEYUP:
      case WM_SYSKEYUP:
        switch(pVirKey->vkCode) 
        {
          case VK_LWIN:
          case VK_RWIN:
            return 1;  // �Ե���Ϣ
            break;
        }
        break;
    }    
  }

  return CallNextHookEx(g_HookHwnd, nCode, wParam, lParam);
}
#endif
