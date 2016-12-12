#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	Node(T value): m_value(value), m_next(0) {}
	~Node();

	T GetValue() const { return m_value; }
	void SetValue(T value) { m_value = value; }
	Node<T> * GetNext() const { return m_next; }
	void SetNext(Node<T> * next) { m_next = next; }
private:
	T m_value;
	Node<T> *m_next;
};

template <class T>
Node<T>::~Node()
{
	cout << m_value << " deleted" << endl;
	if (m_next)
		delete m_next;
}

template <class T>
class Stack
{
public:
	Stack(): m_head(0), m_count(0) {}
	~Stack() { delete m_head; }

	void Push(const T &value);
	T Pop();
	T Top() const;
	int Count() const;
private:
	Node<T> *m_head;
	int m_count;
};

template <class T>
void Stack<T>::Push(const T &value)
{
	Node<T> *newNode = new Node<T>(value);
	newNode->SetNext(m_head);
	m_head = newNode;
	m_count++;
}

template <class T>
T Stack<T>::Pop()
{
	Node<T> *popped = m_head;
	if (m_head != 0)
	{
		m_head = m_head->GetNext();
		T retval = popped->GetValue();
		popped->SetNext(0);
		delete popped;
		m_count--;
		return retval;
	}
	return 0;
}

template <class T>
inline T Stack<T>::Top() const
{
	return m_head->GetValue();
}

template <class T>
inline int Stack<T>::Count() const
{
	return m_count;
}
