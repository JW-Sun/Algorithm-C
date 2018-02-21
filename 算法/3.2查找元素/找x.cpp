// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
using namespace std;

int a[210];
int main()
{
	int n;
	cout << "输入数的个数：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "输入第" << i+1 << "个数:";
		cin >> a[i];
	}
	cout << "在输入将要查找的一个值：" << endl;
	int x;
	cin >> x;
	int j;
	for (j = 0; j < n; j++)
	{
		if (a[j] == x)
		{
			cout << "数组的序号为：" << j << endl;
			break;
		}
	}
	if (j == n)
	{
		cout << "-1" << endl;
	}
	return 0;
}