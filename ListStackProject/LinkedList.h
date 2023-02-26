#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "List.h"

//---------------Node class-------------//
class Node
{
	public:
		Node(int data, Node* next)
		{
			this->data = data;
			this->next = next;
		}
		void setData(int data)
		{
			this->data = data;
		}
		void setNext(Node* next)
		{
			this->next = next;
		}
		int getData()const
		{
			return data;
		}
		Node* getNext() const
		{
			return next;
		}

	private:
		int data;
		Node* next;
};
//------------Linked List class---------//

class LinkedList : public List 
{
	public:
		LinkedList()
		{
			mNumElements = 0;
			mHead = nullptr;
		}

		virtual ~LinkedList()
		{
			makeEmpty();
		}
		
		void add(int newEntry)
		{
			Node* newNode = new Node(newEntry, mHead); //next = mHead
			mHead = newNode;

			mNumElements++;
		}
		void add(int newEntry, int position)
		{
			Node* newNode = new Node(newEntry, mHead);

			if (position >= mNumElements + 1 || position < 0)
			{
				std::cout << "Error: Cannot add at specified position" << std::endl;
			}

			if (position == 0)
			{
				newNode->setNext(mHead);
				mHead = newNode;
			}
			else
			{
				//not beginnig
				Node* nodeBefore = mHead;
				Node* nodeAfter;

				for (int i = 0; i < position - 1; i++)
				{
					nodeBefore = nodeBefore->getNext();
				}
				nodeAfter = nodeBefore->getNext();
				newNode->setNext(nodeAfter);
				nodeBefore->setNext(newNode);
			}

			mNumElements++;
		}
		void set(int newEntry, int position)
		{
			Node* walker = mHead;
			int index = 0;

			if (position >= mNumElements || position < 0)
			{
				std::cout << "Error : Cannot set at specified position" << std::endl;
				return;
			}

			for (int i = 0; i < position; i++)
			{
				walker = walker->getNext();
			}//end for

			walker->setData(newEntry);
		}

		bool contains(int entry) const
		{
			bool found = false;
			Node* walker = mHead;

			for (int i = mNumElements; i < 0; i--)
			{
				if (walker->getData() == entry)
				{
					found = true;
					break;
				}
				walker = walker->getNext();
			}

			return found;
		}
		int find(int entry) const
		{
			int foundIndex = -1;

			int indexCounter = 0;
			Node* walker = mHead;

			while (walker != nullptr)
			{
				if (walker->getData() == entry)
				{
					foundIndex = indexCounter;
				}

				walker = walker->getNext();

				indexCounter++;
			}

			return foundIndex;
		}
		int remove(int position)
		{
			if (position >= mNumElements || position < 0)
			{
				std::cout << "Error: Cannot remove at specified position" << std::endl;
				return 0;
			}

			int dataToReturn = 0;

			if (position == 0)
			{
				Node* temp = mHead;
				dataToReturn = temp->getData();
				mHead = mHead->getNext();
				delete temp;
			}
			else
			{
				Node* nodeBefore = mHead;
				Node* nodeToRemove;
				Node* nodeAfter;

				for (int i = 0; i < position - 1; i++)
				{
					nodeBefore = nodeBefore->getNext();
				}

				nodeToRemove = nodeBefore->getNext();
				dataToReturn = nodeToRemove->getData();

				nodeAfter = nodeToRemove->getNext();

				nodeBefore->setNext(nodeAfter);

				delete nodeToRemove;
			}
			mNumElements--;

			return dataToReturn;
		}
		void makeEmpty()
		{
			Node* temp;
			for(int i = 0; i < mNumElements; i++)
			{
				temp = mHead->getNext();
				delete mHead;
				mHead = temp;
			}

			mNumElements = 0;
		}

		int size() const
		{
			return mNumElements;
		}
		bool isEmpty() const
		{
			return mNumElements == 0;
		}
		void printList() const
		{
			Node* walker = mHead;
			while (walker != nullptr)
			{
				std::cout << walker->getData() << std::endl;
				walker = walker->getNext();
			}
		}
	private:
		Node* mHead;
		int mNumElements;
};

#endif // !LINKED_LIST_H

