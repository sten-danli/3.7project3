// project3.cpp : //基类指针_纯虚函数_多态_虚析构

#include <iostream>
#include "Human.h"
#include "Men.h"
#include "Women.h"
#include "func.h"
#include "project3.h"

//一 派生类对象模型简述
//Men mymen //子类派生类对象，包含多个组成部分，也就是多个子对象。
//（1）一个是含有派生类自己定义的成员变量，成员函数的子对象。
//（2）一个是该派生类所继承的父类的子对象，这个字对象中包含的是父类中定义的成员变量，成员函数（派生类对象含有积累对应的组成部分）。
//Human* phuman = new Man;//基类指针可以new派生类对象，因为派生类对象含有基累部分，所以我们是可以把派生类对象当成基类对象用的。
				//换句话说我们可以用基类指针new一个派生类对象。
				//编译器帮助我们做了隐士的这种派生类到基类的转换
				//这种转换的好处就是有些需要基类引用的地方你可以用这个派生类对象的引用类代替，如果有些需要基类指针的地方呢，你也可以用派生类对象的指针来代替。

//二 派生类构造函数//如果父类的构造函数需要参数，我们如何通过派生类对象的定义，把基类的构造函数的参数传递给基类的构造函数呢。
//在执行子类时及调用了基类，又调用了派生类的构造函数。
//派生类是使用父类的构造函数来初始化他的父类部分，基类控制基类部分的成员变量初始化，派生类控制派生类部分成员初始化，各行其则。
//传递参数给基类构造函数问题:通过派生类的构造函数初始化列表。
//先执行父类的的构造函数，在执行子类的构造函数。
//先执行子类的的析构函数，再执行父类的析构函数。
class A
{
	
public:
	A(int i , int j):m_valuea(i),m_valuea2(j){}

public:
	void virtual funcprint()
	{
		cout << "A" << endl;
		cout << m_valuea << endl;
	}
private:
	int m_valuea;
	int m_valuea2;
};
class B:public A
{
public:
	
	B(int i=0,int j=0, int k=0):A(i, j),m_valueb(k){}// A (i)的意思是因为class A没有初始化构造函数的成员初始化值，所以在B内要为A的成员初始化,通过子类的初始化类表给父类的函数转递参数。
public:

	void funcprint()
	{
		cout << "B" << endl;
		cout << m_valueb<< endl;
	}
private:

	int m_valueb;
};

class C :public A
{
public:

	C(int i = 0, int j = 0, int k = 0) :A(i, j), m_valuec(k) {}// A (i)的意思是因为class A没有初始化构造函数的成员初始化值，所以在B内要为A的成员初始化,通过子类的初始化类表给父类的函数转递参数。
public:

	void funcprint()
	{
		cout << "C" << endl;
		cout << m_valuec << endl;
	}
private:

	int m_valuec;
};


int main()
{
	B b(1, 2, 3);
	C c(11, 22, 33);
	A* pa = &b;//基类指针指向子类的对象
	pa->funcprint();
	A* pc = &c;//基类指针指向子类的对象
	pc->funcprint();
	
	

	////firend 
	////一:友元函数，
	////public,protected,private
	////只要让函数func成为类Men的友元函数，那么func这个函数就能访问类Men的所有成员，成员变量，成员函数，public,protected,private
	//Men friendmen;
	//func(friendmen);
	////总结 友元函数func是个函数，通过声明为某个类Men的友元函数，他就可以访问这个类Men的所有成员，包括public，protected，private。
	//
	////友元类，

	////Men men;
	////men.printtest();//这个对象将从父类调取。
	////men.printtest(1);//这个对象将从子类men调取。
	///*men.add_age(3);*/
	///*men.m_Age = 16;
	//cout << men.m_Age << endl;*/
	//	
	////基类指针_纯虚函数_多态_虚析构
	////新玩法:
	////一虚函数的作用，为什么使用virtual
	//Human* human = new Women;//父类指针可以new一个子类的对象.
	// //Men* men = new Human;//子类不可以new父类对象
	//
	////human->funcHumen();//在父类中未使用virtual之前，虽然父类new了个子类对象，却只能调动父类中的函数,
	//////既然父类指针无法调用子类函数，为什么还要父类指针new一个子类对象呢，有什么用处呢,
	//////当我们把父类同名函数的声明出赋予virtual的时候就可以用一个指针使用子类内的函数了。
	////human->eat();//在父类使用virtual后，此时就可以调用子类Men的 eat()函数了。
	////human = new Women;//把指针指向Women就可以调动Women类里面的同函数名了。
	////human->eat();//此时调动的就是Women类中的ent()函数了。
	////也可以这样玩
	//human->Human::eat();//调动human eat()函数。
	//human = new Men;
	//human->eat();
	//
	//
	//
	//
	////总结什么时候用到虚函数virtual当各类中的函数名函数体都一抹一样的话为了方便调用各个类中的同名函数就可以使用virtual方法。
	//////override是为了防止用virtual时必须子类的函数和父类函数一模一样，当不一样时overide会提出错误,这个关键字用在子类中，为
	////虚函数专用。override就是用来说明派生类中的虚函数，你用了这个关键字后，编译器
	////编译器就会认为你这个函数eat是覆盖了父类中的同名函数的。
	////调动虚函数执行的是动态绑定，动态表示就是在我们程式运行的时候才能知道调用了那个子类的eat函数
	////动态绑定运行时才决定你的human对象绑定到那个eat函数上。
	////在函数声明中virtual void eat() final;也是虚函数专用，使用在父类，如果我们在父类的函数生命中加了final
	////那么任何尝试覆盖该函数的操作都会引发错误。

	////三 多态性是针对虚函数来说的，随着虚函数地提出，面向对象的里边的多态性就浮出了水面
	////多态性体现在具有承诺关系的父类和子类之间，子类重新定义了重写父类的成员函数，同时父类把
	////这个函数声明称了virtual，通过父类的指针，只有到了程序运行时期，找到动态绑定到父类指针上的对象
	////也可能是父类对象，然后系统内部实际上是要查一个虚函数的入口，从而调用父类或子类的eat
	////函数，这就是运行时期的多态性。

	////四 纯虚函数 是在基类中声明的虚函数，但是他在基类中没有定义，但是要求任何派生类都要定义该虚函数自己的实现方法。
	////基类中实现纯虚函数的方法是在函数原型后增加=0;
	////注意一旦一个类中有纯虚函数了，那么你就不能生成这个类的的对象了，例如如下，不能生成父类的对象了,这个类就成为了抽象类了。
	////抽象类主要是用来统一管理子类对象。
	////Human human;
	////Human* human = new Human;
	////所以，大家记住两点
	////1.函数纯虚函数的类 叫做抽象类，不能用来生成该类的对象，主要用于当作父类生成子类用的，这样大家不会忘记在子类中都要定义什么函数方法。
	////2.子类中必须要实现该夫类中定义的纯虚函数。

	////五 父类的析构函数一般写成虚构函数。
	////1
	//Women women;

	///*运行后正常的执行了以下析构语句
	//执行了Women::~Women()
	//执行了Human::~Human()*/
	//
	////2
	////如果是new出来的东西话就用delete 方法，如下
	//Men* men = new Men;
	////men->funcmen();
	//Men men1;
	////men1.funcmen();
	////然后用delete方法释放内存
	////delete men;

	////3
	////但是如果是父类指针new出来子类对象呢，东就要用
	//Human* phuman = new Men;
	//delete phuman;
	////虽然写了delete phuman;但是只执行了Human::~Human()父类的析构。
	////这时就很糟糕因为他只析构了父类的析构函数，而没有析构子类的析构函数，只删除了一半造成内存泄漏。
	////结论;用基类指针new子类的对象，在delete的收系统不会调用派生类的析构函数。这跟定有问题了
	////如何解决.把父类中.h定义虚函数的时候写成虚析构函数:virtual ~Human();
	////如果一个类想要做父类，我们无必要把这个类的析构函数写成virtual析构函数。

	////二 dynamic_cast运算符。
	//Men* p = (Men*)(phuman);//这就是硬把phuman传换成Men类型,这就是用c语言风格强制类型转换，硬把指针转换成Men*.
	//p->add_age(1);//强制转换后就可以使用Men类里面的成员函数add_age函数.
	////在c++中我们用 dynamic_cast运算符 如果开运算符能够转换成功，说明这个指针实际上是要转换到的那个类型。这个运算符能够帮咱们做安全检查。
	////注意使用dynamic_cast时，父类中必须有一个虚函数！
	//Human* pwomen_cpp = new Women;
	//Women* pwomen = static_cast<Women*>(pwomen_cpp);
	//if (pwomen != nullptr)
	//{
	//	pwomen->add_age(1);
	//	cout << "pwomen__cpp实际是一个Women类型" << endl;
	//	//在这里操作Women里边的成员函数，成员变量都能够造作并且安全的操作。
	//}
	//else
	//{
	//	cout << "pwomen__cpp不是一个Women类型" << endl;
	//}
	////三 typeid运算符。
	////typeid(类型/引用)，也可能typeif表达式
	////拿到对象类型信息，typeid就会返回一个常量的对象，这个常量的对象是一个标准的库类型tzpe_info(类，类型)。
	//Human* phuman_t = new Men;
	//Human& p_t = *phuman_t;
	//cout << typeid(*phuman_t).name() << endl;
	//cout << typeid(p_t).name() << endl;






	//delete phuman;
	////虽然写了delete phuman;但是只执行了Human::~Human()父类的析构。
	////这时就很糟糕因为他只析构了父类的析构函数，而没有析构子类的析构函数，只删除了一半造成内存泄漏。
	////结论;用基类指针new子类的对象，在delete的收系统不会调用派生类的析构函数。这跟定有问题了
	////如何解决.把父类中.h定义虚函数的时候写成虚析构函数:virtual ~Human();
	////如果一个类想要做父类，我们无必要把这个类的析构函数写成virtual析构函数。


}
