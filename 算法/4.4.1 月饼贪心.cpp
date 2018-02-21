#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
#include "vector"
#include <malloc.h>
#include "math.h"
#include <algorithm>
using namespace std;

struct mooncake
{
	double store;
	double sell;
	double price;
}cake[1000];

bool cmp(mooncake a, mooncake b)
{
	return a.price > b.price;
}
int main()
{
	int n;
	double D;
	cout << "输入种类数：" << endl;
	cin >> n;
	cout << "最大需求量：" << endl;
	cin >> D;
	for (int i = 0; i < n; i++)
	{
		cin >> cake[i].store;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> cake[i].sell;
		cake[i].price = cake[i].sell / cake[i].store;
	}
	sort(cake, cake + n, cmp);
	double get = 0;
	for (int i = 0; i < n; i++)
	{
		if (cake[i].store < D)
		{
			D -= cake[i].store;
			get += cake[i].sell;
		}
		else
		{
			get += cake[i].price*D;
			break;
		}
	}
	cout << get << endl;
	system("pause");
	return 0;
}