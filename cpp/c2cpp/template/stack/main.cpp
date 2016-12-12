#include "stack.h"

int main(void)
{
	Stack<int> intstack;
	Stack<char> charstack;

	intstack.Push(1);
	intstack.Push(2);
	intstack.Push(3);
	intstack.Push(4);
	while (intstack.Count())
		cout << intstack.Pop() << endl;
	
	charstack.Push('A');
	charstack.Push('B');
	charstack.Push('C');
	cout << "Now charstack will self destruct" << endl;

	return 0;
}
