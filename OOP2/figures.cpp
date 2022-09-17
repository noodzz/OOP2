#include <iostream>
#include <conio.h>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point()
	{
		cout << "Point()" << endl;
		x = 0;
		y = 0;
	}
	Point(int x, int y)
	{
		cout << "Point(int x, int y)" << endl;
		this->x = x;
		this->y = y;
	}
	Point(Point& p)
	{
		cout << "Point(Point &p)" << endl;
		x = p.x;
		y = p.y;
	}
	~Point()
	{
		cout << x << " " << y << endl;
		cout << "~Point()" << endl;
	}
};


class Triangle {
protected:
	Point* A;
	Point* B;
	Point* C;
public:
	Triangle()
	{
		cout << "Triangle()" << endl;
		A = new Point;
		B = new Point;
		C = new Point;
	}
	Triangle(Point a, Point b, Point c)
	{
		cout << "Triangle(Point a, Point b, Point c)" << endl;
		A = new Point(a);
		B = new Point(b);
		C = new Point(c);
	}
	Triangle(Triangle& t)
	{
		cout << "Triangle(Triangle& t)" << endl;
		A = new Point(*(t.A));
		B = new Point(*(t.B));
		C = new Point(*(t.C));
	}
	~Triangle()
	{
		cout << "~Triangle()" << endl;
		delete A;
		delete B;
		delete C;
	}

};

int main()
{

	return 0;
}