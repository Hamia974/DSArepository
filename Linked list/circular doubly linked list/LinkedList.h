#include <iostream>
#include "Node.h"
using namespace std;
class LinkedList
{
protected:
	Node* head;
	Node* tail;
public:
	LinkedList(){
		head = nullptr;
		tail = nullptr;
	}
	virtual void insertAtTail(int) = 0;
	virtual void insertatHead(int) = 0;
	virtual bool isempty() = 0;
	virtual void recursiveInsertion(Node* t, int position, int value, int count = 1) = 0;
	virtual void insertAtPosition(int position, int value) = 0;
	virtual void printListRecursive(Node* t, Node* head) = 0;
	virtual void printList() = 0;
};


