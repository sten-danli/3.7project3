// project3.cpp : //基类指针_纯虚函数_多态_虚析构

#include <iostream>
#include "Human.h"
#include "Men.h"
#include "Women.h"
#include "func.h"
#include "project3.h"



int main()
{
	
	//firend 

	//一:友元函数，
	//public,protected,private
	//只要让函数func成为类Men的友元函数，那么func这个函数就能访问类Men的所有成员，成员变量，成员函数，public,protected,private
	Men friendmen;
	func(friendmen);
	//总结 友元函数func是个函数，通过声明为某个类Men的友元函数，他就可以访问这个类Men的所有成员，包括public，protected，private。
	
	//友元类，
	




	
	//Men men;
	//men.printtest();//这个对象将从父类调取。
	//men.printtest(1);//这个对象将从子类men调取。
	/*men.add_age(3);*/
	/*men.m_Age = 16;
	cout << men.m_Age << endl;*/
		
	//基类指针_纯虚函数_多态_虚析构
	//新玩法:
	//一虚函数的作用，为什么使用virtual
	Human* human = new Women;//父类指针可以new一个子类的对象.
	 //Men* men = new Human;//子类不可以new父类对象
	
	//human->funcHumen();//在父类中未使用virtual之前，虽然父类new了个子类对象，却只能调动父类中的函数,
	////既然父类指针无法调用子类函数，为什么还要父类指针new一个子类对象呢，有什么用处呢,
	////当我们把父类同名函数的声明出赋予virtual的时候就可以用一个指针使用子类内的函数了。
	//human->eat();//在父类使用virtual后，此时就可以调用子类Men的 eat()函数了。
	//human = new Women;//把指针指向Women就可以调动Women类里面的同函数名了。
	//human->eat();//此时调动的就是Women类中的ent()函数了。
	//也可以这样玩
	human->Human::eat();//调动human eat()函数。
	human = new Men;
	human->eat();
	
	
	
	
	//总结什么时候用到虚函数virtual当各类中的函数名函数体都一抹一样的话为了方便调用各个类中的同名函数就可以使用virtual方法。
	////override是为了防止用virtual时必须子类的函数和父类函数一模一样，当不一样时overide会提出错误,这个关键字用在子类中，为
	//虚函数专用。override就是用来说明派生类中的虚函数，你用了这个关键字后，编译器
	//编译器就会认为你这个函数eat是覆盖了父类中的同名函数的。
	//调动虚函数执行的是动态绑定，动态表示就是在我们程式运行的时候才能知道调用了那个子类的eat函数
	//动态绑定运行时才决定你的human对象绑定到那个eat函数上。
	//在函数声明中virtual void eat() final;也是虚函数专用，使用在父类，如果我们在父类的函数生命中加了final
	//那么任何尝试覆盖该函数的操作都会引发错误。

	//三 多态性是针对虚函数来说的，随着虚函数地提出，面向对象的里边的多态性就浮出了水面
	//多态性体现在具有承诺关系的父类和子类之间，子类重新定义了重写父类的成员函数，同时父类把
	//这个函数声明称了virtual，通过父类的指针，只有到了程序运行时期，找到动态绑定到父类指针上的对象
	//也可能是父类对象，然后系统内部实际上是要查一个虚函数的入口，从而调用父类或子类的eat
	//函数，这就是运行时期的多态性。

	//四 纯虚函数 是在基类中声明的虚函数，但是他在基类中没有定义，但是要求任何派生类都要定义该虚函数自己的实现方法。
	//基类中实现纯虚函数的方法是在函数原型后增加=0;
	//注意一旦一个类中有纯虚函数了，那么你就不能生成这个类的的对象了，例如如下，不能生成父类的对象了,这个类就成为了抽象类了。
	//抽象类主要是用来统一管理子类对象。
	//Human human;
	//Human* human = new Human;
	//所以，大家记住两点
	//1.函数纯虚函数的类 叫做抽象类，不能用来生成该类的对象，主要用于当作父类生成子类用的，这样大家不会忘记在子类中都要定义什么函数方法。
	//2.子类中必须要实现该夫类中定义的纯虚函数。

	//五 父类的析构函数一般写成虚构函数。
	//1
	Women women;

	/*运行后正常的执行了以下析构语句
	执行了Women::~Women()
	执行了Human::~Human()*/
	
	//2
	//如果是new出来的东西话就用delete 方法，如下
	Men* men = new Men;
	//men->funcmen();
	Men men1;
	//men1.funcmen();
	//然后用delete方法释放内存
	//delete men;

	//3
	//但是如果是父类指针new出来子类对象呢，东就要用
	Human* phuman = new Men;
	delete phuman;
	//虽然写了delete phuman;但是只执行了Human::~Human()父类的析构。
	//这时就很糟糕因为他只析构了父类的析构函数，而没有析构子类的析构函数，只删除了一半造成内存泄漏。
	//结论;用基类指针new子类的对象，在delete的收系统不会调用派生类的析构函数。这跟定有问题了
	//如何解决.把父类中.h定义虚函数的时候写成虚析构函数:virtual ~Human();
	//如果一个类想要做父类，我们无必要把这个类的析构函数写成virtual析构函数。

}

