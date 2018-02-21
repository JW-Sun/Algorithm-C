// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
using namespace std;

int main()
{
	int step = 0;
	int n;
	cin >> n;
	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n = (3 * n + 1) / 2;
		}
		step++;
	}
	cout << step;
	return 0;
}