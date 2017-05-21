/*********用过程编程的方法实现FSM程序源代码*******/
#include <iostream>
using namespace std;

const int MaxStates=3;
const int MaxEvents=3;

const int StateA=0;
const int StateB=1;
const int StateC=2;

const int EventA=0;
const int EventB=1;
const int EventC=2;

int Noop();
int StateAEventA();
int StateAEventB();
int StateBEventA();
int StateBEventC();
int StateCEventA();

int state;

typedef int (*Action)();

Action sm[MaxStates][MaxEvents]={{StateAEventA,StateAEventB,Noop},{StateBEventA,Noop,StateBEventC},{StateCEventA,Noop,Noop}};
int Noop()
{
	cout<<"No Transition"<<endl;
	return state;
};
int StateAEventA()
{
	cout<<"stateA----->stateB"<<endl;
	return StateB;
};
int StateAEventB()
{
	cout<<"stateA----->stateC"<<endl;
	return StateC;
};
int StateBEventA()
{
	cout<<"stateB----->stateC"<<endl;
	return StateC;
};
int StateBEventC()
{
	cout<<"stateB------>stateA"<<endl;
	return StateA;
};
int StateCEventA()
{
	cout<<"stateC------>stateA"<<endl;
	return StateA;
};
int main()
{
	int event;
	state=StateA;
	while(1)
	{
		cout<<"type event:(0-3)"<<endl;
		cin>>event;
		if((event>=0)&&(event<3))
		{
			state=sm[state][event]();
		}
		else
		{
			cout<<"Unknow event"<<endl;
		}
	}
    return 0;
}
