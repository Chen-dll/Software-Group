//#This program is coded by Chen Sixiang#// 
//#Program Name��ѧ����Ϣ����ϵͳ #//
//#Finish Date: 2024.10.6#//
//#Environment: Dev-C++ 5.11 with EasyX#// 
#include <stdio.h>    // ��׼���������
#include <stdlib.h>   // ��׼��
#include <string.h>   // �ַ�������
#include <conio.h>    // ����̨�������
#include <windows.h>  // Windows API
#include <graphics.h> // EasyX ͼ�ο�ͷ�ļ�

#define MAX_STUDENTS 100     // ���洢ѧ������
#define STUDENTS_PER_PAGE 10 // ÿҳ��ʾѧ��������
#define WIDTH 800   // ���ڿ�� 
#define HEIGHT 600  // ���ڸ߶� 

// ѧ���ṹ�嶨��
typedef struct
{
    long long id;       // id   ʹ��long long�ǿ��ǵ�id�Ƚϴ����� ����3124000xxx 
    char name[50];      // ����
    long long age;      // ���� 
    char className[20]; // �༶
    double grade;       // �ɼ�
} Student;

Student students[MAX_STUDENTS]; // ����ѧ���ṹ������
int studentCount = 0;           // ��¼ѧ������
int currentStartIndex = 0; // ��ǰ��ʾ����ʼѧ������
int isQuerying = 0;        // ��ѯ״̬���

// ��������ѧ����Ϣ����Ļ
void draw_Students()
{
    settextstyle(24, 0, "Consolas"); // ����������ʽ

    if (!isQuerying) // ���û�ڲ�ѯ���� 
    {
        cleardevice(); // �����Ļ
        // ���Ƶ�ǰҳ��ѧ����Ϣ
        for (int i = 0; i < STUDENTS_PER_PAGE && currentStartIndex + i < studentCount; i++)
        {
            int y = 50 + i * 40; // ÿ����¼����Ļ�ϵ� y ����
            char info[100];
            // // ��ѧ����Ϣ��ʽ��Ϊ�ַ���
            snprintf(info, sizeof(info), "ID: %lld Name: %s Age: %lld Class: %s Grade: %.2f",
                     students[currentStartIndex + i].id, students[currentStartIndex + i].name,
                     students[currentStartIndex + i].age, students[currentStartIndex + i].className,
                     students[currentStartIndex + i].grade);
            outtextxy(20, y, info); // ��ʾ��Ϣ
        }

        // ȷ����ѧ�������ڿɼ�ѧ���� ������Ҫ������ 
        if (studentCount > STUDENTS_PER_PAGE)
        {
            float sliderRatio = (float)STUDENTS_PER_PAGE / studentCount; // �������
            int sliderLength = (int)(sliderRatio * HEIGHT);              // �������ĳ���

            // ���㻬������λ��
            int sliderPosition = (int)((float)currentStartIndex / (studentCount - STUDENTS_PER_PAGE) * (HEIGHT - sliderLength));

            // ���ƻ�����
            setfillstyle(SOLID_FILL, DARKGRAY);                                               // ��������ɫ
            solidrectangle(WIDTH - 20, sliderPosition, WIDTH, sliderPosition + sliderLength); // ����λ�úʹ�С
        }
    }
}

// �ڿ���̨����
// ���ѧ����Ϣ
void add_Student()
{
    if (studentCount >= MAX_STUDENTS) // �жϻ��ܲ������ѧ��
    {
        printf("Student list is full!\n");
        return;
    }
    printf("Enter student ID: ");
    scanf("%lld", &students[studentCount].id);       // ����id
    printf("Enter student name: ");
    scanf("%s", students[studentCount].name);        // ��������
    printf("Enter student age: ");
    scanf("%lld", &students[studentCount].age);      // ��������
    printf("Enter student class: ");
    scanf("%s", students[studentCount].className);   // ����༶
    printf("Enter student grade: ");
    scanf("%lf", &students[studentCount].grade);     // ����ɼ�

    studentCount++; // ѧ������+1
}

// ���� ID ������ɾ��ѧ����Ϣ
void delete_Student()
{
    char option[10];
    printf("Delete by (id/name): "); // ѡ�� ID �� ���� �����޸�
    scanf("%s", option);             // ����ѡ��

    if (strcmp(option, "id") == 0) // strcmp() �Ƚ������ַ��� ��ȷ��� 0
    {
        long long id;
        printf("Enter student ID to delete: ");
        scanf("%lld", &id); // ���� ID

        int found = 0;                         // ��¼��û�ҵ�
        for (int i = 0; i < studentCount; i++) // ��������
        {
            if (students[i].id == id)
            {
                found = 1;
                // ����������Ԫ����ǰ�ƣ�����Ҫɾ����ѧ��
                for (int j = i; j < studentCount - 1; j++)
                {
                    students[j] = students[j + 1];
                }
                studentCount--; // ѧ������-1
                printf("Student with ID %lld deleted.\n", id);
                break;
            }
        }

        if (!found) // û�ҵ�
        {
            printf("Student with ID %lld not found.\n", id);
        }
    }
    else if (strcmp(option, "name") == 0) // ѡ�˰�����ɾ��
    {
        char name[50];
        printf("Enter student name to delete: ");
        scanf("%s", name); // ��������
        // ���������Ʋ���
        int found = 0;
        for (int i = 0; i < studentCount; i++)
        {
            if (strcmp(students[i].name, name) == 0)
            {
                found = 1;
                // ����������Ԫ����ǰ�ƣ�����Ҫɾ����ѧ��
                for (int j = i; j < studentCount - 1; j++)
                {
                    students[j] = students[j + 1];
                }
                studentCount--; // ѧ������-1 
                printf("Student with name %s deleted.\n", name);
                break;
            }
        }

        if (!found) // û�ҵ�
        {
            printf("Student with name %s not found.\n", name);
        }
    }
    else // ������Ч����
    {
        printf("Invalid option! Please enter 'id' or 'name'.\n");
    }
}

// ���� ID �������޸�ѧ����Ϣ
void modify_Student()
{
    char option[10];
    printf("Modify by (id/name): "); // ѡ�� ID �� ���������޸�
    scanf("%s", option);             // ����ѡ��
    if (strcmp(option, "id") == 0)   // �� ID ����
    {
        long long id;
        printf("Enter student ID to modify: ");
        scanf("%lld", &id);

        int found = 0; // ��¼��û�ҵ�
        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].id == id)
            {
                found = 1;
                // �ҵ������������Ӧѧ������
                printf("Enter new name: ");
                scanf("%s", students[i].name);         // ��������
                printf("Enter new age: ");
                scanf("%lld", &students[i].age);       // ��������
                printf("Enter new class: ");
                scanf("%s", students[i].className);    // ����༶
                printf("Enter new grade: ");
                scanf("%lf", &students[i].grade);      // ����ɼ�
                printf("Student with ID %lld modified.\n", id);
                break;
            }
        }

        if (!found) // û�ҵ�
        {
            printf("Student with ID %lld not found.\n", id);
        }
    }
    else if (strcmp(option, "name") == 0) // ����������
    {
        char name[50];
        printf("Enter student name to modify: ");
        scanf("%s", name); // ��������

        int found = 0;
        for (int i = 0; i < studentCount; i++)
        {
            if (strcmp(students[i].name, name) == 0)
            {
                found = 1;
                // �ҵ������������Ӧѧ������
                printf("Enter new ID: ");
                scanf("%lld", &students[i].id);      // ����id
                printf("Enter new age: ");
                scanf("%lld", &students[i].age);     // ��������
                printf("Enter new class: ");
                scanf("%s", students[i].className);  // ����༶
                printf("Enter new grade: ");
                scanf("%lf", &students[i].grade);    // ����ɼ�
                printf("Student with name %s modified.\n", name);
                break;
            }
        }

        if (!found) // û�ҵ�
        {
            printf("Student with name %s not found.\n", name);
        }
    }
    else // ������Ч����
    {
        printf("Invalid option! Please enter 'id' or 'name'.\n");
    }
}

// ����ѧ����Ϣ���ļ� ����2048��Ŀ��Ӧ���� д�� txt�ļ�
void save_To_File(const char *filename)
{
    FILE *file = fopen(filename, "w"); // ��д��ģʽ���ļ�
    if (!file)                         // ����ʧ��
    {
        printf("Error opening file for saving!\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) // ���д��
    {
        fprintf(file, "%lld %s %lld %s %.2f\n", students[i].id, students[i].name, 
		        students[i].age, students[i].className, students[i].grade);
    }
    fclose(file); // �ر��ļ�
}

// ���ļ�����ѧ����Ϣ������ļ��������򴴽�һ���µ��ļ�
void load_From_File(const char *filename)
{
    FILE *file = fopen(filename, "r"); // �Զ�ȡģʽ���ļ�

    // ����ļ������ڣ��򴴽��ļ�������
    if (!file)
    {
        printf("File not found, creating new file: %s\n", filename);
        file = fopen(filename, "w"); // �������ļ�
        if (!file)                   // ����ʧ��
        {
            printf("Error creating new file!\n");
            return;
        }
        fclose(file); // �ر��ļ�
        return;
    }

    studentCount = 0; // �����ļ�����ͳ��ѧ������
    while (fscanf(file, "%lld %s %lld %s %lf", &students[studentCount].id, students[studentCount].name, &students[studentCount].age, students[studentCount].className, &students[studentCount].grade) == 5)
    {
        studentCount++; // ѧ������+1
    }
    fclose(file); // �ر��ļ�
}

// ������ѯѧ����Ϣ�����������䡢�ɼ���
void query_Students_By_Condition()
{
    char condition[50];
    printf("Enter condition (name, age, grade): "); // ѡ�������������ɼ����в�ѯ
    scanf("%s", condition);                         // ����ѡ��

    isQuerying = 1; // ����״̬Ϊ��ѯ��
    cleardevice();  // �����Ļ

    settextstyle(24, 0, "Consolas"); // ��������
    int y = 50;

    if (strcmp(condition, "name") == 0) // ��������ѯ
    {
        char name[50];
        printf("Enter name to search: ");
        scanf("%s", name);                     // ��������
        for (int i = 0; i < studentCount; i++) // ����
        {
            if (strcmp(students[i].name, name) == 0)
            {
                char info[200];
                // ��ѧ����Ϣ��ʽ��Ϊ�ַ���
                snprintf(info, sizeof(info), "ID: %lld Name: %s Age: %lld Class: %s Grade: %.2f",
                         students[i].id, students[i].name, students[i].age, students[i].className, students[i].grade);
                outtextxy(50, y, info); // ��ʾ��Ϣ
                y += 50;                // ������ʾ���
            }
        }
    }
    else if (strcmp(condition, "age") == 0) // �������ѯ
    {
        long long age;
        printf("Enter age to search: ");
        scanf("%lld", &age);                   // ��������
        for (int i = 0; i < studentCount; i++) // ����
        {
            if (students[i].age == age)
            {
                char info[200];
                // ��ѧ����Ϣ��ʽ��Ϊ�ַ���
                snprintf(info, sizeof(info), "ID: %lld Name: %s Age: %lld Class: %s Grade: %.2f",
                         students[i].id, students[i].name, students[i].age, students[i].className, students[i].grade);
                outtextxy(50, y, info); // ��ʾ��Ϣ
                y += 50;                // ������ʾ���
            }
        }
    }
    else if (strcmp(condition, "grade") == 0) // ���ɼ���ѯ
    {
        double grade;
        printf("Enter grade to search: ");
        scanf("%lf", &grade);                  // ����ɼ�
        for (int i = 0; i < studentCount; i++) // ����
        {
            if (students[i].grade == grade)
            {
                char info[200];
                // ��ѧ����Ϣ��ʽ��Ϊ�ַ���
                snprintf(info, sizeof(info), "ID: %lld Name: %s Age: %lld Class: %s Grade: %.2f",
                         students[i].id, students[i].name, students[i].age, students[i].className, students[i].grade);
                outtextxy(50, y, info); // ��ʾ��Ϣ
                y += 50;                // ������ʾ���
            }
        }
    }
    else // ������Ч����
    {
        printf("Invalid condition! Please enter 'name', 'age', or 'grade'.\n");
    }

    outtextxy(150, 535, "Press any key to continue..."); // ��ʾ��Ϣ
    _getch();                                            // �����ⰴ������
    isQuerying = 0;                                      // ��ѯ�������ָ�״̬
    draw_Students();                                     // ����ѧ����Ϣ
}

// ��������ѧ����Ϣ���ɼ������䡢�༶��������
void sort_Students()
{
    char choice[10];
    printf("Sort by (grade/age/class/name): "); // ѡ�óɼ��������༶��������������
    scanf("%s", choice);                        // ����ѡ��

    // ð������
    for (int i = 0; i < studentCount - 1; i++) // ����ÿһ��ѧ��
    {
        for (int j = i + 1; j < studentCount; j++) // �Ƚϵ�ǰѧ�������ѧ��֮��Ĵ�С��ϵ
        {
            int shouldSwap = 0; // �ж��Ƿ���Ҫ����

            if (strcmp(choice, "grade") == 0) // ���ɼ��Ӹߵ�������
            {
                shouldSwap = (students[i].grade < students[j].grade);
            }
            else if (strcmp(choice, "age") == 0) // �������С��������
            {
                shouldSwap = (students[i].age > students[j].age);
            }
            else if (strcmp(choice, "class") == 0) // ���༶����
            {
                // �Ƚϰ༶�ַ����ֵ���
                shouldSwap = (strcmp(students[i].className, students[j].className) > 0);
            }
            else if (strcmp(choice, "name") == 0) // ��������ĸ˳������
            {
                // �Ƚ������ַ����ֵ���
                shouldSwap = (strcmp(students[i].name, students[j].name) > 0);
            }
            else // ������Ч����
            {
                printf("Invalid sorting option!\n");
                return;
            }

            if (shouldSwap) // ��������
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// ��ʾ���ܽ���
void show_Intro()
{
    cleardevice();                   // ����
    settextstyle(24, 0, "Consolas"); // ��������
    // ��ʾ����
    outtextxy(100, 100, "Welcome to Student Management System");
    outtextxy(100, 160, "F1: Add Student");
    outtextxy(100, 210, "F2: Query Students by Condition");
    outtextxy(100, 260, "F3: Sort Students (by Grade, Age, Class, or Name)");
    outtextxy(100, 310, "F4: Delete Student");
    outtextxy(100, 360, "F5: Modify Student");
    outtextxy(100, 410, "Esc: Exit");
    outtextxy(100, 460, "Press any key to continue...");
    _getch();
}

// ��ѭ��
void main_loop()
{
    cleardevice();   // �����Ļ
    draw_Students(); // ����ѧ����Ϣ
    while (1)
    {
        // �����������
        if (_kbhit())
        {
            int key = _getch();
            if (key == 27) // ���� ESC �˳�
            {
                break;
            }
            else if (key == 0 || key == 224) // ��⹦�ܼ���ǰ׺
            {
                key = _getch(); // ��ȡʵ�ʵĹ��ܼ�
                if (key == 59)  // �� F1 ���ѧ����Ϣ
                {
                    add_Student();                // ���ѧ����Ϣ
                    draw_Students();              // ����ѧ����Ϣ
                    save_To_File("students.txt"); // ���浽�ļ�
                }
                else if (key == 60) // �� F2 ������ѯѧ����Ϣ
                {
                    query_Students_By_Condition();
                }
                else if (key == 61) // �� F3 ����ѧ����Ϣ
                {
                    sort_Students();              // ����ѧ����Ϣ
                    draw_Students();              // ����ѧ����Ϣ
                    save_To_File("students.txt"); // ���浽�ļ�
                }
                else if (key == 62) // �� F4 ɾ��ѧ����Ϣ
                {
                    delete_Student();             // ɾ��ѧ����Ϣ
                    draw_Students();              // ����ѧ����Ϣ
                    save_To_File("students.txt"); // ���浽�ļ�
                }
                else if (key == 63) // �� F5 �޸�ѧ����Ϣ
                {
                    modify_Student();             // �޸�ѧ����Ϣ
                    draw_Students();              // ����ѧ����Ϣ
                    save_To_File("students.txt"); // ���浽�ļ�
                }
            }
            else if (key == 72) // ���� (���ϼ�ͷ)
            {
                if (currentStartIndex > 0)
                {
                    currentStartIndex--;
                    draw_Students();
                }
            }
            else if (key == 80) // ���� (���¼�ͷ)
            {
                if (currentStartIndex < studentCount - STUDENTS_PER_PAGE)
                {
                    currentStartIndex++;
                    draw_Students();
                }
            }
        }

        // ��������������
        ExMessage msg; // �洢����¼�����Ϣ
        // ��������������
        if (peekmessage(&msg, EM_MOUSE)) // �����Ϣ�������Ƿ��������ص���Ϣ
        {
            if (msg.message == WM_MOUSEWHEEL) // ����Ƿ��ǹ����¼� 
            {
                if (msg.wheel > 0 && currentStartIndex > 0) // ���Ϲ�����ȷ���и����ѧ����Ϣ�������Ϲ��� 
                {
                    currentStartIndex--; // ��ʾ��ѧ����Ϣ�����ƶ�һ��ҳ��
                    draw_Students(); // ���½��� 
                }
                else if (msg.wheel < 0 && currentStartIndex < studentCount - STUDENTS_PER_PAGE) // ���¹���
                {
                    currentStartIndex++; // ��ʾ��ѧ����Ϣ�����ƶ�һ��ҳ��
                    draw_Students(); // ���½��� 
                }
            }
        }
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

// ��������̨�� EasyX ���ڲ�����ʾ
void setWindowsPosition()
{
    // ��ȡ��ǰ����̨���ھ��
    HWND consoleWindow = GetConsoleWindow();

    // ��ȡ EasyX ͼ�δ��ھ��
    HWND easyxWindow = GetHWnd();

    // ���崰�ڵĿ�Ⱥ͸߶�
    int consoleWidth = 500;  // ����̨���ڿ��
    int consoleHeight = 500; // ����̨���ڸ߶�
    int easyxWidth = 800;    // EasyXͼ�δ��ڿ��
    int easyxHeight = 600;   // EasyXͼ�δ��ڸ߶�

    // ���� EasyX ���ڵ�λ�ã�������Ļ���
    SetWindowPos(easyxWindow, NULL, 0, 100, easyxWidth, easyxHeight, SWP_NOZORDER | SWP_SHOWWINDOW);

    // ��������̨���ڵ�λ�ã�������Ļ�ҲࣨEasyX ���ڵ��ұߣ�
    SetWindowPos(consoleWindow, NULL, easyxWidth + 50, 100, consoleWidth, consoleHeight, SWP_NOZORDER | SWP_SHOWWINDOW);

    // �ý���ת������̨���ڲ���
    SetForegroundWindow(GetConsoleWindow());
}

// ������
int main()
{
    RunAsAdmin();                   // ��ȡ����ԱȨ�����޸Ŀ���̨��С
    initgraph(WIDTH, HEIGHT);       // ��ʼ��ͼ�δ���
    setWindowsPosition();           // ��������̨�� EasyX ���ڵ�λ��
    show_Intro();                   // ��ʾ���ܽ���
    load_From_File("students.txt"); // ����ѧ����Ϣ
    main_loop();                    // ��ʼѭ��
    closegraph();                   // �ر�ͼ�δ���
    return 0;
}
//#This program is coded by Chen Sixiang#// 
