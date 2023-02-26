#include <iostream>
#include"LinkedListStack.h"

void printLinkedListStack(LinkedListStack& target);
int main()
{
	LinkedListStack stack;

	for (int i = 0; i < 10; i++)
	{
		stack.push(i * 10);
	}



	printLinkedListStack(stack);
	std::cout << std::endl;
	printLinkedListStack(stack);
	return 0;
}
void printLinkedListStack(LinkedListStack& target)
{
	LinkedListStack hold;
	int data;
	while (!target.isEmpty())
	{
		data = target.pop();
		hold.push(data);
		std::cout << data << std::endl;
	}

	while (!hold.isEmpty())
	{

		data = hold.pop();
		target.push(data);
		//std::cout << data << std::endl;
	}
	data = NULL;
	
}
