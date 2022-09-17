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
		this->x = x;
		this->y = y;
		cout << x << " " << y << " Point(int x, int y)" << endl;

	}
	Point(Point& p)
	{
	
		x = p.x;
		y = p.y;
		cout << x << " " << y << " Point(Point &p)" << endl;
	}
	~Point()
	{
		cout << x << " " << y << " ~Point()" << endl;
	}
};

class Line {
private:
	Point A;
	Point B;
public:
	Line() : A(), B()
	{
		cout << "Line()" << endl;
	}
	Line(int x1, int y1, int x2, int y2)
		:A(x1, y1), B(x2, y2)
	{
		cout << "Line(Point a, Point b)" << endl;

	}
	Line(Line& l)
		:A(l.A), B(l.B)
	{
		cout << "Line(Line& l)" << endl;
	}
	~Line()
	{
		cout << "~Line()" << endl;
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

	Line l1(1, 2, 3, 4);
	//Triangle* t1 = new Triangle();
	//Triangle* t2 = new Triangle(*t1);
	//delete t1;
	//delete t2;
	return 0;
}