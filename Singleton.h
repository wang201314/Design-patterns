#pragma once
#include<iostream>
#include<mutex>
//单例模式，创建型设计模式，为了避免对象的频繁创建和销毁，全局都使用一个对象。
#if 1
//Lazy_Initialization 双检测锁
static std::mutex mtx;
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (m_pInstance == NULL)
		{
			std::unique_lock<std::mutex>lock(mtx);// 加锁
			if (m_pInstance == NULL)
			{
				m_pInstance = new Singleton();
			}
			lock.unlock(); // 解锁
		}
		return m_pInstance;
	}

	// 实现一个内嵌垃圾回收类    
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};

	static CGarbo Garbo; // 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象

private:
	Singleton()
	{
		std::cout << "--------------------Singleton 构造函数-------------------------------" << std::endl;
	};
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
	~Singleton()
	{
		std::cout << "--------------------Singleton 析构函数-------------------------------" << std::endl;
	};
	static Singleton* m_pInstance;
};
#elif 0
//C++11新特性局部静态变量是线程安全的
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		static Singleton m_pInstance;
		return &m_pInstance;
	}
private:
	Singleton()
	{
		std::cout << "--------------------Singleton 构造函数-------------------------------" << std::endl;
	};
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
	~Singleton()
	{
		std::cout << "--------------------Singleton 析构函数-------------------------------" << std::endl;
	};
};
#elif 1
//Eager_Initialization
class Singleton
{
public:

	static Singleton* GetInstance()
	{
		return &m_instance;
	}

private:
	Singleton()
	{
		std::cout << "--------------------Singleton 构造函数-------------------------------" << std::endl;
	};
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
	~Singleton()
	{
		std::cout << "--------------------Singleton 析构函数-------------------------------" << std::endl;
	};
	static Singleton m_instance;
};

Singleton Singleton::m_instance;  // 在程序入口之前就完成单例对象的初始化
#endif // 1
