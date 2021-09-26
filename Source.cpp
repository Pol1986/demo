#include<iostream>
#include<algorithm>
#include<iterator>
#include<time.h>
#include"Matrix.h"

using namespace std;




	int size = 10;

	void print(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void create(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 10 - 1;
		}
		
	}
	template<typename T>
	void MaxEl(T arr[], int size)
	{
		T maxVal = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > maxVal)
				maxVal = arr[i];
		}
		cout << "Максимальный элемент = " << maxVal << endl;
	}

	template<typename T>
	void MinEl(T arr[], int size)
	{
		T minVal = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] < minVal)
				minVal = arr[i];
		}
		cout << "Минимальный элемент = " << minVal << endl;
	}

	template<typename T>
	void sort(T arr[], int size)
	{
		T tmp;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; ++j)
			{
				if (arr[j] < arr[j + 1])
				{
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}
		
	template<typename T>
	int Bi_Search(T arr[], int size,int key)
	{
		int left = 0;
		int rigth = size;
		int midd;
		while (left <= rigth)
		{
			midd = left + (rigth - left) / 2;

			if (key < arr[midd])
				rigth = midd - 1;
			else if (key > arr[midd])
				left = midd + 1;
			else
				return midd;
		}
		return -1;

		
	}



	template<typename T,size_t S>
	void Replace(T(&arr)[S], T val1, T val2)
	{
		replace(begin(arr), end(arr), val1, val2);
	}


	

	int main()
	{
		setlocale(LC_ALL, "Rus");
		srand(time(NULL));


		///*int mass1[10];
		//
		//create(mass1, 10);
  //      print(mass1, 10);
		//MaxEl(mass1, 10);
		//MinEl(mass1, 10);
		//sort(mass1, 10);
		//print(mass1, 10);
		//cout << "-----------------------------------------------------------" << endl;*/
		//
		//
		//int mass[10];
		//int key = 0;
		//create(mass, 10);
		//print(mass, 10);
		////sort(mass, 10);
		////print(mass, 10);
		//cout << " Введите число: " << endl;
		//cin >> key;

		//if( Bi_Search(mass, 10, key)==-1)
		//	cout << " Заданного числа нет в массиве " << endl;
		//else
		//	cout << " Число находится в ячейке - " << Bi_Search(mass, 10, key)+1 << endl;
		//

		//cout << "-----------------------------------------------------------------" << endl;

		//int Array[]{ 2,5,7,8,9,4,0 };
		//Replace(Array, 8, 9);
		//print(Array, 7);

		const int Size = 10;

		Matrix<int>arr(5, 5);

		Matrix<int>M(2,2);
		Matrix<int>M1(2, 2);
		
		M.createMass();
        M.printMass();
		cout << "-----------------------------------" << endl;
		M1.createMass();
		M1.printMass();

        M = M + M1;
	    M.printMass();

		M = M - M1;
		M.printMass();

		M = M * M1;
		M.printMass();

		M = M / M1;
		M.printMass();


		return 0;
	}
		




