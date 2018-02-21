// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
using namespace std;

int s[10000] = { 0 };
int main()
{
	int n, id, score;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> id >> score;
		s[id] += score;
	}
	int mid, max = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i]>max)
		{
			max = s[i];
			mid = i;
		}
	}
	cout << "最大的序号：" << mid << endl;
	cout << "总分：" << max << endl;
	return 0;
}