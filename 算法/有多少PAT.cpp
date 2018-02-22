#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
#include "vector"
#include <malloc.h>
#include "math.h"
#include <algorithm>
using namespace std;

const int MAX = 100010;
const int MOD = 1000000007;
char str[MAX];
int leftNumP[MAX] = { 0 };

int main()
{
	gets(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (i>0)
		{
			leftNumP[i] = leftNumP[i - 1];
		}
		if (str[i] == 'P')
		{
			leftNumP[i]++;
		}
	}
	int ans = 0, rightNumT = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (str[i] == 'T')
		{
			rightNumT++;
		}
		else if (str[i] == 'A')
		{
			ans = (ans + leftNumP[i] * rightNumT) % MOD;
		}
	}
	cout << ans;
	system("pause");
	return 0;
}