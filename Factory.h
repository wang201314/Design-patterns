#pragma once
#include<iostream>
#include<string>
#include<unordered_map>
//����ģʽ�����������ģʽ
/*
���ȣ� ����ģʽ��Ϊ�˽���Ѷ���Ĵ�����ʹ�õĹ��̷ֿ�������Class A ����� Class B ����ôAֻ�ǵ���B�ķ�����������B��ʵ�������ͽ��������ࡣ

��Σ� ����ģʽ���Խ��ʹ����ظ��������������B�Ĺ��̶��ܸ��ӣ���Ҫһ���Ĵ����������Һܶ�ط���Ҫ�õ�����ô�ͻ��кܶ���ظ����롣���ǿ�����Щ��������B�Ĵ���ŵ�������ͳһ�����ȼ������ظ����룬Ҳ�����Ժ��B�Ĵ������̵��޸�ά��������Ȼ���Ҹ��˾���Ҳ���԰���Щ�������̵Ĵ���ŵ���Ĺ��캯���ͬ�����Խ����ظ��ʣ����ҹ��캯�����������Ҳ�ǳ�ʼ�����󡣲���������Ҳ�ᵼ�¹��캯�����ڸ��ӣ�������̫�࣬������java �����ԭ�򡣣�

���ڴ������̶��ɹ���ͳһ�������Է���ҵ���߼��仯������Ҫ�ҵ�������Ҫ����B�ĵط�ȥ���������ֻ��Ҫ�ڹ������޸ļ��ɣ�����ά���ɱ���ͬ��������е���B�ĵط��ĳ�B������B1��ֻ��Ҫ�ڶ�Ӧ����B�Ĺ����л��߹����ķ������޸��������Ķ���ΪB1���ɣ�������Ҫ�ҵ����е�new B������Ϊnew B1()��

���⣬ ��Ϊ���������˶���Ĵ����߼���ʹ���߲�����Ҫ֪������Ĵ������̣�ֻ��ʹ�ü��ɣ�������ʹ������Ϊ�����߼����µĴ���

�ٸ����ӣ�

һ�����ݿ⹤�������Է���һ�����ݿ�ʵ����������mysql��oracle�ȡ�

��������Ϳ��԰����ݿ�������Ҫ���û�������ַ������ȷ�װ�ã�ֱ�ӷ��ض�Ӧ�����ݿ����ͺá�����Ҫ�������Լ���ʼ����������д������ȵ���Щ���󡣵�����ֻ����ʹ�ã�����Ҫ����ôȥ��������ʼ������

���У����һ�����ж�����췽�����������д��������Ҳ���Խ�����������ŵ������У�һ�����췽����Ӧһ����������������һ���Ѻõ����֣��������ǾͲ���ֻ�Ǹ��ݲ����Ĳ�ͬ���жϣ����ǿ��Ը��ݹ����ķ�������ֱ���жϽ�Ҫ�����Ķ�����ص㡣�����ʹ������˵������ȽϺá�

����ģʽ���õ�һЩ�����������������³�������

1. ����Ĵ�������/ʵ����׼�������ܸ��ӣ���Ҫ��ʼ���ܶ��������ѯ���ݿ�ȡ�

2.�౾���кö����࣬��Щ��Ĵ���������ҵ�������׷����ı䣬���߶���ĵ������׷����ı䡣

���ߣ��ɿ����������
���ӣ�https://www.jianshu.com/p/38bd26a1f7ef
��Դ������
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
#if 0
//�򵥹���
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
//ȱ�����Ӳ�Ʒʱ��Ҫ�ı�CreateSingleCore����������ݣ�Υ��һ���޸�ԭ��
#elif 0
//��������
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
//��Ʒ��Ļ�������ǳ���
#elif 0
/*
���󹤳�
һ�����������������ƵĲ�Ʒ
*/
//���󵥺�
class SingleCore
{
public:
	virtual void Show() = 0;
};
//������
class MultiCore
{
public:
	virtual void Show() = 0;
};
//��A��
class SingleCoreA :public SingleCore
{
public:
	void Show()
	{
		std::cout << "SingleCore A" << std::endl;
	}
};
//��B��
class SingleCoreB :public SingleCore
{
public:
	void Show()
	{
		std::cout << "SingleCore B" << std::endl;
	}
};
//��A��
class MultiCoreA :public MultiCore
{
public:
	void Show()
	{
		std::cout << "MultiCore A" << std::endl;
	}
};
//��B��
class MultiCoreB :public MultiCore
{
public:
	void Show()
	{
		std::cout << "MultiCore B" << std::endl;
	}
};
//���󹤳�
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
//��Ʒ��Ļ�����Ҳ�ǳ���
#elif 0
/*
����Ҫ��������Ĺ����� =>����������ģʽ������ģ�����Ϊ��Ʒ��ģ�幤���࣬
����������Ʒ������������
*/
//����Shoes
class Shoes
{
public:
	virtual void Show() = 0;
	virtual ~Shoes() {}
};
//����Clothes
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
//����ģ�幤��
template<class AbstractProduct_t>
class AbstractFactory
{
public:
	virtual AbstractProduct_t* CreateProduct() = 0;
	virtual ~AbstractFactory(){}
};
//����ģ�幤��
template<class AbstractProduct_t,class ConcreteProduct_t>
class ConcreteFactory:public AbstractFactory<AbstractProduct_t>
{
public:
	ConcreteProduct_t* CreateProduct()
	{
		return new ConcreteProduct_t();
	}
};
//������ʱ��ػ�ȡ��Ʒ
#elif 1
/*
����ͳһ��ʱ��ػ�ȡָ���Ĳ�Ʒ����=> �Ѳ�Ʒע��Ĺ��ܷ�װ�ɲ�Ʒע��ģ����+�ѻ�ȡ��Ʒ����Ĺ��ܷ�װ�ɵ�������ģ����
*/
//����Shoes
class Shoes
{
public:
	virtual void Show() = 0;
	virtual ~Shoes() {}
};
//����Clothes
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
//����ģ��ע����
template<class ProductType_t>
class IProductRegistrar
{
public:
	virtual ProductType_t* CreateProduct() = 0;
	virtual ~IProductRegistrar() {}
};
//����ģ��ע����
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
//ģ�幤��
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
		std::cout << "û�иò�Ʒ"<<std::endl;
		return nullptr;
	}
private:
	std::unordered_map<std::string, IProductRegistrar<ProductType_t>*>map;
};
#endif
