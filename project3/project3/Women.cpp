// Women.cpp : // project3.cpp : //基类指针_纯虚函数_多态_虚析构

#include "Women.h"
#include <iostream>
using namespace std;


void Women::sleep()
{
	cout << "调动Women sleep()函数" << endl;
}

void  Women::eat()
{
	cout << "调动Women eat()" << endl;
}

Women::Women()
{
	
	cout << "执行了不带参数构造函数Women::Women()" << endl;
	 m_Age=12;
	 cout << m_Age<<endl;
}

Women::~Women()

	{
		cout << "执行了Women::~Women()" << endl;
	}


//void Men::printtest()
//{
//	cout << "调动子类的printtest" << endl;
//}


void Women::printtest(int)
{
	// Human::printtest(12);

	cout << "调动子类的带参数的printtest(int)" << endl;
}

void Women::add_age(int age)
{
	m_Age += age;
	cout << m_Age << endl;
}
