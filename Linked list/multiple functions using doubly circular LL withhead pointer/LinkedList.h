#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList
{
protected:
	Node* tail;
public:
	LinkedList();
	virtual void insertAtTail(int) = 0;
	virtual void insertAtHead(int) = 0;
	virtual void display() = 0;
	virtual int deleteFromHead() = 0;
	virtual int deleteFromTail() = 0;
	virtual bool isEmpty() = 0;
	virtual int findKthToLast(int k) = 0;
};

LinkedList::LinkedList()
{
	tail = nullptr;
}
