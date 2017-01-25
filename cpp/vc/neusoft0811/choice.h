#ifndef __CHOICE_H__
#define __CHOICE_H__
//#pragma once

#include <iostream>
using namespace std;

//int lala;
void test2();
void test6();
void test9();
void test10();
void test15();

class Base6
{
public:
	Base6(){};
	~Base6(){};
};
//class CDemo : public Base6
class CDemo
{
public:
	CDemo() {}
	virtual ~CDemo() {}
protected:
	static int m_siObjCnt;
	Base6 m_ob;
};

template <typename T>
class Complex{
private:
	T t;
};

class Base
{
public:
	virtual void f(int iParam){
		cout << "Base::f(int)" << endl;
	};
	virtual void f(double dParam){
		cout << "Base::f(double)" << endl;
	};
	virtual void g(int i = 10){
		cout << i << endl;
	};
};

class Derived : public Base
{
public:
	//virtual void f(Complex<double> Param){
	void f(Complex<double> Param){
		cout << "Derived::f(complex)" << endl;
	};
	void g(int i = 20){
		cout << "Derived::g() " << i << endl;
	};
};

class CBaseClass
{
public:
	CBaseClass(){
		Init();
	}
	~CBaseClass(void){};

	virtual int Init(void){
		m_iInitVar = 1;
		return 0;
	}

	int GetResult(void){
		return m_iInitVar;
	}
	int m_iInitVar;
};

class CDerivedClass : public CBaseClass
{
public:
	CDerivedClass(void) {};
	//CDerivedClass(void) { Init(); };
	~CDerivedClass(void) {};
	virtual int Init(void)	{
		m_iInitVar = 2;
		return 0;
	}
};

#endif // __CHOICE_H__