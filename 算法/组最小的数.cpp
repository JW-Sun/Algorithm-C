#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
#include "vector"
#include <malloc.h>
#include "math.h"
#include <algorithm>
using namespace std;



int main()
{
	int count[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> count[i];
	}
	for (int i = 1; i < 10; i++)
	{
		if (count[i]>0)
		{
			cout << i;
			count[i]--;
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			cout << i;
		}
	}
	system("pause");
	return 0;
}