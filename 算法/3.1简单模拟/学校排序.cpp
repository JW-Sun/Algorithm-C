// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "������ţ�" << mid << endl;
	cout << "�ܷ֣�" << max << endl;
	return 0;
}