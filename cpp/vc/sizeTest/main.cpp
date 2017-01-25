#include <iostream>
using namespace std;

class A
{
	virtual void aa(){};
};

class B : public virtual  A
{
	char j[3];     //加入一个变量是为了看清楚class中的vfptr放在什么位置
public:
	virtual void bb(){};
};

class C : public virtual B
{
	char i[3];
public:
	virtual void cc(){};
};



class Base {
public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};

class Derive : public Base {
public:
	void f() { cout << "Derive::f" << endl; }
	void g() { cout << "Derive::g" << endl; }
	void h() { cout << "Derive::h" << endl; }
	virtual void h1() { cout << "Derive::h" << endl; }
};
void test1()
{
	typedef void(*Fun)(void);
	Base b;
	Derive d;
	Fun pFun = NULL;

	cout << "虚函数表地址：" << (int*)(&b) << endl;
	cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;

	// Invoke the first virtual function 
	pFun = (Fun)*((int*)*(int*)(&b));
	pFun();
}

int main()
{
	A a;
	B b;
	C c;
	cout << sizeof(A) << ", " << sizeof(B) << ", " << sizeof(C) << endl;

	cout << sizeof(Base) << endl;
	cout << sizeof(Derive) << endl;
	test1();


	return 0;
}
