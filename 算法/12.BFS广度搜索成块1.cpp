#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <malloc.h>
#include "math.h"
#include <algorithm>
using namespace std;

const int maxn = 100;

struct Node
{
	int x, y;
}node;

int m, n;//––”Î¡–
int matrix[maxn][maxn];
bool Ife[maxn][maxn] = {false};
int xx[4] = { 0, 0, 1, -1 };
int yy[4] = { 1, -1, 0, 0 };

bool figure(int x, int y)
{
	if (x < 0 || x >= m || y < 0 || y >= n)
	{
		return false;
	}
	if (matrix[x][y] == 0 || Ife[x][y] == true)
	{
		return false;
	}
	return true;
}

void BFS(int x, int y)
{
	queue<Node>q;
	node.x = x, node.y = y;
	q.push(node);
	//Ife[x][y] == true;
	while (!q.empty())
	{
		Node top = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int newx = top.x + xx[i];
			int newy = top.y + yy[i];
			if (figure(newx, newy))
			{
				node.x = newx;
				node.y = newy;
				q.push(node);
				Ife[newx][newy] = true;
			}
		}
	}
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 1 && Ife[i][j]==false)
			{
				BFS(i, j);
				count++;
			}
		}
	}
	cout << count;
	system("pause");
	return 0;
}