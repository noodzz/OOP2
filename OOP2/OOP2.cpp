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
		cout << r << " ~Circle()" << endl;
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
	Circle* c5 = new Circle(5);
	Circle* c6 = new Circle(*c5);
	cout << c5->area() << endl;
	//удаление динамически созданных объектов
	delete c4;
	delete c5;
	delete c6;
	
	c1.expand(4);
	return 0;
}
