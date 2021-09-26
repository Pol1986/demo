#pragma once
#include <iostream>
#include <time.h>

using namespace std;
template<class Type>
class Matrix
{
	Type **mass;
	int col;
	int row;

public:
	Matrix() :mass(nullptr), col(0), row(0) {}

	Matrix(int col, int row);

	Matrix(const Matrix& other);

	/*friend istream& operator>>(istream &is, Matrix<Type> &matrix)
	{
		for (int i = 0; i < matrix.col; ++i)
		{
			for (int j = 0; j < matrix.row; ++j)
			{
				is >> matrix.mass[i][j];
				return is;
			}
		}
	}*/

	Matrix& operator=(const Matrix& other);

	void setMass(int col, int row, Type val);

	Matrix<Type>operator+(Matrix<Type> M);

	Matrix<Type>operator-(Matrix<Type> M);

	Matrix<Type>operator*(Matrix<Type> M);

	Matrix<Type>operator/(Matrix<Type> M);

	void createMass();

	void printMass();

	~Matrix();
};


template<class Type>
Matrix<Type>::Matrix(int col, int row)
{
	this->col = col;
	this->row = row;
	mass = new Type*[col];
	for (int i = 0; i < col; i++)
	{
		//cout << "[" << j << "]: ";
		//cin >> mass[i] >> endl;
		mass[i] = new Type[row];
		for (int j = 0; j < row; ++j)
		{
			//cout << "[" << j << "]: ";
			//cin >> mass[j] >> endl;
			mass[i][j] = 0;
		}
	}
}

template<class Type>
Matrix<Type>::Matrix(const Matrix& other)
{
	this->row = other.row;
	this->col = other.col;
	mass = new Type*[col];
	for (int i = 0; i < col; ++i)
	{
		mass[i] = new Type[row];
		for (int j = 0; j < row; ++j)
		{
			this->mass[i][j] = other.mass[i][j];
		}
	}

}

template<class Type>
Matrix<Type>& Matrix<Type>::operator=(const Matrix<Type> & other)
{
	if (row > 0)
	{
		for (int i = 0; i < col; i++)
		{
			delete[]mass[i];

		}
	}
	if (col > 0)
	{
		delete[]mass;
	}

	this->row = other.row;
	this->col = other.col;
	mass = new Type*[col];
	for (int i = 0; i < col; ++i)
	{
		mass[i] = new Type[row];
		for (int j = 0; j < row; ++j)
		{
			this->mass[i][j] = other.mass[i][j];
		}
	}
	return *this;
}


template<class Type>
void Matrix<Type>::setMass(int col, int row, Type val)
{
	mass[col][row] = val;
}

template<class Type>
 Matrix<Type> Matrix<Type>::operator+(Matrix<Type> M)
{
	Matrix<Type> temp(col,row);
	for (int i = 0; i < col; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			temp.mass[i][j] = mass[i][j] + M.mass[i][j];
		}
		cout << endl;
	}
	return temp;
}

 template<class Type>
 Matrix<Type> Matrix<Type>::operator-(Matrix<Type> M)
 {
	 Matrix<Type>temp(col,row);
	 for (int i = 0; i < col; ++i)
	 {
		 for (int j = 0; j < row; ++j)
		 {
			 temp.mass[i][j] = mass[i][j] - M.mass[i][j];
		 }
		 cout << endl;
	 }
	 return temp;
 }

 template<class Type>
 Matrix<Type> Matrix<Type>::operator*(Matrix<Type> M)
 {
	 Matrix<Type>temp(col, row);
	 for (int i = 0; i < col; ++i)
	 {
		 for (int j = 0; j < row; ++j)
		 {
			 temp.mass[i][j] = mass[i][j] * M.mass[i][j];
		 }
		 cout << endl;
	 }
	 return temp;
 }

 template<class Type>
 Matrix<Type> Matrix<Type>::operator/(Matrix<Type> M)
 {
	 Matrix<Type>temp(col,row);
	 for (int i = 0; i < col; ++i)
	 {
		 for (int j = 0; j < row; ++j)
		 {
			 temp.mass[i][j] = mass[i][j] / M.mass[i][j];
		 }
		 cout << endl;
	 }
	 return temp;
 }



template<class Type>
void Matrix<Type>::createMass()
{
	for (int i = 0; i < col; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			mass[i][j] = rand() % 10 - 1;
		}
	}
}

template<class Type>
void Matrix<Type>::printMass()
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << mass[i][j] << " ";
		}
		cout << endl;
	}
}

template<class Type>
Matrix<Type>::~Matrix()
{
	if (row > 0)
	{
		for (int i = 0; i < col; i++)
		{
			delete[]mass[i];
		}
		if (col > 0)
			delete[]mass;
	}
}


