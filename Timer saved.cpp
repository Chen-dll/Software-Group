//#This program is coded by Chen Sixiang#// 
#include <bits/stdc++.h>
#include <conio.h>//getch() 
#include <windows.h>//Sleep()

using namespace std;

string int2string(int i);
string s1 = int2string(10), s2 = "2021-6-18 08:00:00";//�����п�ʱ�� 

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
//  cout << "\n\n\n\n\n\n\n\n\n\n";
//	cout << "\t\t\t\t\t  ";
//  cout << "��ǰʱ��:      " << s1 << endl << "\t\t\t\t\t  " 
//	<< "2021�п�ʱ��:  " << s2 << endl <<"\t\t\t\t\t  " << "ʣ������:      " << dif;
//  CONSOLE_FONT_INFOEX cfi;
//	cfi.cbSize = sizeof cfi;
//	cfi.nFont = 0;
//	cfi.dwFontSize.X = 0;
//	cfi.dwFontSize.Y = 20;
//	cfi.FontFamily = FF_DONTCARE;
//	cfi.FontWeight = FW_NORMAL; 
//	wcscpy(cfi.FaceName, L"Consolas");
//	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system("cls"); 
	cout << "��ǰʱ��:      " << s1 << endl;
	for(int i = 0; i <= s2.length(); i++)//ϸ�� 
	{
		if(s2[i] == '-') break;
		cout << s2[i];
	}
	cout << "�п�ʱ��:  " << s2 << endl << "ʣ������:      " << dif;
	cout << "\n\n\n\n\n\n\n\n\n\n\n" << "\t\t\t\t\t\t" << days << "��" << hours << "Сʱ" << minutes << "����" 
	<< seconds << "��";
    Sleep(1000); 
}

int main()
{	
	char a;
	cout << "��������п�ʱ�䲻��2021-6-18 08:00:00";
	cout << endl << "�밴�¿ո��,�ٰ��س�";
	cout << endl << "��������п�ʱ����2021-6-18 08:00:00";
	cout << endl << "��ֱ�Ӱ��»س���"; 
	a = getchar();
	if(a == ' ') 
	{
		cin.ignore();//��ֹgetline()�����Ե� 
		system("cls"); 
		cout << "�����������п�ʱ��" << endl << "��ʽΪ:��-��-�� ʱ:��:��" << endl 
		<< "��������2021��10��10��10ʱ10��10���п�" << endl << "��ô������" << "2021-10-10 10:10:10" << endl;
		getline(cin,s2);//cin,printf�����ո�ֱ�ӷ��� 
		while(1) print();
	}
    else while(1) print();
	 return 0;
}
/*#This program is coded by Chen Sixiang#*/ 
