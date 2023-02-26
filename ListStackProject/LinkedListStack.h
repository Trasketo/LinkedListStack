#ifndef LINKED_LIST_STACK
#define LINKED_LIST_STACK
#include"Stack.h"
#include"LinkedList.h"

class LinkedListStack : public Stack
{
public:
	LinkedListStack();
	~LinkedListStack();

	void push(int newEntry)
	{
		list.add(newEntry);
	}
	int pop()
	{
		return list.remove(0);
	}
	int peek()
	{
		if (this->isEmpty() != true)
		{
			int data = list.remove(0);
			list.add(data);
			return data;
		}
		else
		{
			std::cout << "stack empty";
			return -1;
		}
	}
	bool isEmpty()const
	{
		return list.isEmpty();
	}
	void makeEmpty()
	{
		list.makeEmpty();
	}

private:
	LinkedList list;
};

LinkedListStack::LinkedListStack()
{
}

LinkedListStack::~LinkedListStack()
{

}
#endif // !LINKED_LIST_STACK
