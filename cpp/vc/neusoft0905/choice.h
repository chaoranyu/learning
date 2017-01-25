#include <iostream>
using namespace std;

void test5();
int test6a();
int test6b();
void test6();
void test7();

class CInner
{
public:
	CInner(){ cout << "CInner Construct" << endl; }
	~CInner(){ cout << "CInner Destruct" << endl; }
};

class CBase
{
public:
	CBase(){ cout << "CBase Construct" << endl; }
	~CBase(){ cout << "CBase Destruct" << endl; }
};

class CChild : public CBase
{
public:
	CChild(){ cout << "CChild Construct" << endl; }
	~CChild(){ cout << "CChild Destruct" << endl; }
private:
	CInner m_inner;
};

