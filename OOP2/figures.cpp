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
