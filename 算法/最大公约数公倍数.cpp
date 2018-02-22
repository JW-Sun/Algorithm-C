#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
#include "vector"
#include <malloc.h>
#include "math.h"
#include <algorithm>
using namespace std;

int Gongyue(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		Gongyue(b, a%b);
	}
}
int main()
{
	int a, b;
	cout << "输入两个数：" << endl;
	cin >> a >> b;
	int x=Gongyue(a, b);
	cout << "最大公约数：" << x << endl;
	cout << "最大公倍数：" << a*b / x;
	system("pause");
	return 0;
}