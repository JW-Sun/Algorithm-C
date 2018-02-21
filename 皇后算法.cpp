#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
#include "vector"
#include <malloc.h>
#include "math.h"
using namespace std;

int *p;//��i�лʺ����ڵ�����
int count;//���������
int queens;//�ʺ����Ŀ

bool figure(int n)//��n���Ƿ���ûʺ�
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

void set(int n = 0)//��n�����±��п�ʼ����
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
		for (int i = 0; i < queens; i++)//���ڵ�i��
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
	cout << "�ʺ�����" << endl;
	cin >> queens;
	p = new int[queens];
	set();
	cout << "set done" << endl;
	system("pause");
	return 0;
}