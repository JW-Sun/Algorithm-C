#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
#include "vector"
#include <malloc.h>
#include "math.h"
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

void toArray(int n, int num[])
{
	for (int i = 0; i < 4; i++)
	{
		num[i] = n % 10;
		n = n / 10;
	}
}

int toNumber(int num[])
{
	int a = 0;
	for (int i = 0; i < 4; i++)
	{
		a = a*10 + num[i];
	}
	return a;
}

int main()
{
	int n, min, max;
	cout << "输入一个数：";
	cin >> n;
	int num[5];
	while (1)
	{
		toArray(n, num);
		sort(num, num + 4);
		min = toNumber(num);
		sort(num, num + 4, cmp);
		max = toNumber(num);
		n = max - min;
		cout << max << "-" << min << "=" << n << endl;
		if (n == 0 || n == 6174)
		{
			break;
		}
	}
	system("pause");
	return 0;
}