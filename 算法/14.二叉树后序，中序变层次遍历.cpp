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

struct node
{
	int data;
	node* lchild;
	node* rchild;
};

int pre[maxn], in[maxn], post[maxn];//ǰ�����򣬺���
int n;//������

/*����������������Ϊ��postL,postR��
��������Ϊ��inL,inR��
����create���ع������Ķ������ڵ��ַ*/

node* create(int postL, int postR, int inL, int inR)
{
	if (postL > postR)
	{
		return NULL;
	}
	node* root = new node;
	root->data = post[postR];
	int i;
	for (i = inL; i <= inR; i++)
	{
		if (in[i] == post[postR])
		{
			break;
		}
	}
	int numberOfLeft = i - inL;//������
	root->lchild = create(postL, postL + numberOfLeft - 1, inL, i - 1);
	root->rchild = create(postL + numberOfLeft,postR-1, i + 1, inR);
	return root;
}

int num = 0;

void BFS(node* root)
{
	queue<node*>q;
	q.push(root);
	while (!q.empty())
	{
		node* now = q.front();
		q.pop();
		cout << now->data;
		num++;
		if (num < n)
		{
			cout << " ";
		}
		if (now->lchild != NULL)
		{
			q.push(now->lchild);
		}
		if (now->rchild != NULL)
		{
			q.push(now->rchild);
		}
	}
}

int main()
{
	cout << "��������" << endl;
	cin >> n;
	cout << "���������" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> post[i];
	}
	cout << "���������" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
	}
	node* root = create(0, n - 1, 0, n - 1);
	BFS(root);
	system("pause");
	return 0;
}