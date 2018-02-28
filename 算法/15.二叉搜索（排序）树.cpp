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

struct node
{
	int data;
	node* lchild;
	node* rchild;
};

void Insert(node* &root, int data)
{
	if (root == NULL)
	{
		root = new node;
		root->data = data;
		root->lchild = NULL;
		root->rchild = NULL;
		return;
	}
	if (data < root->data)
	{
		Insert(root->lchild, data);
	}
	else
	{
		Insert(root->rchild, data);
	}
}

void PreOrder(node* root, vector<int>&v)
{
	if (root == NULL)
	{
		return;
	}
	v.push_back(root->data);
	PreOrder(root->lchild, v);
	PreOrder(root->rchild, v);
}

void PreOrderMirror(node* root, vector<int>&v)
{
	if (root == NULL)return;
	v.push_back(root->data);
	PreOrderMirror(root->rchild, v);
	PreOrderMirror(root->lchild, v);
}

void PostOrder(node* root, vector<int>&v)
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->lchild, v);
	PostOrder(root->rchild, v);
	v.push_back(root->data);
}

void PostOrderMirror(node* root, vector<int>&v)
{
	if (root == NULL)
	{
		return;
	}
	PostOrderMirror(root->rchild, v);
	PostOrderMirror(root->lchild, v);
	v.push_back(root->data);
}

vector<int>origin, pre, prem, post, postm;


int main()
{
	int n, data;
	node* root = NULL;
	cout << "二叉树结点个数：";
	cin >> n;
	cout << "输入结点：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		origin.push_back(data);
		Insert(root, data);
	}
	PreOrder(root, pre);
	PreOrderMirror(root, prem);
	PostOrder(root, post);
	PostOrderMirror(root, postm);
	if (origin == pre)
	{
		cout << "YES" << endl;
		for (int i = 0; i < post.size(); i++)
		{
			cout << post[i];
			if (i < post.size() - 1)
			{
				cout << " ";
			}
		}
	}
	else if (origin == prem)
	{
		cout << "YES" << endl;
		for (int i = 0; i < postm.size(); i++)
		{
			cout << postm[i];
			if (i < postm.size() - 1)
			{
				cout << " ";
			}
		}
	}
	else
	{
		cout << "NO" << endl;
	}
	system("pause");
	return 0;
}