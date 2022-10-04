#include <iostream>
#include <conio.h>
using namespace std;

class Circle
{
private:
	int r;
	float pi = 3.14159;
public:
	Circle() //конструктор без параметров
	{
		r = 0;
		cout << "Circle()" << " r = " << r << endl;
	}
	Circle(int _r) //конструктор с параметром 
	{
		r = _r;
		cout << "Circle(int _r)" << " r = " << r << endl;
	}
	Circle(Circle& c) //конструктор копирования
	{
		r = c.r;
		cout << "Circle(Circle& c)" << " r = " << r << endl;
	}
	~Circle() //деструктор
	{
		cout << "~Circle()" << " r = " << r << endl;
	}
	void expand(int dr)
	{
		r += dr;
	}
	float area();
};

float Circle::area()
{
	return pi * r * r;
}

int main()
{
	//статически создаваемые объекты
	Circle c1;
	Circle c2(5);
	Circle c3 = c2;
	//динамически создаваемые объекты
	Circle *c4 = new Circle;
	Circle* c5 = new Circle(6);
	Circle* c6 = new Circle(*c5);
	//удаление динамически созданных объектов
	delete c4;
	delete c5;
	delete c6;
	
	return 0;
}
