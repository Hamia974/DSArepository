struct Node
{
	int data;
	Node* next;
};
LinkedList.h
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

myLL.h
#include "LinkedList.h"
class myLL :public LinkedList
{
	
public:
	void insertAtTail(int);
	void insertAtHead(int);
	void display();
	int deleteFromHead();
	int deleteFromTail();
	bool isEmpty();
	int findKthToLast(int k);
};
int myLL::findKthToLast(int k){
	//counting nodes
	int count = 0;
	Node* t = tail->next;
	while (true)
	{
		count++;
		t = t->next;

		if (t == tail->next)
			break;
	}
	//findingKthTolast
	if (k >= count){
		return -1;
	}
	else{
		int num = count - k;
		Node* t = tail->next;
		for (int i = 0; i < num; i++){
			t = t->next;
		}
		return t->data;
	}
	
}
int myLL::deleteFromHead()
{
	if (tail == nullptr)
		return NULL;

	else if (tail->next == tail)
	{
		int rV = tail->data;
		delete tail;
		tail = nullptr;
		return rV;
	}

	else
	{
		Node*t = tail->next;
		tail->next = t->next;
		int rV = t->data;
		delete t;
		t = nullptr;
		return rV;
	}
}


int myLL::deleteFromTail()
{
	if (tail == nullptr)
		return NULL;

	else if (tail->next == tail)
	{
		int rV = tail->data;
		delete tail;
		tail = nullptr;
		return rV;
	}

	else
	{
		Node*t = tail->next;
		while (true)
		{
			if (t->next == tail)
				break;

			t = t->next;
		}

		int rV = tail->data;
		t->next = tail->next;
		delete tail;
		tail = t;
		return rV;
	}
}

bool myLL::isEmpty()
{
	return (tail == nullptr);
}

void myLL::display()
{
	if (tail == nullptr)
		cout << "LL is empty" << endl;

	else
	{
		Node* t = tail->next;
		while (true)
		{
			cout << t->data << "->";
			t = t->next;

			if (t == tail->next)
				break;
		}

	}
}

void myLL::insertAtHead(int value)
{
	Node* nn = nullptr;
	nn = new Node;
	nn->next = nullptr;
	nn->data = value;

	if (tail == nullptr)
	{
		tail = nn;
		tail->next= tail;
	}

	else
	{
		nn->next = tail->next;
		tail->next = nn;
	}

}


void myLL::insertAtTail(int value)
{
	Node* nn = nullptr;
	nn = new Node;
	nn->next = nullptr;
	nn->data = value;

	if (tail == nullptr)
	{
		tail = nn;
		tail->next = tail;
	}

	else
	{
		nn->next = tail->next;
		tail->next = nn;
		tail = nn;
	}

}

Main.cpp
#include "myLL.h"
int main()
{
	myLL obj;
	obj.insertAtTail(1);
	obj.insertAtTail(2);
	obj.insertAtTail(3);
	obj.insertAtTail(4);
	obj.insertAtTail(5);
	obj.insertAtTail(6);
	obj.insertAtTail(7);
	obj.insertAtTail(8);
	obj.insertAtTail(9);
	obj.insertAtTail(10);
	obj.display();
	int k;
	cout << "\nenter kth element: ";
	cin >> k;
	cout << "Result: " << obj.findKthToLast(k) << endl;
	return 0;
}
