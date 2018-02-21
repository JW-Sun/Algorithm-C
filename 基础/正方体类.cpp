// study.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

class ZhengCube
{
private:
	double x;
public:
	ZhengCube(double xx){ x = xx; };
	double getS();
	double getV();
};
double ZhengCube::getS()
{
	return pow(x, 2) * 6;
}

double ZhengCube::getV()
{
	return pow(x, 3);
}

int main()
{
	double x;
	cout << "请输入正方体的边长：";
	cin >> x;
	ZhengCube z(x);
	cout << "表面积：" << z.getS() << endl;
	cout << "体积为：" << z.getV() << endl;
	system("pause");
	return 0;
}
