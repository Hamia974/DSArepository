#include "LinkedList.h"
class DCLL :public LinkedList
{
public:
	void insertAtTail(int value){
		Node* nn = new Node;
		nn->data = value;
		nn->next = nullptr;
		nn->prev = nullptr;
		if (head == nullptr && tail == nullptr){
			head = nn;
			tail = nn;
			nn->prev = nn;
			nn->next = nn;
		}
		else{
			tail->next = nn;
			nn->prev = tail;
			tail = nn;
			nn->next = head;
			head->prev = nn;
		}
	}
	void insertatHead(int value){
		Node* nn = new Node;
		nn->data = value;
		nn->next = nullptr;
		nn->prev = nullptr;
		if (head == nullptr && tail == nullptr){
			head = nn;
			tail = nn;
			nn->prev = nn;
			nn->next = nn;
		}
		else{
			nn->next = head;
			head->prev = nn;
			head = nn;
			head->prev = tail;
			tail->next = head;
		}
	}
	bool isempty(){
		if (head == nullptr && tail == nullptr){
			return true;
		}
		return false;
	}
	void printList(){
		if (isempty()) {
			cout << "linked List is empty." << endl;
		}

		else{
			printListRecursive(head, head);
		}
		cout << endl;
	}
	void printListRecursive(Node* t, Node* head) {
		cout << t->data << " ";
		if (t->next != head) {
			printListRecursive(t->next, head);
		}
	}
	void insertAtPosition(int position, int value) {
		if (position < 1) {
			cout << "Invalid position!" << endl;
			return;
		}
		if (position == 1) {
			insertatHead(value);
		}
		else {
			recursiveInsertion(head, position, value);
		}
	}

	void recursiveInsertion(Node* t, int position, int value, int count = 1) {
		if (count == position - 1) {
			Node* nn = new Node;
			nn->data = value;
			nn->next = t->next;
			nn->prev = t;
			t->next->prev = nn;
			t->next = nn;
			return;
		}
		recursiveInsertion(t->next, position, value, count + 1);
	}

};

