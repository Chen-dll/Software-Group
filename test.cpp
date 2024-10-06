#include <iostream>
#include <conio.h>  // ���� _getch() ����

int main() {
    std::cout << "Press arrow keys (left or right) or ESC to exit:\n";

    while (true) {
        int ch = _getch();  // �����һ���ַ�
        if (ch == 224) {  // ���������������ĵ�һ��ֵ�� 224
            ch = _getch();  // ����ʵ�ʵķ����ֵ
            switch (ch) {
                case 75:  // ���ͷ
                    std::cout << "Left arrow key pressed.\n";
                    break;
                case 77:  // �Ҽ�ͷ
                    std::cout << "Right arrow key pressed.\n";
                    break;
                default:
                    std::cout << "Another special key pressed.\n";
                    break;
            }
        } else if (ch == 27) {  // ESC ���˳�
            break;
        }
    }

    return 0;
}

