#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <memory> 
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <set>
#include <thread> 
#include <chrono> 
#include <algorithm>
#include <numeric>
#include <mutex>
using namespace std;
//---------------------������� � ���������---------------------------------------

// ��������� ���������, ������� ����� ������������ ��������� ����� � ���������[a;b]
// � ��������� ��� ��������� ������ �������� 10 �� 10. 
// � ������� ���������� ����� ����� ������ � ����������� ���������.
// �������� ������ ������� �������, ������ � ����������� ��������� � ������ ������ �������.
// ������������ ������� ����� �� �����.


double d_rand(double min, double max, int precision);

//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------���� �����-------------------------------------

	int a, b;

	cout << "������� ����� �: ";
	cin >> a;

	cout << "������� ����� b: ";
	cin >> b;

	double arr[10][10]{};

	double reserve_arr[10][10]{};



	double min = b + 1;
	int i_min = 0;
	bool x_moment = true;

	// ---------- RAND----------

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = d_rand(a, b, 3);
		}
	}

	cout << "\n ��������������� ������: \n\n";

	//------OUT------

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;

	//-----MIN-----

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] < min)
			{
				min = arr[i][j];
				i_min = i;
		    }
		}
	}

	cout << "����� ������ � ����������� ���������: " << i_min + 1 << endl;
	cout << "����������� �������: " << min << endl << endl;

	// ---permutation----------
	//----1 row----

	for (int j = 0; j < 10; j++)
	{
		reserve_arr[0][j] = arr[i_min][j];
	}

	//-------

	for (int i = 1; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
		
			if (i - 1 == i_min)
			{
				x_moment = false;
			}

			if (x_moment)
			{
				reserve_arr[i][j] = arr[i - 1][j];
			}
			else
			{
				reserve_arr[i][j] = arr[i][j];
			}

		}
	}

	//---result OUT--------------

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << reserve_arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;

	system("pause");

	return 0;
}


double d_rand(double min, double max, int precision)
{

	double value;

	// �������� ��������� ����� ��� ����� ����� � �������� precision
	value = rand() % (int)pow(10, precision);

	// ������ ( 2 , 5 , 2 )
	// v = 194 % (int) pow (10,2)
	 // v = 194 % 100
	 // v = 94

	  // �������� ������������ �����
	value = min + (value / pow(10, precision)) * (max - min);

	// v = 2 + (94 / 100 ) * (5 - 2)
	 // v = 2 + (0.94) * 3
	 // v = 2 + 2,82
	 // v = 4.82         - ��������� ����� ( �� 2 �� 5 � �������� 2 ����� ����� ������� )

	return value;
}
