// project3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "Women.h"
#include <iostream>
using namespace std;


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
