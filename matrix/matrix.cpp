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
		rows = 1; 
		cols = 1;
		vals[0] = 0;
	}
	Matrix(int r, int c)
		: rows(r), cols(c)
	{
		memory();
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				vals[i][j] = 0;
	}
	Matrix(Matrix& m)
	{
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
		return res;
	}
};
int main()
{
	

}