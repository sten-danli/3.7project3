#ifndef __MEN__H__
#define __MEN__H__
#include <iostream>
#include "Human.h"

using namespace std;
// Men.h : //基类指针_纯虚函数_多态_虚析构

//定义子类
class Men : public Human
{
	//因为友元函数不属于成员，所以友元函数声明不受public，protected，private。
	friend void func(const Men& tempmen);
	
private:
	void funcmen()const;
	//只要让函数func成为类Men的友元函数，那么func这个函数就能访问类Men的所有成员，成员变量，成员函数，public,protected,private




public:
	virtual void sleep();

	virtual void eat()override;
	//override是为了防止用virtual时必须子类的函数和父类函数一模一样，当不一样时overide会提出错误。



public:
	Men();//不带参数构造函数声明。
	~Men();


	

public:
	//如果子类和父类的函数都是同名的话，那么子类会覆盖父类的函数，如果非要想调动父类的函数的话，那么只能在子类的函数中调查父类的函数。
	//void printtest();//父类中有同名函数。
	void printtest(int);//父类中有同名函数。

public:
	using Human::printtest;//而在子类中只要一个using父类的函数那么将所有同名函数都用父类的。



public:
	void add_age(int age);

};






#endif // !__HUMAN__H__
