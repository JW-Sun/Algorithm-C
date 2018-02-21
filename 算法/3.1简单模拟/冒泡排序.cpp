// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
using namespace std;

int main()
{
	int a[5] = { 4, 2, 1, 5, 3 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5 - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout <<  a[i] << " ";
	}
}