// Men.cpp : // project3.cpp : //基类指针_纯虚函数_多态_虚析构
#include "Men.h"
#include <iostream>
using namespace std;



void Men::sleep()
{
	cout << "调用Men spleep函数" << endl;
}

void Men::eat()
{
	cout << "调动Men的 eat()" << endl;
}


Men::Men()
{
	
	cout << "执行了不带参数构造函数Men::Men()" << endl;
	 m_Age=12;
	 cout << m_Age<<endl;
}

Men::~Men()
{
	cout << "执行了Men::~Men" << endl;
}


void Men::funcmen() const
{
	cout << "调动了funcman()函数" << endl;
}



//void Men::printtest()
//{
//	cout << "调动子类的printtest" << endl;
//}


void Men::printtest(int)
{
	// Human::printtest(12);

	cout << "调动子类的带参数的printtest(int)" << endl;
}

void Men::add_age(int age)
{
	m_Age += age;
	cout << m_Age << endl;
}
