#include <iostream>
#include <stdlib.h>
#include <windows.h> 
using namespace std;
int main()
{
	system("color f0");
	int a , b , c;
	cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
	cout << "						  ";
	cout << "�����뱾������:";
	cin >> a; 
	system("cls");
	cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
	cout << "						  ";
	cout << "�������Ŵ���:";
	cin >> b;
	system("cls");
	cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
	cout << "						  ";
	cout << "�����뱾����:"; 
    cin >> c;
	system("cls");
	int e = a + 1; 
	if(c == 8)
	{
		for(int d = 0;d < b;d++)
		{
			int f = rand()%e;
		   	if ( f != 0 && f < 10 )
			{
				int i = 0;
				for(int a = 0; a < 20; a++)
				{ 
					system("cls");
					cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
					cout << "  						        " ;
					cout << i++;
					system("cls");
				} 
		    	cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
				cout << "  						        " ;
				cout << "0" << c << "0" << f << endl;
				cout << "  						        " ;
		    	system("pause");
		    }
		   	if ( f != 0 && f >= 10 && f != 20 )
			{
				int i = 0;
				for(int a = 0; a < 20; a++)
				{ 
					system("cls");
					cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
					cout << "  						        " ;
					cout << i++;
					system("cls");
				} 
		    	cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
				cout << "  						        " ;
				cout << "0" << c << f << endl;
				cout << "  						        " ;
		    	system("pause");
		    }
	    }
    }
	if( c < 10 && c >= 0 )
	{
		for( int d = 0; d < b ; d++ )
		{
			int f = rand() % e;
		   	if ( f != 0 && f < 10 )
			{
				int i = 0;
				for(int a = 0; a < 20; a++)
				{ 
					system("cls");
					cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
					cout << "  						        " ; 
					cout << i++;
					system("cls");
				} 
		    	cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
				cout << "  						        " ;
				cout << "0" << c << "0" << f << endl;
				cout << "  						        " ;
		    	system("pause");
		    }
		   	if ( f != 0 && f >= 10 )
			{
				int i = 0;
				for(int a = 0; a < 20; a++)
				{ 
					system("cls");
					cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
					cout << "  						        " ;
					cout << i++;
					system("cls");
				} 
				cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
				cout << "  						        " ;
		    	cout << "0" << c << f << endl;
		    	cout << "  						        " ;
		    	system("pause");
		    }
	    }
    }
    else if(c > 10)
	{
		for ( int d = 0 ; d < b ; d++ )
		{	
			int f = rand() % e;
			if ( f < 10 && f != 0 )
			{
				int i = 0;
				for(int a = 0; a < 20; a++)
				{ 
					system("cls");
					cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n" ;
					cout << "  						        " ;
					cout << i++;
					system("cls");
				} 
				cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
				cout << "  						        " ;
				cout << c << "0" << f << endl;
				cout << "  						        " ;
		    	system("pause");
		    }
		   	if ( f != 0 && f >= 10 )
			{
				int i = 0;
				for(int a = 0; a < 20; a++)
				{ 
					system("cls");
					cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
					cout << "  						        " ;
					cout << i++;
					system("cls");
				} 
				cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
				cout << "  						        " ;
				cout << c << f << endl;
				cout << "  						        " ;
		    	system("pause");
		    }	
        } 
	}
	system("cls");
	cout << "\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n""\n";
	cout << "  					   " ;
	cout << "��л����ʹ�ã�"<<endl;
	cout << "  					   " ;
	cout << "���в��㣬����0820��" <<endl;
	cout << "  					   " ;
	system("pause");
	return 0;
 } 
 
