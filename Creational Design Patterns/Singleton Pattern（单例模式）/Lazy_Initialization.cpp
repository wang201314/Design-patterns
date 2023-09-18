#include<iostream>
#include<mutex>
using namespace std;

mutex mtx;

class Singleton
{
public:
    static Singleton* GetInstance()
    {
        if (m_pInstance == NULL )
        {
            unique_lock<mutex>lock(mtx);// 加锁
            if (m_pInstance == NULL )
            {
                m_pInstance = new Singleton ();
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
            if(Singleton::m_pInstance) 
                delete Singleton::m_pInstance;
        }
    };
 
    static CGarbo Garbo; // 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
 
private:
    Singleton(){};
    Singleton(Singleton const&); 
    Singleton& operator=(Singleton const&); 
    
    static Singleton* m_pInstance;
};
 
Singleton* Singleton::m_pInstance = NULL;
Singleton::CGarbo Garbo;

int main()
{
    Singleton* newSingleton = Singleton::GetInstance();
	Singleton* newSingleton1 = Singleton::GetInstance();
    return 0;
}