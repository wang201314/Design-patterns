#pragma once
#include <iostream>
#include <string>
#include <vector>

#if 1
class AbstractObserver
{
public:
	virtual void respose() = 0;
};

class Mouse : public AbstractObserver
{
public:
	void respose() override
	{
		std::cout << "ÀÏÊóÌÓÅÜ" << std::endl;
	}				
};

class Dog : public AbstractObserver
{
public:
	void respose() override
	{
		std::cout << "¹·×·Ã¨" << std::endl;
	}
};

class Cat
{
public:
	void attach(AbstractObserver* observer)
	{
		observers.push_back(observer);
	}
	void detach(AbstractObserver* observer)
	{
		for (auto it=observers.begin();it!= observers.end();it++)
		{
			if (*it == observer)
			{
				observers.erase(it);
				break;
			}
		}
	}
	void cry()
	{
		for (auto& it:observers)
		{
			it->respose();
		}
	}
private:
	std::vector<AbstractObserver*>observers;
};
#elif 1

#endif // 1
