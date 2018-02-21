#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
#include "vector"
using namespace std;

int main()
{
	vector<string> v;
	string str;
	getline(cin, str);
	string tmp = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '\n')
		{
			break;
		}
		if (str[i] != ' ')
		{
			tmp += str[i];
		}
		else
		{
			v.push_back(tmp);
			tmp = "";
		}
	}
	v.push_back(tmp);
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (i != 0)
		{
			cout << v[i] << " ";
		}
		else
		{
			cout << v[i];
		}
	}
	system("pause");
	return 0;
}