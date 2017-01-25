#include <iostream>
using std::cout;
using std::endl;
//using namespace::std;

void choice2()
{
	int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };

	cout << a[1][1] << endl;
	cout << *(a[1] + 1) << endl;
	cout << *(&a[1][1]) << endl;
	cout << (*(a + 1))[1] << endl;
	cout << (a + 5) << endl;
}

// choice7
class Bezaa; // Forward declaration of class Bezaa in order for example to compile.
class Aazaa
{
private:
	int a;
public:
	Aazaa() { a = 0; }
	void show(Aazaa& x, Bezaa& y);
	friend void show(Aazaa& x, Bezaa& y); // declaration of global friend
};

class Bezaa
{
private:
	int b;
public:

	Bezaa() { b = 6; }
	friend void show(Aazaa& x, Bezaa& y); // declaration of global friend
	friend void Aazaa::show(Aazaa& x, Bezaa& y); // declaration of friend from other class 
};

// Definition of a member function of Aazaa; this member is a friend of Bezaa
void Aazaa::show(Aazaa& x, Bezaa& y)
{
	cout << "Show via function member of Aazaa" << endl;
	cout << "Aazaa::a = " << x.a << endl;
	cout << "Bezaa::b = " << y.b << endl;
}

// Friend for Aazaa and Bezaa, definition of global function
void show(Aazaa& x, Bezaa& y)
{
	cout << "Show via global function" << endl;
	cout << "Aazaa::a = " << x.a << endl;
	cout << "Bezaa::b = " << y.b << endl;
}

void choice7()
{
	Aazaa a;
	Bezaa b;

	show(a, b);
	a.show(a, b);
}

// choice10
class Aa
{
private:
	static int aa;
public:
	//Aa() : aa(4) {}
	//Aa(){ aa = 9; }  // can be compiled, but not be excuted
	void print(){ cout << "aa = " << aa << endl; }
};

int Aa::aa = 3;

void choice10()
{
	Aa a;
	a.print();
}

// chioce12
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (NULL == _instance)
		{
			_instance = new Singleton();
		}
		return _instance;
	}

protected:
	Singleton(){};
	static Singleton* _instance;
};

Singleton* Singleton::_instance = NULL;

void choice12()
{
	Singleton s(*Singleton::GetInstance());
	Singleton s1(*Singleton::GetInstance());
	Singleton s2(*Singleton::GetInstance());
}

// choice13
class A
{
public:
	static int a;
};

int A::a = 0;

class B : public A
{
public:
	virtual int get_num()
	{
		return a;
	}

private:
	char *p;
};

class C : public B
{
public:
	int get_num()
	{
		return 2 * a;
	}

private:
	B b;
};

void choice13()
{
	cout << sizeof(A) << ", " << sizeof(B) << ", " << sizeof(C) << endl;
	A a;
	B b;
	C c;
	cout << sizeof(a) << ", " << sizeof(b) << ", " << sizeof(c) << endl;
}

// choice14
void choice14()
{
	int s(1), t(2);
	int * const p1 = &s;
	int const * p2 = &s;
	const int * p3 = &s;

	//p1 = &t;      	//¢Ù
	*p1 = t;       	//¢Ú
	(int*)p1 = &t; 	//¢Û
	p2 = &t;       	//¢Ü
	//*p2 = t;       	//¢Ý
	p2 = (int*)&t; 	//¢Þ
	p3 = &t;       	//¢ß
	//*p3 = t;       	//¢à
}

class AA
{
public:
	AA(int i){ cout << "A "; }
	~AA(){}
};

class BB
{
public:
	BB(int j){ cout << "B "; }
	~BB(){}
};

class CC
{
public:
	CC(int k){ cout << "C "; }
	virtual ~CC(){ cout << "~C "; }
	//~CC(){ cout << "~C "; }
};

class DD : public CC
{
public:
	DD(int i, int j, int k) :a(i), b(j), CC(k){ cout << "D "; }
	~DD(){ cout << "~D "; }

private:
	BB b;
	AA a;
};

int choice15()
{
	CC* pc = new DD(1, 2, 3);
	delete pc;
	//DD pd(1, 2, 3);

	return 0;
}


void choice21()
{
	int i, x1, y1, x2, y2, x3, y3, x4, y4;
	i = 3;
	x1 = y1 = x2 = y2 = x3 = y3 = x4 = y4 = 0;

	i > 4 ? ++x1 : ++y1;
	cout << "x1 = " << x1 << ", y1 = " << y1 << endl;
	i > 1 ? ++x2 : ++y2;
	cout << "x2 = " << x2 << ", y2 = " << y2 << endl;
	i > 4 ? x3++ : y3++;
	cout << "x3 = " << x3 << ", y3 = " << y3 << endl;
	i > 1 ? x4++ : y4++;
	cout << "x4 = " << x4 << ", y4 = " << y4 << endl;
}

//
class Base1
{
public:
	int a;
private:
	char b;
};
class Derive1 : public Base1
{
public:
	char c;
	int d;
};

void choice22()
{
	cout << sizeof(Base1) << ", " << sizeof(Derive1) << endl;
}

void cchoice8()
{
	char a[3][4] = { "aaa", "bb", "ccc" };
	char(*q)[4] = a;
	int i;
	*(*q + 3) = 'b';
	for (i = 0; i < 3; i++)
	{
		printf("%s", q[i]);
	}
}