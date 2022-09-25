#include <iostream>

using namespace std; 

class Matrix
{
protected:
	int rows, cols;
	float** vals;
	void memory() //выделение памяти под динамический двумерный массив
	{
		vals = new float* [rows]; //выделениe памяти под массив указателей размера rows
		for (int i = 0; i < rows; i++)
			vals[i] = new float[cols]; //выделение памяти под массив значений размера cols
	}
public:
	Matrix()
	{
		cout << "Matrix()" << endl;
		rows = 1; 
		cols = 1;
		memory();
		vals[0][0] = 0;
	}
	Matrix(int r, int c)
		: rows(r), cols(c)
	{
		cout << "Matrix(int r, int c)" << endl;
		memory();
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				vals[i][j] = 0;
	}
	Matrix(Matrix& m)
	{
		cout << "Matrix(Matrix& m)" << endl;
		rows = m.rows;
		cols = m.cols;
		memory();
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				vals[i][j] = m.vals[i][j];
		
	}
	~Matrix()
	{
		cout << "~Matrix()" << endl;
		for (int i = 0; i < rows; i++)
			delete[] vals[i];
		delete[] vals;
	}
	void fill()
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				cin >> vals[i][j];
	}
	virtual void print()
	{
		cout << "This is a rectangular matrix:" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				cout << vals[i][j] << " ";
			cout << endl;
		}
	}
	void random_fill()
	{
		srand(time(0));
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				vals[i][j] = 1 + rand() % 100;
	}
	Matrix transpose()
	{
		Matrix res(cols, rows);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				res.vals[j][i] = vals[i][j];
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				vals[i][j] = res.vals[i][j];
		return *this;
	}
};

class SquareMatrix : public Matrix {
private:
	SquareMatrix minor(int r, int c);
	float AlgCompl(int r, int c)
	{
		int sign;
		if ((r + c) % 2 == 0) sign = 1;
		else sign = -1;
		return sign * minor(r, c).determinant();
	}
public:
	SquareMatrix() : Matrix() 
	{
		cout << "SquareMatrix()" << endl;
	}
	SquareMatrix(int n) : Matrix(n, n)
	{
		cout << "SquareMatrix(int n)" << endl;
	}
	SquareMatrix(const SquareMatrix& sm)
	{
		
		rows = sm.rows;
		cols = sm.rows;
		memory();
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				vals[i][j] = sm.vals[i][j];
		cout << "SquareMatrix(const Matrix& sm)" << endl;
	}
	~SquareMatrix() 
	{
		cout << "~SquareMatrix()" << endl;
	}
	void print()
	{
		cout << "This is a square matrix:" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				cout << vals[i][j] << " ";
			cout << endl;
		}
	}
	float determinant()
	{
		float det = 0;
		if (rows == 1) det = vals[0][0];
		else if (rows == 2)
			det = vals[0][0] * vals[1][1] - vals[0][1] * vals[1][0];
		else
		{
			for (int i = 0; i < rows; i++)
				det += vals[0][i] * AlgCompl(1, i + 1);
		}
		return det;
	}
};

SquareMatrix SquareMatrix::minor(int r, int c)
{
	if (r <= rows && c <= cols)
	{
		int _rows = 0, _cols = 0;
		SquareMatrix tmp(rows - 1);
		for (int i = 0; i < rows; i++)
		{
			if (i == r - 1) continue;
			else {
				for (int j = 0; j < rows; j++)
				{
					if (j == c - 1) continue;
					else
					{
						tmp.vals[_rows][_cols] = vals[i][j];
						_cols++;
					}
				}
			}
			_rows++;
			_cols = 0;
		}
		return tmp;
	}
}

int main()
{
	Matrix m1(2, 3);
	m1.random_fill();
	SquareMatrix m(3);
	m.random_fill();
	m1.print();
	m.print();
	
	

}