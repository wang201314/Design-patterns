#pragma once
#include <iostream>
#include <string>
#include <list>
/*
一个/多个类访问一个多个类，强调访问操作
*/
class Apple;
class Book;
//抽象访问者
class Vistor
{
public:
	void set_name(std::string name)
	{
		name_ = name;
	}
	virtual void visit(Apple*apple) = 0;
	virtual void visit(Book*book) = 0;
protected:
	std::string name_;
};
//具体访问者
class Customer :public Vistor
{
public:
	void visit(Apple*apple) override
	{
		std::cout << "顾客:" << name_ << "挑选苹果。" << std::endl;
	}
	void visit(Book*book) override
	{
		std::cout << "顾客:" << name_ << "买书。" << std::endl;
	}
};
class Saler :public Vistor
{
public:
	void visit(Apple*apple) override
	{
		std::cout << "收银员:" << name_ << "计算苹果价格。" << std::endl;
	}
	void visit(Book*book) override
	{
		std::cout << "收银员:" << name_ << "计算书的价格。" << std::endl;
	}
};
//抽象物品
class Product
{
public:
	virtual void accept(Vistor*vistor)=0;
};
class Apple:public Product
{
public:
	void accept(Vistor*vistor) override
	{
		vistor->visit(this);
	}
};
class Book :public Product
{
public:
	void accept(Vistor*vistor) override
	{
		vistor->visit(this);
	}
};
class ShoppingCart
{
public:
	void accept(Vistor*vistor)
	{
		for (auto&prd: prd_list_)
		{
			prd->accept(vistor);
		}
	}
	void addProduct(Product* prd)
	{
		prd_list_.push_back(prd);
	}
	void removeProduct(Product* prd)
	{
		prd_list_.remove(prd);
	}
private:
	std::list<Product*>prd_list_;
};
/*
访问者模式适合应用场景
 如果你需要对一个复杂对象结构 （例如对象树） 中的所有元素执行某些操作， 可使用访问者模式。

 访问者模式通过在访问者对象中为多个目标类提供相同操作的变体， 让你能在属于不同类的一组对象上执行同一操作。

 可使用访问者模式来清理辅助行为的业务逻辑。

 该模式会将所有非主要的行为抽取到一组访问者类中， 使得程序的主要类能更专注于主要的工作。

 当某个行为仅在类层次结构中的一些类中有意义， 而在其他类中没有意义时， 可使用该模式。

 你可将该行为抽取到单独的访问者类中， 只需实现接收相关类的对象作为参数的访问者方法并将其他方法留空即可。



 多个访问者继承抽象访问实现需要访问产品的访问方法，方法是重载的，对于不同的产品可以实现不同的放问方法，
 被访问者有一个接受访问的的方法：利用多态性将自己作为参数传递给访问者调用的访问函数
*/