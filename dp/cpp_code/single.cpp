#include <iostream>

class Singleton
{
public:
	static Singleton *instance()
	{
		if (instance_ == NULL)
		{
			instance_ = new Singleton();
		}
		return instance_;
	}

private:
	Singleton(){}
	~Singleton();
	Singleton(const Singleton&);
	Singleton operator=(const Singleton&);

private:
	static Singleton *instance_;
};

Singleton *Singleton::instance_ = NULL;


int main()
{
	Singleton *test = Singleton::instance();


	return 0;
}
