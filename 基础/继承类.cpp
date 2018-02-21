// study.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

class person
{
protected:
	char name[10];
	int age;
public:
	person(char n[], int a){ strcpy_s(name, n); age = a; }
	void disp()
	{
		cout << "������" << name << endl;
		cout << "���䣺" << age << endl;
	}
};

class teacher :public person
{
	char tid[10];
	char dept[20];
	char post[10];
public:
	teacher(char *s1, char *s2, int i, char *s3, char *s4) :person(s2, i)
	{
		strcpy_s(tid, s1);
		strcpy_s(dept, s3);
		strcpy_s(post, s4);
	}
	void disptech()
	{
		cout << "��ţ�" << tid << endl;
		person::disp();
		cout << "�������ţ�" << dept << endl;
		cout << "ְλ��" << post << endl;
	}
};

class student :public person
{
	char sid[12];
	char cnum[12];
	double score;
public:
	student(char *s1, char *s2, int a, char *s3, double i) :person(s2, a)
	{
		strcpy_s(sid, s1);
		strcpy_s(cnum, s3);
		score = i;
	}
	void dispstu() 
	{
		cout << "  ѧ    �ţ�" << sid << endl;
		person::disp();
		cout << "  ��    ����" << cnum << endl;
		cout << "  ��    ����" << score << endl;
	}
};

int main()
{
	teacher t("007","С��",18,"��Ϣ����","����");
	t.disptech();
	student s("008", "����", 20, "116152", 98);
	s.dispstu();
	return 0;
}







