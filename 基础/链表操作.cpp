// study.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

struct node
{
	int data;
	node *next;
};

int create(node *h)
{
	node *p, *s;
	int a;
	p = h;
	cout << "从大到小输入：";
	cin >> a;
	while (a != 0)
	{
		if (!(s = (node*)malloc(sizeof(node))))
		{
			return 1;
		}
		else
		{
			s->data = a;
			s->next = p->next;
			p->next = s;
			cout << "请输入结点值：";
			cin >> a;
		}
	}
	return 0;
}

void showList(node *h)
{
	node *q;
	q = h->next;
	cout << "展示链表：";
	while (q != NULL)
	{
		cout << "->" << q->data;
		q = q->next;
	}
	cout << endl;
}

int len(node *h)
{
	node *p;
	p = h->next;
	int i = 0;
	while (p)
	{
		++i;
		p = p->next;
	}
	return i;
}

int insert(node *h)
{
	int a;
	node *s, *p;
	p = h;
	cout << "插入值：";
	cin >> a;
	if (!(s = (node*)malloc(sizeof(node))))
		return 1;
	else
	{
		s->data = a;
		while (p->next&&p->next->data<a)
		{
			p = p->next;
		}
		s->next = p->next;
		p->next = s;
	}
	return 0;
}

int del(node *h)
{
	node *p, *q;
	p = h;
	int i;
	cout << "输入要删除的位置：";
	cin >> i;
	if (i <= 0 || i>len(h))
	{
		return 1;
	}
	else
	{
		for (int j = 1; j < i; j++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		free(q);
	}
	return 1;
}
void main()
{
	node *head;
	if (!(head = (node*)malloc(sizeof(node))))
		return;
	else
	{
		head->next = NULL;
		create(head);
		showList(head);
		cout << "链表长度：" << len(head) << endl;
		insert(head);
		showList(head);
		del(head);
		showList(head);
	}
}