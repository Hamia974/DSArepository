Node.h
struct Node
{
	int data;
	Node* next;
	Node* prev;
};
LinkedList.h
#include <iostream>
#include "Node.h"
using namespace std;
class LinkedList
{
protected:
	Node* head;
public:
	LinkedList();
	virtual void insertAtTail(int) = 0;
	virtual void insertatHead(int) = 0;
	virtual void display() = 0;
	virtual int deleteFromHead() = 0;
	virtual int deleteFromTail() = 0;
	virtual bool isEmpty() = 0;
	virtual bool deleteValue(int) = 0;
	virtual void insertSorted(int) = 0;
};

LinkedList::LinkedList()
{
	head = nullptr;
}

DCLL.h
#include "LinkedList.h"
class DCLL :public LinkedList
{
public:
	void insertAtTail(int value){
		Node* nn = new Node;
		nn->data = value;
		nn->next = nullptr;
		nn->prev = nullptr;
		if (head == nullptr){
			head = nn;
			nn->prev = nn;
			nn->next = nn;
		}
		else{
			nn->next = head;
			nn->prev = head->prev;
			head->prev = nn;
			head->prev->prev->next = nn;
		}
	}
	void insertatHead(int value){
		Node* nn = new Node;
		nn->data = value;
		nn->next = nullptr;
		nn->prev = nullptr;
		if (head == nullptr){
			head = nn;
			nn->prev = nn;
			nn->next = nn;
		}
		else{
			nn->prev = head->prev;
			nn->next = head;
			head->prev->next = nn;
			head->prev = nn;
			head = nn;
		}	
	}
	void display(){
			if (head == nullptr)
				cout << "LL is empty" << endl;
			else
			{
				Node* t = head;
				while (true)
				{
					cout << t->data;
					t = t->next;
					if (t == head)
						break;
					cout << "->";
				}
			}
		}
	int deleteFromHead(){
		if (head == nullptr) {
			return NULL;
		}
		else if (head->next==head){
			int rv = head->data;
			delete head;
			head = nullptr;
			return rv;
		}
		else{
			int rv = head->data;
			head->prev->next = head->next;
			head->next->prev = head->prev->next;
			delete head;
			return rv;
		}
	}
	int deleteFromTail(){
		if (head == nullptr){
			return NULL;
		}	
		else if (head->next==head){
			int rv = head->data;
			delete head;
			head = nullptr;
			return rv;
		}
		else{

			int rv = head->prev->data;
			head->prev = head->prev->prev; 
			delete head->prev->next;
			head->prev->next = head; 
			
			return rv;
		}
	}
	bool isEmpty(){
		return (head == nullptr);
	}
	bool deleteValue(int value){
			if (head == nullptr )
				return false;
			else if (value == head->data)
			{
				deleteFromHead();
				return true;
			}
			else if (value == head->prev->data)
			{
				deleteFromTail();
				return true;
			}
			else
			{
				Node* t = head;
				while (true){
					if (t->data == value){
						break;
					}
					t = t->next;
				}
				t->prev ->next = t->next;
				t->next->prev = t->prev;
				delete t;
				t = nullptr;
				return true;
			}
   }
	void insertSorted(int value){
		if (head == nullptr)
		{
			Node* nn = new Node;
			nn->data = value;
			nn->next = nn;
			nn->prev = nn;
			head = nn;
		}
		else if (value <= head->data)
		{
			insertatHead(value);
		}

		else if (value >= head->prev->data)
		{
			insertAtTail(value);
		}

		else
		{
			Node* nn = new Node;
			nn->data = value;
			nn->next = nullptr;
			nn->prev = nullptr;
			Node* t = head;
			while (true)
			{
				if (t->data < value && t->next->data >= value)
					break;

				else
					t = t->next;

			}

			nn->next = t->next;
			nn->prev = t;
			nn->next->prev = nn;
			nn->prev->next = nn;
			
		}
	}
	//maximum element
	void maximum(){
		int max = head->data;
		Node* t = head;
		while (true){
			if (t->data > max){
				max = t->data;
			}
			else{
				t = t->next;
			}
			if (t == head){
				break;
			}
		}
		cout << "maximum element in linked list is: " << max << endl;
	}
	//factorial 
	int fact(int num){
		if (num > 0){
			return num*fact(num - 1);
		}
		if (num == 0){
			return 1;
		}
	}
	void printfactorials(){
		Node* t = head;
		while (true){
			cout << "Factorial of " << t->data << " is: " << fact(t->data) << endl;		
				t = t->next;		
			if (t == head){
				break;
			}
		}
	}
	//second maximum
	void secondmax(){
		int max = 0;
		int sec_max = 0;
		Node* t = head;
		while (true){
			if (t->data > max){
				sec_max = max;
				max = t->data;
			}		
			if (t->data > sec_max && t->data < max){
				sec_max = t->data;
			}
				t = t->next;			
			if (t == head){
				break;
			}
		}
		cout << "maximum element in linked list is: " << max << endl;
		cout << "second maximum element in linked list is: " << sec_max << endl;
	}
	//sum of all values
	void sum(){
		Node* t = head;
		int sum = 0;
		while (true){
			sum += t->data;
			t = t->next;
			if (t == head)
				break;
		}
		cout << "sum of all values are: " << sum << endl;
	}
	//delete even nodes
	void deleteeven(){
		Node* t = head;

		while (true){
			if (t->data % 2 == 0){
				t->prev->next = t->next;
				t->next->prev = t->prev;
			}
			t = t->next;
			if (t == head)
				break;
		}
		cout << "after deletion: ";
		display();
	}
	//sort linked list
	void sort(){
		for (Node* i = head; i!=head->prev; i = i->next){
			for (Node*j = head; j !=head->prev; j = j->next){
				if (j->next->data < j->data){
					swap(j->next->data, j->data);
				}
			}
		}
		
	}
};

Main.cpp
#include "DCLL.h"
int main()
{
	DCLL obj;
	obj. insertAtTail(1);
	obj. insertAtTail(2);
	obj. insertAtTail(6);
	obj. insertAtTail(4);
	obj. insertAtTail(5);
	obj. insertAtTail(9);
	obj. insertAtTail(7);
	obj.display();
	int choice, value;
	do {
		cout << "\nMenu:\n";
		cout << "1. Find Maximum Element\n";
		cout << "2. Print Factorials of Each Element\n";
		cout << "3. Find Second Maximum Element\n";
		cout << "4. Sum All Values\n";
		cout << "5. Delete Nodes with Even Numbers\n";
		cout << "6. Print the Linked obj\n";
		cout << "7. Sort the Linked obj\n";
		cout << "8. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			obj.maximum();
			break;
		case 2:
			obj.printfactorials();
			break;
		case 3:
			obj.secondmax();
			break;
		case 4:
			obj.sum();
			break;
		case 5:
			obj.deleteeven();
			cout << "Even numbers deleted successfully." << endl;
			break;
		case 6:
			cout << "Linked list is: ";
			obj.display();
			break;
		case 7:
			obj.sort();
			cout << "Linked list sorted successfully." << endl;
			break;
		case 8:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	} while (choice != 8);
	return 0;
}
