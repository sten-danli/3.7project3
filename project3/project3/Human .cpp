// project3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "Human.h"
#include <iostream>
using namespace std;


void Human:: eat()
{
	cout << "调动Human eat()" << endl;
}

Human::Human()
{
	cout << "执行了不带参数构造函数Human::Human()" << endl;
}
Human::Human(int h)
{
	cout << "执行了带参数构造函数Human::Human(int)" << endl;
}

void Human::printtest()
{
	cout << "调动父类的printtest" << endl;
}

void Human:: printtest(int)
{
	cout << "调动父类的带参数的printtest(int)" << endl;
}


