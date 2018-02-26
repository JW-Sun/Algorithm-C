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
	int step;
}S,T,node;

int m, n;
char message[maxn][maxn];
bool Ife[maxn][maxn] = { false };
int xx[4] = { 0, 0, 1, -1 };
int yy[4] = { 1, -1, 0, 0 };

bool figure(int x, int y)
{
	if (x < 0 || x >= m || y < 0 || y >= n)
	{
		return false;
	}
	if (message[x][y] == '*')
	{
		return false;
	}
	if (Ife[x][y] == true)
	{
		return false;
	}
	return true;
}

int BFS()
{
	queue<Node>q;
	q.push(S);
	while (!q.empty())
	{
		Node top = q.front();
		q.pop();
		if (top.x == T.x&&top.y == T.y)
		{
			return top.step;
		}
		for (int i = 0; i < 4; i++)
		{
			int newx = top.x + xx[i];
			int newy = top.y + yy[i];
			if (figure(newx, newy))
			{
				node.x = newx;
				node.y = newy;
				node.step = top.step + 1;
				q.push(node);
				Ife[newx][newy] = true;
			}
		}
	}
	return -1;
}

int main()
{
	cout << "输入行列数：" << endl;
	cin >> m >> n;
	cout << "输入迷宫信息：" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> message[i][j];
		}
	}
	cout << "输入起点坐标：" << endl;
	cin >> S.x >> S.y ;
	cout << "输入终点坐标：" << endl;
	cin >> T.x >> T.y;
	S.step = 0;
	cout<<BFS();
	system("pause");
	return 0;
}