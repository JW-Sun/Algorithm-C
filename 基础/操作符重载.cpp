// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class A
{
	double x, y, z;
public:
	A(double xx=0, double yy=0, double zz=0)
	{
		x = xx;
		y = yy;
		z = zz;
	}
	void show()
	{
		cout << "x:" << x << ",y:" << y << ",z:" << z << endl;
	}
	A operator+(A a);
	friend A operator++(A &a);
};

A A::operator+(A a)
{
	A aa = *this;
	aa.x += a.x;
	aa.y += a.y;
	aa.z += a.z;
	return aa;
}

A operator++(A &a)
{
	a.x++;
	a.y++;
	a.z++;
	return a;
}

int main()
{
	A a1(1, 2, 3);
	A a2(16, 7, 5);
	A a3,a4;
	a1.show();
	a2.show();
	a3 = a1 + a2;
	a3.show();
	a4 = ++a2;
	a4.show();
	return 0;
}