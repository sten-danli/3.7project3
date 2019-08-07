#ifndef __MEN__H__
#define __MEN__H__
#include <iostream>
#include "Human.h"
using namespace std;

//定义子类
class Men : public Human
{

public:
	Men();
	

public:
	//如果子类和父类的函数都是同名的话，那么子类会覆盖父类的函数，如果非要想调动父类的函数的话，那么只能在子类的函数中调查父类的函数。
	void printtest();//父类中有同名函数。
	void printtest(int);//父类中有同名函数。



};






#endif // !__HUMAN__H__
