#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
#include "vector"
#include <malloc.h>
#include "math.h"
#include <algorithm>
using namespace std;

const int maxn = 1000001;
int prime[maxn];
int num = 0;
bool p[maxn] = {0};

void FindPrime(int n)
{
	for (int i = 2; i < maxn; i++)
	{
		if (p[i] == false)
		{
			prime[num++] = i;
			if (num >= n)
			{
				break;
			}
			for (int j = i + i; j < maxn; j += i)
			{
				p[j] = true;
			}
		}
	}
}
int main()
{
	int m, n;
	int count = 0;
	cout << "ÊäÈëmºÍn:" << endl;
	cin >> m >> n;
	FindPrime(n);
	for (int i = m - 1; i < n; i++)
	{
		cout << prime[i];
		count++;
		if (count % 10 != 0 && i < n)
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}
	system("pause");
	return 0;
}