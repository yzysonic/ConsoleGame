#pragma once

template<class T>
class Singleton
{
public:
	static void Destroy(void)
	{
		delete instance;
		instance = nullptr;
	}

	static T* GetInstance(void)
	{
		if (instance == nullptr)
			instance = new T;

		return instance;
	}

	virtual ~Singleton(void) {};

protected:
	static T* instance;

	Singleton(void) {}
};

template<class T>
T* Singleton<T>::instance = nullptr;