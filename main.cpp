#include<iostream>
#include"Design-patterns.h"
using namespace std;
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Singleton::Garbo;
int main()
{
#if 0
//��������
	auto test = []()
	{

		Singleton* newSingleton = Singleton::GetInstance();
		Singleton* newSingleton1 = Singleton::GetInstance();
	};
	test();
	//int a;
	//cin >> a;
#elif 0
//��������
	ConcreteFactory<Shoes, NikeShoes>SFactory;
	Shoes* s = SFactory.CreateProduct();
	s->Show();
	ConcreteFactory<Shoes, adidasShoes>AFactory;
	s = AFactory.CreateProduct();
	s->Show();
	ConcreteFactory<Clothes, UniClothes>UFactory;
	Clothes* c = UFactory.CreateProduct();
	c->Show();
#elif 0
	//������������
	ProductRegistrar<Shoes, NikeShoes>NRegistrar("nike");	
	Shoes* s = ProductFactory<Shoes>::Instance().GetProduct("nike");
	s->Show();
	ProductRegistrar<Shoes, adidasShoes>ARegistrar("adidasShoes");
	s = ProductFactory<Shoes>::Instance().GetProduct("adidasShoes");
	s->Show();
	ProductRegistrar<Clothes, UniClothes>URegistrar("UniClothes");
	Clothes* c = ProductFactory<Clothes>::Instance().GetProduct("UniClothes");
	c->Show();
#elif 0
	//�����߲���
	Book book;
	Apple apple;
	ShoppingCart basket;
	basket.addProduct(&book);
	basket.addProduct(&apple);
	Customer customer;
	customer.set_name("С��");
	basket.accept(&customer);
	Saler saler;
	saler.set_name("С��");
	basket.accept(&saler);
#elif 1
	//�۲��߲���
	Cat cat;
	AbstractObserver* mouse = new Mouse;
	AbstractObserver* dog = new Dog;
	cat.attach(mouse);
	cat.attach(dog);
	cat.cry();
	cat.detach(dog);
	cat.cry();
	cat.detach(mouse);
	cat.cry();
#endif // 0

	
	return 0;
}

