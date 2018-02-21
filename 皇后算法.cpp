#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
#include "vector"
#include <malloc.h>
#include "math.h"
using namespace std;

int *p;//第i行皇后所在的列数
int count;//解决方法数
int queens;//皇后的数目

bool figure(int n)//第n行是否放置皇后
{
	for (int i = 0; i < n; i++)
	{
		if (p[i] == p[n])
			return false;
		if (abs(p[i] - p[n]) == abs(i - n))
			return false;
	}
	return true;
}

void set(int n = 0)//从n数组下标列开始放置
{
	if (queens == n)
	{
		for (int i = 0; i < queens; i++)
		{
			for (int j = 0; j < queens; j++)
			{
				if (j == p[i])
				{
					cout << j + 1;
				}
				else
				{
					cout << "*";
				}
			}
			cout << endl;
		}
		for (int a = 0; a < queens; a++)
		{
			cout << "p[" << a << "]=" << p[a] << endl;
		}
		cout << endl;
		return;
	}
	else
	{
		for (int i = 0; i < queens; i++)//放在第i列
		{
			p[n] = i;
			if (figure(n))
			{
				set(n + 1);
			}
		}
	}
}

int main()
{
	cout << "皇后数：" << endl;
	cin >> queens;
	p = new int[queens];
	set();
	cout << "set done" << endl;
	system("pause");
	return 0;
}