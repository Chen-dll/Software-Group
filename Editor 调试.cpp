// #This program is coded by Chen Sixiang#//
// #Program Name���ı��༭��#//
// #Finish Date: 2024.10.7#//
// #Environment: Dev-C++ 5.11#// 
#include <iostream>  // ��׼�������
#include <conio.h>   // ���� _getch() �����������������
#include <string>    // �����ַ�������
#include <windows.h> // �����������̨�����˯�ߺ���
#include <stdexcept> // ���� std::out_of_range
#include <fstream>   // ���ڲ����ļ�
#include <time.h>    // ���������
#include <thread>    // ���ڶ��߳�
#include <atomic>    // ����ԭ�ӱ���

#define SIZE 1024 // SIZE

using namespace std;

const int MAX_LOG_SIZE = 1024; // ���������־����

char operationLogs[MAX_LOG_SIZE]; // ȫ�ֲ�����־���� �����洢������־
int logIndex = 0;                 // ��ǰ��־��д��λ��
int IsTest = 0;                   // ��¼����״̬ �����ж�����

// ������¼�ṹ��
struct Operation
{
    int type;          // �������ͣ�1 ��ʾ���룬0 ��ʾɾ����
    char character;    // �������ɾ�����ַ�
    string pastedText; // ��ճ�����ı�������ճ��������ʹ�ã�
};

// �Զ���ջ��
template <typename T>
class Stack
{
private:
    T *data;      // ��̬����洢ջԪ��
    int capacity; // ջ������
    int top;      // ջ������

    // ��̬��չջ������
    void resize()
    {
        int newCapacity = capacity * 2;  // ��չΪԭ������������
        T *newData = new T[newCapacity]; // �����¿ռ�

        // ���ƾ����ݵ�������
        for (int i = 0; i <= top; ++i)
        {
            newData[i] = data[i];
        }

        // ɾ�������飬�л���������
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    // ���캯��
    Stack(int size = SIZE) : capacity(size), top(-1)
    {
        data = new T[capacity]; // ������̬����
    }

    // ��������
    ~Stack()
    {
        delete[] data; // �ͷŶ�̬����
    }

    // ����Ԫ�ص�ջ
    void push(const T &value)
    {
        // ����Ƿ���Ҫ��չ����
        if (top >= capacity - 1)
        {
            resize(); // ��̬��չ����
        }
        data[++top] = value; // ����ջ����������ֵ
    }

    // ��ջ�е���Ԫ��
    T pop()
    {
        if (isEmpty())
        {
            cerr << "ջΪ�գ��޷�����Ԫ�أ�" << endl;
            throw out_of_range("ջΪ��"); // �׳��쳣��Ϣ
        }
        return data[top--]; // ����ջ��Ԫ�ز�����ջ������
    }

    // �鿴ջ��Ԫ��
    T peek() const
    {
        if (isEmpty())
        {
            cerr << "ջΪ�գ��޷��鿴ջ��Ԫ�أ�" << endl;
            throw out_of_range("ջΪ��"); // �׳��쳣��Ϣ
        }
        return data[top]; // ����ջ��Ԫ��
    }

    // ���ջ�Ƿ�Ϊ��
    bool isEmpty() const
    {
        return top == -1; // ջ������Ϊ-1ʱջΪ��
    }

    // ��ȡջ�Ĵ�С
    int size() const
    {
        return top + 1; // ջ�Ĵ�СΪջ��������1
    }

    // ����ջ���ݵ��ַ���
    string toString() const
    {
        string result;
        // ͨ��������������ǰջ�����ݴ洢����ʱջ
        for (int i = 0; i <= top; ++i)
        {
            result += data[i]; // ��������ַ���
        }
        return result; // �����ַ���
    }
};

// �ı��༭����
class TextEditor
{
private:
    Stack<char> textStack;      // �ı�ջ���洢�ı�����
    Stack<Operation> undoStack; // ����ջ���洢��������
    Stack<Operation> redoStack; // ��������ջ
    string clipboard;           // �������ַ���

public:
    // �����ַ�����
    void insertChar(char c)
    {
        textStack.push(c);
        undoStack.push({1, c}); // 1 ��ʾ�������
        while (!redoStack.isEmpty())
            redoStack.pop(); // �������ջ
        // displayUndoStack();  // ��ʾ����ջ
    }

    // ɾ���ַ�����
    bool deleteChar() // �����Ƿ�ɹ�ɾ��
    {
        if (!textStack.isEmpty()) // �ж��ı�ջ�Ƿ�Ϊ��
        {
            char deletedChar = textStack.pop(); // ɾ���ַ�
            undoStack.push({0, deletedChar});   // 0 ��ʾɾ������
            // displayUndoStack();               // ��ʾ����ջ
            while (!redoStack.isEmpty()) // �������ջ
                redoStack.pop();
            return true; // ɾ���ɹ�
        }
        else
        {
            return false; // ɾ��ʧ��
        }
    }

    //	  ��ؼ��Ĵ������
    //    // ��ʾ����ջ������
    //    void displayUndoStack()
    //    {
    //        cout << "\n\n\n";
    //        cout << "\n��ǰ����ջ����: ";
    //        Stack<Operation> tempStack; // ��ʱջ������ʾ����ջ����
    //
    //        // ������ջ�������������ʱջ
    //        while (!undoStack.isEmpty())
    //        {
    //            Operation op = undoStack.pop();
    //            tempStack.push(op); // ������ѹ����ʱջ�Ա���ԭ˳��
    //
    //            // ���ݲ����������
    //            if (op.type == 1)
    //            {
    //                cout << "[����: " << op.character << "] ";
    //            }
    //            else if (op.type == 0)
    //            {
    //                cout << "[ɾ��: " << op.character << "] ";
    //            }
    //            else if (op.type == 2)
    //            {
    //                cout << "[ճ��: " << op.pastedText << "] ";
    //            }
    //        }

    //        // �����ݷŻس���ջ
    //        while (!tempStack.isEmpty())
    //        {
    //            undoStack.push(tempStack.pop());
    //        }
    //        cout << endl; // ����
    //    }

    // ������������
    void undo()
    {
        if (!undoStack.isEmpty()) // �жϳ���ջ�Ƿ�Ϊ��
        {
            Operation lastOperation = undoStack.pop(); // ��ȡ���һ�����
            if (lastOperation.type == 1)               // 1 ��ʾ���������
            {
                textStack.pop(); // ����ʱɾ���ַ�
            }
            else if (lastOperation.type == 0) // 0 ��ʾɾ������
            {
                textStack.push(lastOperation.character); // ����ʱ�ָ��ַ�
            }
            else if (lastOperation.type == 2) // 2 ��ʾճ������������ʱɾ��ճ�����ı�
            {
                // ֱ��ɾ��ճ�����ı�������������ַ�ɾ��
                size_t lengthToDelete = lastOperation.pastedText.size();
                for (size_t i = 0; i < lengthToDelete; ++i)
                {
                    if (!textStack.isEmpty()) // ȷ���������ı�ջ�ķ�Χ
                        textStack.pop();      // ɾ���ַ�
                }
            }
            // ����������ѹ������ջ
            redoStack.push(lastOperation);
            // displayUndoStack(); // ��ʾ����ջ
        }
        else
        {
            showErrorWithDelay("û�п��Գ����Ĳ�����", 1000); // ��ʾ�û�û�пɳ�������
        }
    }

    // ������������
    void redo()
    {
        if (!redoStack.isEmpty()) // �ж�����ջ�Ƿ�Ϊ��
        {
            Operation lastOperation = redoStack.pop(); // ��ȡ���һ����������
            if (lastOperation.type == 1)               // 1 ��ʾ�������
            {
                textStack.push(lastOperation.character);
            }
            else if (lastOperation.type == 0) // 0 ��ʾɾ������
            {
                textStack.pop();
            }
            else if (lastOperation.type == 2) // 2 ��ʾճ������������ʱ���ճ�����ı�
            {
                const string &textToRedo = lastOperation.pastedText; // ��ȡճ�����ı�
                                                                     // �������ճ�����ı���ȷ��˳����ȷ
                for (size_t i = lastOperation.pastedText.size(); i > 0; --i)
                {
                    textStack.push(textToRedo[i - 1]); // �Ӻ���ǰ�����ַ�
                }
            }

            undoStack.push(lastOperation); // �������Ĳ���ѹ�س���ջ
            // displayUndoStack(); // ��ʾ����ջ
        }
        else
        {
            showErrorWithDelay("û�п��������Ĳ�����", 1000); // ��ʾ�û�û�п���������
        }
    }

    // ���Ƶ�������
    void copy()
    {
        clipboard.clear();     // ��ռ�����
        Stack<char> tempStack; // ��ʱջ�������ı�ջ����

        // ���ı����ݸ��Ƶ�������
        // �����ı�ջ�����������ȡ������ӵ�������
        while (!textStack.isEmpty())
        {
            char c = textStack.pop();
            clipboard += c;    // ��ӵ�������
            tempStack.push(c); // �����ݱ��浽��ʱջ
        }

        // �����ݷŻ�ԭջ��ȷ���ı�ջ������
        while (!tempStack.isEmpty())
        {
            textStack.push(tempStack.pop());
        }

        showErrorWithDelay("�ı��Ѹ��Ƶ������壡", 1000); // ��ʾ��Ϣ
    }

    // �Ӽ�����ճ��
    void paste()
    {
        if (clipboard.empty()) // �жϼ������Ƿ�Ϊ��
        {
            showErrorWithDelay("������Ϊ�գ��޷�ճ����", 1000);
            return;
        }

        // �ȱ��浱ǰ�ı����ݵĿ��գ����ڳ�������������
        size_t originalSize = textStack.size();

        // ������������������뵽�ı���ջ�� ���������֤ճ����˳����ȷ
        for (size_t i = clipboard.size(); i > 0; --i)
        {
            textStack.push(clipboard[i - 1]);
        }

        // ������ճ��������¼�ڳ���ջ��
        Operation pasteOperation;
        pasteOperation.type = 2;               // 2 ��ʾճ������
        pasteOperation.pastedText = clipboard; // ��¼ճ�����ı�

        undoStack.push(pasteOperation); // ��ճ��������ӵ�����ջ

        // �������ջ
        while (!redoStack.isEmpty())
            redoStack.pop();

        // ��ʾ����ջ
        // displayUndoStack();
    }

    // ��ʾ��ǰ�ı�����
    void displayText()
    {
        static int lastLineCount = 0;                                     // ������һ����ʾ������
        COORD coord = {0, 0};                                             // ���� (0, 0)
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // ���ù��λ��

        string currentText = textStack.toString(); // ��ȡջ���ݲ�ת��Ϊ�ַ���

        // ����������� ��һ�������ֿ���
        int totalLines;
        if (currentText.length() < 111)
            totalLines = 1;
        else
            totalLines = ((currentText.length() - 111) / 120) + 2; // �Ա��˵��Դ��ڴ�СΪ׼

        // �����ǰ�������ϴ�������ͬ�����������������ͬ����Ϊ�˻�������
        if (totalLines != lastLineCount)
        {
            system("cls");              // ��������
            lastLineCount = totalLines; // ������һ�ε�����
        }

        // ���Բ�����ʾ�������־������
        if (IsTest)
        {
            system("cls"); // ����
            IsTest = 0;    // �ָ����Ա��β���
        }

        cout << string(100, ' ') << "\r��ǰ�ı�: "; // �����ǰ��
        cout << currentText;                        // ����ı�

        COORD newCoord = {0, totalLines + 1};                                // ���ı��·����
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newCoord); // ���ù��λ��

        // ����������ܺͱ�����ʾ
        cout << "ɾ��(Backspace), ����(Ctrl+C), ճ��(Ctrl+V), ��������(Ctrl+Z), ��������(Ctrl+Y), ����(F1), �˳�(Esc)" << endl;

        // ���ù��λ�õ��ı�ĩβ
        int newCoord_x, newCoord_y = totalLines;
        if (totalLines == 1)
            newCoord_x = currentText.length() + 9; // ��Ϊ��һ���� "��ǰ�ı���"
        else
            newCoord_x = (currentText.length() - 111) % 120;                 // ������������
        newCoord = {newCoord_x, newCoord_y};                                 // ����ĩβ����
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newCoord); // ���ù��λ��
    }

    // ��ʾ������Ϣ
    void displayError(const string &message)
    {
        string currentText = textStack.toString(); // ��ȡջ���ݲ�ת��Ϊ�ַ���
        int totalLines;                            // ͬ�ϲ���
        if (currentText.length() < 111)
            totalLines = 1;
        else
            totalLines = ((currentText.length() - 111) / 120) + 2;           // �Ա��˵��Դ��ڴ�СΪ׼
        COORD newCoord = {0, totalLines + 1};                                // ���ı��·����
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newCoord); // ���ù��λ��
        cout << string(100, ' ');                                            // �����ǰ������
        cout << "\r" << message;                                             // ���������Ϣ
        cout.flush();                                                        // ˢ�������
    }

    // �ӳ�������Ϣ��ʾʱ��
    void showErrorWithDelay(const string &message, int delay)
    {
        displayError(message); // ��ʾ������Ϣ
        Sleep(delay);          // �ӳ�ָ��ʱ��
        displayError("");      // ���������Ϣ
        displayText();         // ���ı��������������������
    }

    // �������������Ϣʱ���λ��
    void setTestCursor()
    {
        // ��ȡջ���ݲ�ת��Ϊ�ַ���
        string currentText = textStack.toString();

        // ����������� ͬ�ϲ���
        int totalLines;
        if (currentText.length() < 111)
            totalLines = 1;
        else
            totalLines = ((currentText.length() - 111) / 120) + 2; // �Ա��˵��Դ��ڴ�СΪ׼

        COORD newCoord = {0, totalLines + 2};                                // ���ı��·����
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newCoord); // ���ù��λ��
    }

    // ����ı�ջ
    void clearTextStack()
    {
        while (!textStack.isEmpty())
        {
            textStack.pop(); // ɾ���ַ�
        }
    }

    // �ӳ�������Ϣ��ʾʱ��
    void showOperationWithDelay(const string &message, int delay)
    {
        setTestCursor(); // �ѹ���Ƶ��ı��·������������Ϣ
        cout << "\r" << message;
        cout.flush();
        Sleep(delay); // ��ʱ
        cout << "\r" << string(100, ' ') << "\r";
        displayText(); // ������ʾ�ı�
    }

    // ׷����־����־����
    void appendLog(const string &log)
    {
        if (logIndex + log.size() >= MAX_LOG_SIZE) // ������־����
        {
            cout << "��־�������޷�����д�롣" << endl; // ��־��������ʾ
            return;
        }
        for (size_t i = 0; i < log.size(); ++i) // ����־�ַ����е�ÿ���ַ�����洢��������
        {
            operationLogs[logIndex++] = log[i];
        }
        operationLogs[logIndex++] = '\n'; // ÿ����־����ӻ��з�
    }

    // ����־д���ļ�
    void saveLogToFile(const string &filename, TextEditor &editor)
    {
        ofstream outFile(filename.c_str()); // ����һ������ļ�������
        if (!outFile)                       // ����ļ��Ƿ�ɹ���
        {
            editor.setTestCursor();                       // �ƶ���굽�ʵ�λ��
            cerr << "�޷����ļ�: " << filename << endl; // ��ʾ��Ϣ
            return;
        }

        outFile.write(operationLogs, logIndex);           // ����־����д���ļ�
        outFile.close();                                  // �ر��ļ�
        editor.setTestCursor();                           // �ƶ���굽�ʵ�λ��
        cout << "��־�ѱ��浽�ļ�: " << filename << endl; // ��ʾ��Ϣ
    }

    // ģ����̰����¼��ĺ���
    void simulateKey(WORD virtualKey, bool isPress)
    {
        INPUT input = {0};           // ��ʼ������ṹ��
        input.type = INPUT_KEYBOARD; // ��ʾ�������¼���һ�������¼�
        input.ki.wVk = virtualKey;   // �������ⰴ����

        input.ki.dwFlags = isPress ? 0 : KEYEVENTF_KEYUP; // �ж��ǰ��»����ͷ�
        // ��� isPress Ϊ true��������Ϊ 0����ʾ�����¼�
        // ��� isPress Ϊ false��������Ϊ KEYEVENTF_KEYUP����ʾ�ͷ��¼�

        SendInput(1, &input, sizeof(INPUT)); // ���������¼�

        // Ϊ�˹۲�Ч�������һЩ�ӳ�
        Sleep(100);
    }

    // ģ���ı����룬���ִ�Сд��ĸ
    void simulateTextInput(const string &text, TextEditor &editor)
    {
        for (size_t i = 0; i < text.size(); ++i) // ����������ɵ��ַ���
        {
            char ch = text[i];
            bool isUpperCase = isupper(ch);    // �ж��Ƿ��Ǵ�д��ĸ
            SHORT vk = VkKeyScan(tolower(ch)); // ��ȡ��Ӧ��Сд��ĸ���ⰴ����
            BYTE vkCode = LOBYTE(vk);          // ��ȡ���ⰴ����

            // ����Ǵ�д��ĸ���Ȱ�ס Shift ��
            if (isUpperCase)
            {
                simulateKey(VK_SHIFT, true); // ���� Shift ��
            }

            showOperationWithDelay("ģ�ⰴ������: " + string(1, ch), 500); // ��ʾ������Ϣ
            appendLog("ģ�ⰴ������: " + string(1, ch));                   // �����������¼����־
            simulateKey(vkCode, true);                                     // ���°���
            Sleep(100);                                                    // �ӳ٣��۲�����Ч��
            simulateKey(vkCode, false);                                    // �ͷŰ���

            // ����Ǵ�д��ĸ���ͷ� Shift ��
            if (isUpperCase)
            {
                simulateKey(VK_SHIFT, false); // �ͷ�Shift��
            }
            Sleep(100); // ��ÿ���ַ�֮������ӳ�
        }
    }

    // ģ��Backspace��
    void simulateBackspaceKey(TextEditor &editor)
    {
        showOperationWithDelay("ģ�ⰴ��Backspace��", 1000); // ��ʾ��Ϣ
        appendLog("����Backspace��");
        simulateKey(VK_BACK, true);  // ����Backspace��
        Sleep(100);                  // �ӳ�
        simulateKey(VK_BACK, false); // �ͷ�Backspace��
        Sleep(100);                  // �ӳ�
    }

    // ģ�� Ctrl + ָ������ (���� Ctrl + Z, Ctrl + C)
    void simulateCtrlKey(WORD key, TextEditor &editor)
    {
        showOperationWithDelay("ģ�ⰴ��Ctrl + " + string(1, key), 1000); // ��ʾ��Ϣ
        appendLog("����Ctrl + " + string(1, key));                        // д��������־

        // ����Ctrl��
        simulateKey(VK_CONTROL, true);
        // ����ָ����
        simulateKey(key, true);
        Sleep(100);              // �ӳ�
        simulateKey(key, false); // �ͷ�ָ����
        Sleep(100);              // �ӳ�
        // �ͷ�Ctrl��
        simulateKey(VK_CONTROL, false);
    }

    // ������������ı�
    string generateRandomText(int length)
    {
        // ��������������ɵ��ַ�
        const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string randomText; // �洢���ɵ��ַ���
        for (int i = 0; i < length; ++i)
        {
            randomText += characters[rand() % characters.size()]; // ʹ��rand��������ַ�
        }
        return randomText; // ����������ɵ��ַ���
    }
};

// ���� Ctrl + C �¼�����������˳�
BOOL WINAPI ConsoleHandler(DWORD signal) 
{
    if (signal == CTRL_C_EVENT)
    {
        return TRUE; // ���� TRUE ��ʾ�Ѵ����ź�
    }
    return FALSE; // ���� FALSE ��ʾδ�����ź�
}

// �߳̿��Ƶ�ȫ�ֱ��� ���̻߳���
atomic<bool> running(true); // ������ѭ���Ƿ�����

// ���Ա༭���Ĺ���
void runTest(TextEditor &editor)
{
    srand(time(0)); // ��ʼ�����������

    string testText = editor.generateRandomText(10); // ����10���ַ�������ı�

    // �������¼� ���� F1�ͽ�����Բ���
    while (running)
    {
        if (_kbhit() && _getch() == 59) // F1 ���� ASCII ֵ�� 59
        {
            editor.clearTextStack();                                                 // ����ı�ջ
            editor.setTestCursor();                                                  // ���ù��λ��
            system("cls");                                                           // ����
            editor.displayText();                                                    // ������ʾ�ı�
            editor.showOperationWithDelay("F1 �������£���ʼ���в��Թ���...", 1000); // ��ʾ��Ϣ
            editor.appendLog("�����ı�: " + testText);                               // ��¼����־

            editor.simulateTextInput(testText, editor); // ģ�������ı�
            Sleep(1000);

            // ���ĸ�������˳��ģ��һ�� �ٽ���������������
            // ģ�⸴�Ʋ��� Ctrl + C
            editor.simulateCtrlKey('C', editor);
            editor.appendLog("ִ�и��Ʋ���"); // ��¼����־
            Sleep(1000);                      // ÿ�β���֮����ͣ1��

            // ģ��ճ������ Ctrl + V
            editor.simulateCtrlKey('V', editor);
            editor.appendLog("ִ��ճ������"); // ��¼����־
            Sleep(1000);                      // ÿ�β���֮����ͣ1��

            // ģ�⳷������ Ctrl + Z
            editor.simulateCtrlKey('Z', editor);
            editor.appendLog("ִ�г�������"); // ��¼����־
            Sleep(1000);                      // ÿ�β���֮����ͣ1��

            // ģ���������� Ctrl + Y
            editor.simulateCtrlKey('Y', editor);
            editor.appendLog("ִ����������"); // ��¼����־
            Sleep(1000);                      // ÿ�β���֮����ͣ1��

            int executedCount = 0;                                            // ��¼��������
            bool operationsExecuted[5] = {false, false, false, false, false}; // ��¼5�������Ƿ���ִ��

            while (executedCount < 5) // ȷ�� 5��������ִ�й�һ��
            {
                int randomOperation = rand() % 5; // ���� 0-4 ֮��������

                if (!operationsExecuted[randomOperation]) // ����ò�����δִ��
                {
                    switch (randomOperation)
                    {
                    case 0:
                        editor.simulateBackspaceKey(editor);
                        editor.appendLog("ִ��ɾ������");
                        break;
                    case 1:
                        editor.simulateCtrlKey('C', editor);
                        editor.appendLog("ִ�и��Ʋ���");
                        break;
                    case 2:
                        editor.simulateCtrlKey('V', editor);
                        editor.appendLog("ִ��ճ������");
                        break;
                    case 3:
                        editor.simulateCtrlKey('Z', editor);
                        editor.appendLog("ִ�г�������");
                        break;
                    case 4:
                        editor.simulateCtrlKey('Y', editor);
                        editor.appendLog("ִ����������");
                        break;
                    }
                    operationsExecuted[randomOperation] = true; // ��Ǹò���Ϊ��ִ��
                    executedCount++;                            // ��������+1
                    Sleep(1000);                                // ÿ�β���֮����ͣ1��
                }
            }

            IsTest = 1;             // ��ɲ��Բ���������������ʾ
            editor.setTestCursor(); // �ƶ���굽�ʵ�λ��
            // ���������־
            cout << "������־:" << endl;
            cout.write(operationLogs, logIndex);               // ��ӡ������־����
            editor.saveLogToFile("operation_log.txt", editor); // ������־���ݵ��ļ�
            editor.clearTextStack();                           // ����ı�ջ
            this_thread::sleep_for(chrono::milliseconds(500)); // ��ͣ���ԣ���ֹ��������
        }
        Sleep(100); // �����ӳ��Լ��� CPU ʹ��
    }
}

// ��ѭ�����������ڴ������������ı�����
void mainLoop(TextEditor &editor)
{
    cout << "���ı��༭��\n\n";
    cout << "ɾ��(Backspace), ����(Ctrl+C), ճ��(Ctrl+V), ��������(Ctrl+Z), ��������(Ctrl+Y), ����(F1), �˳�(Esc)" << endl;
    cout << "�������������";
    _getch();
    // ����������ʾ
    system("cls");
    editor.displayText();
    while (running)
    {
        char ch = _getch(); // �����û�������ַ�

        if (ch == 27)
        {                    // ���� ESC ���˳�
            running = false; // ֹͣ�����߳�
            break;
        }
        else if (ch == 8) // ���� Backspace ��ɾ���ַ�
        {
            if (!editor.deleteChar()) // �ж��ܷ����ɾ��
            {
                editor.showErrorWithDelay("�޷�ɾ�����ı�Ϊ�գ�", 1000); // ��ʾ������Ϣ���ӳ�
            }
            system("cls"); // ����
        }
        else if (ch == 26) // ���� Ctrl+Z ��������
        {
            editor.undo(); // ���ó�������
            system("cls"); // ����
        }
        else if (ch == 25) // ���� Ctrl+Y ��������
        {
            editor.redo(); // ������������
            system("cls"); // ����
        }
        else if (ch == 3) // ���� Ctrl+C ���Ʋ���
        {
            editor.copy(); // ���ø��ƺ���
            system("cls"); // ����
        }
        else if (ch == 22) // ���� Ctrl+V ճ������
        {
            editor.paste(); // ����ճ������
            system("cls");  // ����
        }

        else if (isprint(ch)) // ����ǿɴ�ӡ�ַ�
        {
            editor.insertChar(ch);
        }

        editor.displayText(); // ��ʾ��ǰ���ı�����
    }
}

// ��ù���ԱȨ�����޸Ŀ���̨����
void RunAsAdmin()
{
    // �жϵ�ǰ�����Ƿ��Թ���Ա�������
    BOOL isAdmin = FALSE;
    HANDLE hToken = NULL;
    TOKEN_ELEVATION te;

    // ��ȡ��ǰ���̵�����
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
    {
        DWORD dwSize;

        if (GetTokenInformation(hToken, TokenElevation, &te, sizeof(te), &dwSize))
            isAdmin = te.TokenIsElevated;

        CloseHandle(hToken);
    }

    // ���û�й���ԱȨ�ޣ��������������Ի��Ȩ��
    if (!isAdmin)
    {
        // �������·��
        char path[MAX_PATH];
        GetModuleFileNameA(NULL, path, MAX_PATH);

        // ʹ��ShellExecute�Թ���Ա������г���
        ShellExecuteA(NULL, "runas", path, NULL, NULL, SW_SHOWNORMAL);

        // ��ֹ��ǰ����
        TerminateProcess(GetCurrentProcess(), 0);
    }
}

// ������
int main()
{
    RunAsAdmin();                                // ��ù���ԱȨ��
    SetConsoleCtrlHandler(ConsoleHandler, TRUE); // ���ÿ���̨���ƴ������
    TextEditor editor;                           // �����ı��༭��ʵ��

    thread testThread(runTest, ref(editor));  // �������Թ����߳�
    thread mainThread(mainLoop, ref(editor)); // ����������

    testThread.join(); // �ȴ������߳̽���
    mainThread.join(); // �ȴ������̽���

    return 0;
}
// #This program is coded by Chen Sixiang#//
