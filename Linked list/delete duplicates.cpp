struct Node{
	int data;
	Node* next;
};
LinkedList.h

#include <iostream>
#include "Node.h"
using namespace std;
class LinkedList{
protected:
	Node* head;
	Node* tail;
public:
	LinkedList(){
		head = nullptr;
		tail = nullptr;
	}

	virtual void display() = 0;
	virtual void deleteDuplicates() = 0;
	virtual void addValue(int value) = 0;
};
myLL.h
#include "LinkedList.h"
class myLL :public LinkedList{
public:
	myLL() :LinkedList(){

	}
	void deleteDuplicates() {
		if (head == nullptr){
			return; // Empty list, nothing to remove
		}
		Node* current = head;
		while (current != nullptr) {
			Node* t = current;
			while (t->next != nullptr) {
				if (t->next->data == current->data) {
					// Remove duplicate node
					Node* duplicate = t->next;
					t->next = t->next->next;
					if (duplicate == tail) tail = t; // Update tail if necessary
					delete duplicate;
				}
				else {
					t = t->next;
				}
			}
			current = current->next;
		}
	}
	void addValue(int value) {
		Node* nn = new Node;
		nn->data = value;
		nn->next = nullptr;
		if (head == nullptr && tail == nullptr) { // Empty list
			head = nn;
			tail = nn;
		}
		else {
			tail->next = nn;
			tail = nn;
		}
	}
	void display(){
		if (head == nullptr && tail == nullptr){
			cout << "linked list is empty." << endl;
		}
		else{
			Node* t = head;
			while (true){
				cout << t->data << endl;
				t = t->next;
				if (t == nullptr){
					break;
				}
			}
		}
	}

};
Main.cpp
#include "myLL.h"
int main() {
	myLL list;
	int choice, value;
	do {
		cout << " Menu:\n";
		cout << "1. Add a value to the linked list\n";
		cout << "2. Delete duplicate values from the linked list\n";
		cout << "3. Display the linked list\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter the value to add to the linked list: ";
			cin >> value;
			list.addValue(value);
			break;
		case 2:
			list.deleteDuplicates();
			cout << "Duplicates removed. Updated list: ";
			list.display();
			break;
		case 3:
			cout << "Linked list: ";
			list.display();
			break;
		case 4:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 4);

	return 0;

}
