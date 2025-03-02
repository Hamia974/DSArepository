
#include <iostream>
#include <string>
using namespace std;
template <typename T>
struct node{
	T data;
	node* next;
};
template <typename T>
class linkedlist {
protected:
	node<T>* head; // Use node<T> to specify the template argument
	node<T>* tail;
public:
	linkedlist() {
		head = nullptr;
		tail = nullptr;
	}
	void insert(T value) {
		node<T>* nn = new node<T>();
		nn->data = value;
		nn->next = nullptr;
		if (head == nullptr && tail == nullptr) {

			head = nn;
			tail = nn;
		}
		else {

			tail->next = nn;
			tail = nn;
		}
	}

	void display() {
		if (head == nullptr && tail == nullptr) {
			cout << "Empty linked list." << endl;
			return;
		}

		node<T>* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main() {
	linkedlist<int> L;
	int choice;
	int value;
	do {
		cout << "......Menu.." << endl;
		cout << "1. Insert a value." << endl;
		cout << "2. Display the linked list." << endl;
		cout << "0. Exit. " << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter the value to insert: ";
			cin >> value;
			L.insert(value);
			cout << "Value inserted successfully." << endl;
			break;
		case 2:
			cout << "Display Linked list: ";
			L.display();
			break;
		case 0:
			cout << "Exiting program. ";
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 0);

	return 0;
}
