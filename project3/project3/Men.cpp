﻿// project3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "Men.h"
#include <iostream>
using namespace std;



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
