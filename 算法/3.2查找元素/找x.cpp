// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "�������ĸ�����" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "�����" << i+1 << "����:";
		cin >> a[i];
	}
	cout << "�����뽫Ҫ���ҵ�һ��ֵ��" << endl;
	int x;
	cin >> x;
	int j;
	for (j = 0; j < n; j++)
	{
		if (a[j] == x)
		{
			cout << "��������Ϊ��" << j << endl;
			break;
		}
	}
	if (j == n)
	{
		cout << "-1" << endl;
	}
	return 0;
}