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
	void print()
	{
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
};

int main()
{
	SquareMatrix m(2);
	m.random_fill();
	m.print();
	m.transpose();
	m.print();

}