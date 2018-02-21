// study.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;

public:
	Time(){};
	int setHour(int h);
	int setMinute(int m);
	int setSecond(int s);
	int getHour();
	int getMinute();
	int getSecond();
	void showTime();
	void show();
};

int Time::setHour(int h)
{
	if (h<0||h>24)
	{
		cout << "时间错误。" << endl;
		return 0;
	}
	else
	{
		hour = h;
		return 1;
	}
}

int Time::setMinute(int m)
{
	if (m<0 || m>60)
	{
		cout << "time error!" << endl;
		return 0;
	}
	else
	{
		minute = m;
		return 1;
	}
}

int Time::setSecond(int s)
{
	if (s<0||s>60)
	{
		cout << "time error!" << endl;
		return 0;
	}
	else
	{
		second = s;
		return 1;
	}
}

int Time::getHour()
{
	return hour;
}

int Time::getMinute()
{
	return minute;
}

int Time::getSecond()
{
	return second;
}

void Time::showTime()
{
	cout << "时间为：" << hour << ":" << minute << ":" << second << endl;
}

void Time::show()
{
	if (hour == 12)
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}
	else
	{
		cout << ((hour<12 && hour >= 0) ? "上午：" : "下午：") << hour%12 << ":" << minute << ":" << second << endl;
	}
}

void main()
{
	int h, m, s;
	cout << "输入时，分，秒：" << endl;
	cin >> h >> m >> s;
	Time t;
	if (t.setHour(h)==0||t.setMinute(m)==0||t.setSecond(s)==0)
	{
		cout << "error!" << endl;
	}
	t.show();
	t.showTime();
	system("pause");
}