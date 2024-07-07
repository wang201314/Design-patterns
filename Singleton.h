#pragma once
#include<iostream>
#include<mutex>
//����ģʽ�����������ģʽ��Ϊ�˱�������Ƶ�����������٣�ȫ�ֶ�ʹ��һ������
#if 1
//Lazy_Initialization ˫�����
static std::mutex mtx;
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (m_pInstance == NULL)
		{
			std::unique_lock<std::mutex>lock(mtx);// ����
			if (m_pInstance == NULL)
			{
				m_pInstance = new Singleton();
			}
			lock.unlock(); // ����
		}
		return m_pInstance;
	}

	// ʵ��һ����Ƕ����������    
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};

	static CGarbo Garbo; // ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������

private:
	Singleton()
	{
		std::cout << "--------------------Singleton ���캯��-------------------------------" << std::endl;
	};
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
	~Singleton()
	{
		std::cout << "--------------------Singleton ��������-------------------------------" << std::endl;
	};
	static Singleton* m_pInstance;
};
#elif 0
//C++11�����Ծֲ���̬�������̰߳�ȫ��
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
		std::cout << "--------------------Singleton ���캯��-------------------------------" << std::endl;
	};
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
	~Singleton()
	{
		std::cout << "--------------------Singleton ��������-------------------------------" << std::endl;
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
		std::cout << "--------------------Singleton ���캯��-------------------------------" << std::endl;
	};
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
	~Singleton()
	{
		std::cout << "--------------------Singleton ��������-------------------------------" << std::endl;
	};
	static Singleton m_instance;
};

Singleton Singleton::m_instance;  // �ڳ������֮ǰ����ɵ�������ĳ�ʼ��
#endif // 1
