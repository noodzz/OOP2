#include <iostream>
#include <conio.h>
using namespace std;

class Circle
{
private:
	int r;
public:
	Circle() //конструктор без параметров
	{
		cout << "Circle()" << endl;
		r = 0;
	}
	Circle(int r) //конструктор с параметром 
	{
		cout << "Circle(int r)" << endl;
		this->r = r;
	}
	Circle(Circle& c) //конструктор копирования
	{
		cout << "Circle(Circle& c)" << endl;
		r = c.r;
	}
	~Circle() //деструктор
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
	Circle *c4 = new Circle;
	Circle* c5 = new Circle(5);
	Circle* c6 = new Circle(*c5);

	delete c4;
	delete c5;
	delete c6;
	
	return 0;
}
