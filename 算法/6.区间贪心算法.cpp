#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
#include "vector"
#include <malloc.h>
#include "math.h"
#include <algorithm>
using namespace std;

struct A
	{
		int x, y;
	}aa[100];
bool cmp(A a, A b)
{
	if (a.x != b.x)
	{
		return a.x > b.x;
	}
	else
	{
		return a.y < b.y;
	}
}

int main()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> aa[i].x >> aa[i].y;
		}
		sort(aa, aa + n, cmp);
		int ans = 1;
		int lastx = aa[0].x;
		for (int i = 1; i < n; i++)
		{
			if (aa[i].y <= lastx)
			{
				lastx = aa[i].x;
				ans++;
			}
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}