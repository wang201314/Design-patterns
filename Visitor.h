#pragma once
#include <iostream>
#include <string>
#include <list>
/*
һ��/��������һ������࣬ǿ�����ʲ���
*/
class Apple;
class Book;
//���������
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
//���������
class Customer :public Vistor
{
public:
	void visit(Apple*apple) override
	{
		std::cout << "�˿�:" << name_ << "��ѡƻ����" << std::endl;
	}
	void visit(Book*book) override
	{
		std::cout << "�˿�:" << name_ << "���顣" << std::endl;
	}
};
class Saler :public Vistor
{
public:
	void visit(Apple*apple) override
	{
		std::cout << "����Ա:" << name_ << "����ƻ���۸�" << std::endl;
	}
	void visit(Book*book) override
	{
		std::cout << "����Ա:" << name_ << "������ļ۸�" << std::endl;
	}
};
//������Ʒ
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
������ģʽ�ʺ�Ӧ�ó���
 �������Ҫ��һ�����Ӷ���ṹ ������������� �е�����Ԫ��ִ��ĳЩ������ ��ʹ�÷�����ģʽ��

 ������ģʽͨ���ڷ����߶�����Ϊ���Ŀ�����ṩ��ͬ�����ı��壬 �����������ڲ�ͬ���һ�������ִ��ͬһ������

 ��ʹ�÷�����ģʽ����������Ϊ��ҵ���߼���

 ��ģʽ�Ὣ���з���Ҫ����Ϊ��ȡ��һ����������У� ʹ�ó������Ҫ���ܸ�רע����Ҫ�Ĺ�����

 ��ĳ����Ϊ�������νṹ�е�һЩ���������壬 ������������û������ʱ�� ��ʹ�ø�ģʽ��

 ��ɽ�����Ϊ��ȡ�������ķ��������У� ֻ��ʵ�ֽ��������Ķ�����Ϊ�����ķ����߷������������������ռ��ɡ�



 ��������߼̳г������ʵ����Ҫ���ʲ�Ʒ�ķ��ʷ��������������صģ����ڲ�ͬ�Ĳ�Ʒ����ʵ�ֲ�ͬ�ķ��ʷ�����
 ����������һ�����ܷ��ʵĵķ��������ö�̬�Խ��Լ���Ϊ�������ݸ������ߵ��õķ��ʺ���
*/