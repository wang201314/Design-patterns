#pragma once
#include<iostream>
#include<string>
#include<unordered_map>
//工厂模式，创建型设计模式
/*
首先， 工厂模式是为了解耦：把对象的创建和使用的过程分开。就是Class A 想调用 Class B ，那么A只是调用B的方法，而至于B的实例化，就交给工厂类。

其次， 工厂模式可以降低代码重复。如果创建对象B的过程都很复杂，需要一定的代码量，而且很多地方都要用到，那么就会有很多的重复代码。我们可以这些创建对象B的代码放到工厂里统一管理。既减少了重复代码，也方便以后对B的创建过程的修改维护。（当然，我个人觉得也可以把这些创建过程的代码放到类的构造函数里，同样可以降低重复率，而且构造函数本身的作用也是初始化对象。不过，这样也会导致构造函数过于复杂，做的事太多，不符合java 的设计原则。）

由于创建过程都由工厂统一管理，所以发生业务逻辑变化，不需要找到所有需要创建B的地方去逐个修正，只需要在工厂里修改即可，降低维护成本。同理，想把所有调用B的地方改成B的子类B1，只需要在对应生产B的工厂中或者工厂的方法中修改其生产的对象为B1即可，而不需要找到所有的new B（）改为new B1()。

另外， 因为工厂管理了对象的创建逻辑，使用者并不需要知道具体的创建过程，只管使用即可，减少了使用者因为创建逻辑导致的错误。

举个例子：

一个数据库工厂：可以返回一个数据库实例，可以是mysql，oracle等。

这个工厂就可以把数据库连接需要的用户名，地址，密码等封装好，直接返回对应的数据库对象就好。不需要调用者自己初始化，减少了写错密码等等这些错误。调用者只负责使用，不需要管怎么去创建、初始化对象。

还有，如果一个类有多个构造方法（构造的重写），我们也可以将它抽出来，放到工厂中，一个构造方法对应一个工厂方法并命名一个友好的名字，这样我们就不再只是根据参数的不同来判断，而是可以根据工厂的方法名来直观判断将要创建的对象的特点。这对于使用者来说，体验比较好。

工厂模式适用的一些场景（不仅限于以下场景）：

1. 对象的创建过程/实例化准备工作很复杂，需要初始化很多参数、查询数据库等。

2.类本身有好多子类，这些类的创建过程在业务中容易发生改变，或者对类的调用容易发生改变。

作者：可可西里的星星
链接：https://www.jianshu.com/p/38bd26a1f7ef
来源：简书
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#if 0
//简单工厂
enum CTYPE {COREA, CORED};
class SingleCore
{
public:
	virtual void Show() = 0;
};
class SingleCoreA:public SingleCore
{
public:
	void Show()
	{
		std::cout << "SingleCore A" << std::endl;
	}
};
class SingleCoreB :public SingleCore
{
public:
	void Show()
	{
		std::cout << "SingleCore B" << std::endl;
	}
};
class Factory
{
public:
	SingleCore* CreateSingleCore(enum CTYPE ctype)
	{
		switch (ctype)
		{
		case COREA:
			return new SingleCoreA();
		case CORED:
			return new SingleCoreB();
		default:
			return nullptr;
		}
	}
};
//缺点增加产品时需要改变CreateSingleCore方法里的内容，违反一个修改原则，
#elif 0
//工厂方法
class SingleCore
{
public:
	virtual void Show() = 0;
};
class SingleCoreA :public SingleCore
{
public:
	void Show()
	{
		std::cout << "SingleCore A" << std::endl;
	}
};
class SingleCoreB :public SingleCore
{
public:
	void Show()
	{
		std::cout << "SingleCore B" << std::endl;
	}
};
class Factory
{
public:
	virtual SingleCore* CreateSingleCore() = 0;
};
class FactoryA :public Factory
{
public:
	SingleCoreA* CreateSingleCore()
	{
		return new SingleCoreA();
	}
};
class FactoryB :public Factory
{
public:
	SingleCoreB* CreateSingleCore()
	{
		return new SingleCoreB();
	}
};
//商品多的话工厂会非常多
#elif 0
/*
抽象工厂
一个工厂可以生产相似的产品
*/
//抽象单核
class SingleCore
{
public:
	virtual void Show() = 0;
};
//抽象多核
class MultiCore
{
public:
	virtual void Show() = 0;
};
//单A核
class SingleCoreA :public SingleCore
{
public:
	void Show()
	{
		std::cout << "SingleCore A" << std::endl;
	}
};
//单B核
class SingleCoreB :public SingleCore
{
public:
	void Show()
	{
		std::cout << "SingleCore B" << std::endl;
	}
};
//多A核
class MultiCoreA :public MultiCore
{
public:
	void Show()
	{
		std::cout << "MultiCore A" << std::endl;
	}
};
//多B核
class MultiCoreB :public MultiCore
{
public:
	void Show()
	{
		std::cout << "MultiCore B" << std::endl;
	}
};
//抽象工厂
class Factory
{
public:
	virtual SingleCore* CreateSingleCore() = 0;
	virtual MultiCore* CreateMultiCore() = 0;
};
class FactoryA :public Factory
{
public:
	SingleCoreA* CreateSingleCore()
	{
		return new SingleCoreA();
	}
	MultiCoreA* CreateMultiCore()
	{
		return new MultiCoreA();
	}
};
class FactoryB :public Factory
{
public:
	SingleCoreB* CreateSingleCore()
	{
		return new SingleCoreB();
	}
	MultiCoreB* CreateMultiCore()
	{
		return new MultiCoreB();
	}
};
//商品多的话工厂也非常多
#elif 0
/*
不需要新增具体的工厂类 =>将工厂方法模式改良成模板参数为产品的模板工厂类，
这样新增产品无需新增工厂
*/
//抽象Shoes
class Shoes
{
public:
	virtual void Show() = 0;
	virtual ~Shoes() {}
};
//抽象Clothes
class Clothes
{
public:
	virtual void Show() = 0;
};
//NikeShoes
class NikeShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "NikeShoes" << std::endl;
	}
};
//adidasShoes
class adidasShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "adidasShoes" << std::endl;
	}
};
class UniClothes :public Clothes
{
public:
	void Show() 
	{
		std::cout << "UniClothes" << std::endl;
	}
};
//抽象模板工厂
template<class AbstractProduct_t>
class AbstractFactory
{
public:
	virtual AbstractProduct_t* CreateProduct() = 0;
	virtual ~AbstractFactory(){}
};
//具体模板工厂
template<class AbstractProduct_t,class ConcreteProduct_t>
class ConcreteFactory:public AbstractFactory<AbstractProduct_t>
{
public:
	ConcreteProduct_t* CreateProduct()
	{
		return new ConcreteProduct_t();
	}
};
//不能随时随地获取产品
#elif 1
/*
可以统一随时随地获取指定的产品对象=> 把产品注册的功能封装成产品注册模板类+把获取产品对象的功能封装成单例工厂模板类
*/
//抽象Shoes
class Shoes
{
public:
	virtual void Show() = 0;
	virtual ~Shoes() {}
};
//抽象Clothes
class Clothes
{
public:
	virtual void Show() = 0;
};
//NikeShoes
class NikeShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "NikeShoes" << std::endl;
	}
};
//adidasShoes
class adidasShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "adidasShoes" << std::endl;
	}
};
class UniClothes :public Clothes
{
public:
	void Show()
	{
		std::cout << "UniClothes" << std::endl;
	}
};
//抽象模板注册类
template<class ProductType_t>
class IProductRegistrar
{
public:
	virtual ProductType_t* CreateProduct() = 0;
	virtual ~IProductRegistrar() {}
};
//具体模板注册类
template<class ProductType_t, class ProductImpl_t>
class ProductRegistrar :public IProductRegistrar<ProductType_t>
{
public:
	explicit ProductRegistrar(std::string name)
	{
		ProductFactory<ProductType_t>::Instance().RegisterProduct(this,name);
	}
	ProductType_t* CreateProduct()override
	{
		return new ProductImpl_t();
	}
};
//模板工厂
template<class ProductType_t>
class  ProductFactory
{
public:
	static ProductFactory<ProductType_t>&Instance()
	{
		static ProductFactory<ProductType_t>instance;
		return instance;
	}
	void RegisterProduct(IProductRegistrar<ProductType_t>*Registrar, std::string name)
	{
		map[name] = Registrar;
	}
	ProductType_t * GetProduct(std::string name)
	{
		if(map.find(name)!=map.end())
			return map[name]->CreateProduct();
		std::cout << "没有该产品"<<std::endl;
		return nullptr;
	}
private:
	std::unordered_map<std::string, IProductRegistrar<ProductType_t>*>map;
};
#endif
