#include <iostream>

template <class T>
class ShiftedList {
	T* array;
	int offset, size;
public:
	ShiftedList(int sz) : offset(0), size(sz) {
		array = new T[size];
	}

	~ShiftedList() {
		delete [] array;
	}

	void shiftBy(int n) {
		offset = (offset + n) % size;
	}

	T getAt(int i) {
		return array[convertIndex(i)];
	}

	T setAt(T item, int i) {
		array[convertIndex(i)] = item;
	}

private:
	int convertIndex(int i) {
		int index = (i - offset) % size;
		while (index < 0) index += size;
		return index;
	}
};

int main()
{
	int size = 4;
	ShiftedList<int> *list = new ShiftedList<int>(size);
	for (int i = 0; i <  size; i++) {
		list->setAt(i, i);
	}
	std::cout << list->getAt(0) << std::endl;
	std::cout << list->getAt(1) << std::endl;
	list->shiftBy(1);
	std::cout << list->getAt(0) << std::endl;
	std::cout << list->getAt(1) << std::endl;
	delete list;

	return 0;
}
