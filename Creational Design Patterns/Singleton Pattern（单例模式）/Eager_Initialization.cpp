#include<iostream>
class Singleton
{
public:
 
    static Singleton* GetInstance()
    {
        return &m_instance;
    }
 
private:
    Singleton(){};
    Singleton(Singleton const&) = delete; 
    Singleton& operator=(Singleton const&) = delete; 
 
    static Singleton m_instance;
};
 
Singleton Singleton::m_instance;  // 在程序入口之前就完成单例对象的初始化
// int main()
// {
//     Singleton* newSingleton = Singleton::GetInstance();
//     return 0;
// }