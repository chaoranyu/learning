
void test11();
void test13();
void test15();
void test30();

class ClassA
{
public:
	virtual void foo(int i)
	{
		cout << "void CA::foo(int i)" << endl;
	}
};
class ClassB : public ClassA
{
public:
	virtual void foo(int i)
	{
		cout << "void CB::foo(int i)" << endl;
	}

	virtual void foo(double d)
	{
		cout << "void CB::foo(double d)" << endl;
	}
};

// test13
class CA
{
public:
	CA(void) { ++CA::ms_iCounter; }
	~CA(void) { --CA::ms_iCounter; }

	static int ms_iCounter;
};

// test15
class Base
{
public:
	void h(float x){ cout << "Base::h(float) " << x << endl; }
};
class Derived : public Base
{
public:
	void h(float x){ cout << "Derived::h(float) " << x << endl; }
};