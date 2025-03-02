#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
class LinkedList{
protected:
	Node* head;
	Node* tail;
public:
	LinkedList(){
		head = nullptr;
		tail = nullptr;
	}

	virtual void insertatTail(int) = 0;
	virtual void insertatHead(int) = 0;
	virtual void display() = 0;
	virtual int deletefromHead() = 0;
	virtual int deletefromTail() = 0;

};
class myLL :public LinkedList{
public:
	myLL() :LinkedList(){

	}
	void insertatTail(int value){
		Node* nn = nullptr;
		nn = new Node;
		nn->data = value;
		nn->next = nullptr;
		//empty case
		if (head == nullptr && tail == nullptr){

			head = nn;
			tail == nn;

		}
		else{//non-empty
			tail->next = nn;
			tail = nn;
		}
	}
	void insertatHead(int value){
		Node* newnn = nullptr;
		newnn = new Node;
		newnn->data = value;
		newnn->next = nullptr;
		//empty case
		if (head == nullptr && tail == nullptr){
			head = newnn;
			tail = newnn;
		}
		//non-empty case
		else{
			newnn->next = head;
			head = newnn;
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
	int deletefromHead(){
		if (head == nullptr && tail == nullptr){
			cout << "LL is empty. " << endl;
			return NULL;
		}
		else if (head == tail){ //single node
			int returningValue = head->data;
			delete head;
			head = nullptr;
			tail = nullptr;
			return returningValue;
		}
		else{
			int returningValue = head->data;
			Node* temp = head;
			head = head->next;
			delete temp;
			temp = nullptr;
			return returningValue;
		}
	}
	int deletefromTail(){
		int returningvalue = tail->data;
		Node* t = head;
		while (1){
			if (t->next->next == nullptr){
				break;
			}
			else{
				t = t->next;
			}
		}
		delete tail;
		tail = t;
		t->next = nullptr;
		return returningvalue;
	}
};

class Stack{
public:
	myLL l;
	void push(int a){
		l.insertatHead(a);
	}
	int pop(){
		return l.deletefromHead();
	}
	int top(){
		int returning_value = l.deletefromHead();
		push(returning_value);
		return returning_value;
	}
	bool isempty(){
		return l.deletefromHead() == NULL;
	}
	void display(){
		l.display();
	}

};
using namespace std;
int main() {
	Stack s;
	int choice, value;
	do {
		cout << "Menu:" << endl;
		cout << "1. Push an element onto the stack" << endl;
		cout << "2. Pop an element from the stack" << endl;
		cout << "3. Display the top element of the stack" << endl;
		cout << "4. Display all elements in the stack" << endl;
		cout << "5. Check if the stack is empty" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter the value to push: ";
			cin >> value;
			s.push(value);
			break;
		case 2:
			cout << "Popped value: " << s.pop() << endl;
			break;
		case 3:
			cout << "Top element: " << s.top() << endl;
			break;
		case 4:
			s.display();
			break;
		case 5:
			if (s.isempty()){
			}
			else {
				cout << "not empty" << endl;
			}
			break;
		case 6:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice, please try again." << endl;
		}
	} while (choice != 6);
	return 0;
}
