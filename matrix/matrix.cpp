#include <iostream>

using namespace std; 

class Matrix
{
protected:
	int rows, cols;
	float** vals;
	void memory()
	{
		vals = new float* [rows];
		for (int i = 0; i < rows; i++)
			vals[i] = new float[cols];
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
	

};
int main()
{
	

}