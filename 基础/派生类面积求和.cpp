// study.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

class shape
{
public:
	virtual float area() = 0;
};

class rectangle :public shape
{
	float width, height;
public:
	rectangle(float w, float h)
	{
		width = w;
		height = h;
	}
	void show()
	{
		cout << "width:" << width << "," << "height:" << height << endl;
		cout << "area:" << area() << endl;
	}
	float area()
	{
		return width*height;
	}
};

class triangle :public shape
{
	float a, b, c;
public:
	triangle(float aa, float bb, float cc)
	{
		a = aa;
		b = bb;
		c = cc;
	}
	float show()
	{
		cout << "a:" << a << ",b:" << b << ",c:" << c << endl;
		cout << "area:" << area() << endl;
	}
	float area()
	{
		float s = (a + b + c) / 2;
		return sqrt(s*(s - a)*(s - b)*(s - c));
	}
};

float total(shape *s[], int n)
{
	float sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum += s[i]->area();
	}
	return sum;
}
void main()
{
	float w, h, aa, bb, cc;
	cout << "�����������ε������ߣ�" << endl;
	cin >> aa >> bb >> cc;
	triangle t(aa, bb, cc);
	cout << "��������εĳ��Ϳ�" << endl;
	cin >> w >> h;
	rectangle r(w, h);
	shape *p[2];
	p[0] = &t;
	p[1] = &r;
	cout << "����ܺͣ�" << total(p, 2) << endl;
}