#ifndef __HUMAN__H__
#define __HUMAN__H__
#include <iostream>
using namespace std;
//protected 只允许本类或子类的成员函数中来访问。
//private 只允许本类的成员函数来访问。
//如果子类和父类的函数都是同名的话，那么子类会覆盖父类的函数，如果非要想调动父类的函数的话，那么只能在子类的函数中调查父类的函数。
//定义基类
class Human
{
	
public: 
	virtual void eat();



public:
	Human();
	Human(int);

protected:
	int m_Age;
	char m_Name[100];

public: 
	void funcHumen()//inline 函数使用，因为直接在.h内定义了函数。
	{
		cout << "调用funchumen函数" << endl;
	}

public:
	
	void printtest();//子类中创建了同名函数。
	void printtest(int);//子类中创建了同名函数。
	//如果子类和父类的函数都是同名的话，那么子类会覆盖父类的函数，如果非要想调动父类的函数的话，那么只能在子类的函数中调查父类的函数。









};






#endif // !__HUMAN__H__
