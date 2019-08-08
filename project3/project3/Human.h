// Human.h : //基类指针_纯虚函数_多态_虚析构

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
public:	//声明一个纯虚函数，1.函数纯虚函数的类 叫做抽象类，不能用来生成该类的对象，主要用于当作父类生成子类用的，
	//这样大家不会忘记在子类中都要定义什么函数方法。

	virtual void sleep() = 0;
	


public: 
	virtual void eat();//虚函数



public:
	Human();
	Human(int);
	virtual ~Human();
	//因为在Human *phuman = new Men;时只是放了父类的析构函数儿子类没有释放所以这里用virtual。
	//只执行了Human::~Human()
	//这时就很糟糕因为他只析构了父类的析构函数，而没有析构子类的析构函数，只删除了一半造成内存泄漏。
	//结论;用基类指针new子类的对象，在delete的收系统不会调用派生类的析构函数。这跟定有问题了
	//如何解决.把父类中.h定义虚函数的时候写成虚析构函数:virtual ~Human();

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
