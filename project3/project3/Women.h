// Women.h : //基类指针_纯虚函数_多态_虚析构

#ifndef __WOMEN__H__
#define __WOMEN__H__
#include <iostream>
#include "Human.h"
using namespace std;

//定义子类
class Women : public Human 
{
	virtual void sleep();

public:
	virtual void  eat()override;//override是为了防止用virtual时必须子类的函数和父类函数一模一样，当不一样时overide会提出错误。


public:
	Women();
	~Women();

public:
	//如果子类和父类的函数都是同名的话，那么子类会覆盖父类的函数，如果非要想调动父类的函数的话，那么只能在子类的函数中调查父类的函数。
	//void printtest();//父类中有同名函数。
	void printtest(int);//父类中有同名函数。

public:
	//using Human::printtest;//而在子类中只要一个using父类的函数那么将所有同名函数都用父类的。



public:
	void add_age(int age);

};






#endif // !__HUMAN__H__
