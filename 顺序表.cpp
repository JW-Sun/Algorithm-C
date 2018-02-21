#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"
using namespace std;

static int l = 0;
typedef struct list
{
	int a[100];
	int length;
}A;

void init(A &L)
{
	L.length = 0;
}

void createList(A &L)
{
	cout << "�������"<<endl;
	cin >> L.length;
	cout << "����˳����Ԫ�أ�"<<endl;
	for (int i = 0; i < L.length; i++)
	{
		cin >> L.a[i];
		l++;
		if (getchar() == '\n')
			break;
	}
}

void Traverse(A &L)
{
	for (int i = 0; i < L.length; i++)
	{
		if (i % 10 == 0)
		{
			cout << endl;
		}
		cout << L.a[i] << " ";
	}
}

int Insert(A &L, int i, int e)
{
	if (i<0 || i>L.length)
	{
		return 0;
	}
	if(L.length>=100)
	{
		exit(OVERFLOW);
	}
	for (int j = L.length; j > i-1; j--)
	{
		L.a[j] = L.a[j - 1];
	}	
	L.a[i - 1] = e;	
	L.length++;	
	return 0;
	
}

void findByValue(A &L, int m1)
{
	static int p = 1;
	for (int i = 0; i < L.length; i++)
	{
		if (L.a[i] != m1)
		{
			continue;
		}
		cout << "�ҵ����ֵ�λ�þ��ǣ�" << i << endl;
		p = 0;
	}
	if (p)
	{
		cout << "����ʧ�ܡ�" << endl;
	}
}

void symmertry(A &L)
{
	int p = 0;
	for (int i = 0; i < (L.length) / 2; i++)
	{
		if (L.a[i] == L.a[L.length - 1 - i])
		{
			p = 1;
		}
		if (p)
		{
			cout << "�ǶԳƵġ�";
		}
		else
		{
			cout << "���ǶԳƵġ�";
		}
	}
}

void MaopaoSort(A &L)
{
	for (int i = 0; i < L.length - 1; i++)
	{
		for (int j = 0; j < L.length - i - 1; j++)
		{
			if (L.a[j]>L.a[j + 1])
			{
				int t = L.a[j];
				L.a[j] = L.a[j + 1];
				L.a[j + 1] = t;
			}
		}
	}
}

void JiOu(A &L)
{
	int temp;
	int i = 0;
	int flag = 0;
	while (L.a[i] % 2 == 0 && i < L.length)
	{
		i++;
		flag = 1;
	}
	if (i == 0)
	{
		while (L.a[i] % 2 == 1 && i < L.length)
		{
			i++;
			flag = 1;
		}
		if (flag)
			i--;
		if (L.a[i] % 2 == 0 && i== L.length-1)
			return;
	}
	int j = 0;
	while (L.a[j] % 2 == 1 && j < L.length)
		j++;
	if (i == L.length || j == L.length)
		return;
	if (i>j)
	{
		temp = L.a[i];
		L.a[i] = L.a[j];
		L.a[j] = temp;
		temp = i;
		i = j;
		j = temp;
	}
	while (i < L.length - 1 && j < L.length - 1)
	{
		i++;
		while (L.a[i] % 2 == 0 && i < L.length)
			i++;
		if (i == L.length)
			return;
		temp = L.a[i];
		int k;
		for (k = i; k>j; k--)
			L.a[k] = L.a[k - 1];
		L.a[j] = temp;
		while (j < L.length&&L.a[j] % 2 == 1)
			j++;
	}
}

void SequentialList(A &L,int s)
{
	createList(L);
	cout << "����Ҫ����ģ�";
	cin >> s;
	for (int i = L.length; i>0; i--)
	{
		L.a[i] = L.a[i - 1];
	}
	L.a[0] = s;
	L.length++;
	MaopaoSort(L);
}

void hebing(A &L1, A &L2, A &L3)
{
	cout << "����1��";
	createList(L1);
	cout << "����2";
	createList(L2);
	init(L3);
	L3.length = L1.length + L2.length;
	int a = 0, b = 0, c = 0;
	while (a < L1.length&&b < L2.length)
	{
		if (L1.a[a] <= L2.a[b])
		{
			L3.a[c++] = L1.a[a++];
		}
		else
		{
			L3.a[c++] = L2.a[b++];
		}
	}
	while (a < L1.length)
		L3.a[c++] = L1.a[a++];
	while (b < L2.length)
		L3.a[c++] = L1.a[b++];
	MaopaoSort(L3);
}

int main()
{
	int choose,g,g1,g2;
	int g3 = 0;
	int c = 1;
	A a1, a2, a3;
	while (c==1)
	{
		cout << "��ѡ����Ҫ���еĲ�����" << endl;
		cout << "1������һ������Ԫ�����У�����˳���" << endl;
		cout << "2��˳���ı���" << endl;
		cout << "3����ֵ˳�����ĳһԪ��" << endl;
		cout << "4����λ�ò���һ��Ԫ��" << endl;
		cout << "5���жϸ�˳�����Ԫ���Ƿ�Գ�" << endl;
		cout << "6��������������ż��֮ǰ" << endl;
		cout << "7����λ��˳�����ĳһԪ��" << endl;
		cout << "8����������Ԫ�����У��������������㷨����һ�������" << endl;
		cout << "9�����������ǵݼ�����������Ǻϲ���һ���ǵݼ������" << endl;
		cin >> choose;
		if (choose<1 || choose>9)
		{
			cout << "��������." << endl;
			cin >> choose;
		}
		switch (choose)
		{
		case 1:
			createList(a1);
			Traverse(a1);
			break;
		case 2:
			createList(a1);
			cout << "������" << endl;
			Traverse(a1);
		case 3:
			createList(a1);
			cout << "����Ҫ���ҵ�����:";
			cin >> g;
			findByValue(a1, g);
			break;
		case 4:
			createList(a1);
			cout << "��������λ�ã�";
			cin >> g1;
			cout << "����������ֵ��";
			cin >> g2;
			Insert(a1, g1, g2);
			Traverse(a1);
			break;
		case 5:
			createList(a1);
			symmertry(a1);
			break;
		case 6:
			createList(a1);
			JiOu(a1);
			Traverse(a1);
			break;
		case 8:
			SequentialList(a1, g3);
			Traverse(a1);
			break;
		case 9:
			hebing(a1, a2, a3);
			Traverse(a3);
			break;
		default:
			break;
		}
		cout << "�Ƿ������1������  2���˳�";
		cin >> c;
	}
	return 0;
}