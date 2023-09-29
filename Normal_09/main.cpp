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
//---------------------Функции и Прототипы---------------------------------------

// Составить программу, которая будет генерировать случайные числа в интервале[a;b]
// и заполнять ими двумерный массив размером 10 на 10. 
// В массиве необходимо найти номер строки с минимальным элементом.
// Поменять строки массива местами, строку с минимальным элементом и первую строку массива.
// Организовать удобный вывод на экран.


double d_rand(double min, double max, int precision);

//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------САМА ПРОГА-------------------------------------

	int a, b;

	cout << "Введите число а: ";
	cin >> a;

	cout << "Введите число b: ";
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

	cout << "\n Сгенерированный массив: \n\n";

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

	cout << "Номер строки с минимальным элементом: " << i_min + 1 << endl;
	cout << "Минимальный элемент: " << min << endl << endl;

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

	// получить случайное число как целое число с порядком precision
	value = rand() % (int)pow(10, precision);

	// ПРИМЕР ( 2 , 5 , 2 )
	// v = 194 % (int) pow (10,2)
	 // v = 194 % 100
	 // v = 94

	  // получить вещественное число
	value = min + (value / pow(10, precision)) * (max - min);

	// v = 2 + (94 / 100 ) * (5 - 2)
	 // v = 2 + (0.94) * 3
	 // v = 2 + 2,82
	 // v = 4.82         - случайное число ( от 2 до 5 с точность 2 знака после запятой )

	return value;
}
