#include <iostream>
#include <conio.h>
using namespace std;

class Circle
{
private:
	int r;
public:
	Circle()
	{
		cout << "Circle()" << endl;
		r = 0;
	}
	Circle(int r)
	{
		cout << "Circle(int r)" << endl;
		this->r = r;
	}
	Circle(Circle& c)
	{
		cout << "Circle(Circle& c)" << endl;
		r = c.r;
	}
	~Circle()
	{
		cout << r << endl;
		cout << "~Circle()" << endl;
	}
};

int main()
{
	Circle c1;
	Circle c2(5);
	Circle c3 = c2;

	
	return 0;
}
