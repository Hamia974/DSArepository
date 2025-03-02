#include <iostream>
#include <string>
using namespace std;
class CircularQueue {
private:
	string* queue;
	int front;
	int rear;
	int currentsize;
	int maxsize;
public:
	CircularQueue(int s = 0) {
		maxsize = s;
		queue = new string[maxsize];
		front = 0;
		rear = 0;
		currentsize = 0;
	}
	bool isFull() {
		return currentsize == maxsize;
	}
	bool isEmpty() {
		return currentsize == 0;
	}
	void enqueue(string name) {
		if (isFull()) {
			cout << "Queue is full. Cannot add more customers." << endl;
		}
		else {
			queue[rear%maxsize] = name;
			currentsize++;
			rear++;
			cout << "Customer " << name << " added to the queue." << endl;
		}
	}
	string dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty. No customers to remove." << endl;
		}
		else {

			string returningvalue = queue[front%maxsize];
			currentsize--;
			front++;
			if (currentsize == 0) { // Reset front and rear when queue becomes empty
				front = 0;
				rear = 0;
			}
			return returningvalue;
		}
	}

	int getSize() {
		return currentsize;
	}

	void viewFirstCustomer() {
		if (isEmpty()) {
			cout << "Queue is empty. No first customer." << endl;
		}
		else {
			cout << "First customer in the queue: " << queue[front] << endl;
		}
	}

	void viewLastCustomer() {
		if (isEmpty()) {
			cout << "Queue is empty. No last customer." << endl;
		}
		else {
			cout << "Last customer in the queue: " << queue[rear] << endl;
		}
	}
	//destructor
	~CircularQueue() {
		delete[] queue;
	}

};
int main() {
	int maxsize;
	cout << "Enter the maxsize of the queue: ";
	cin >> maxsize;
	CircularQueue c(maxsize);
	int choice;
	string name;
	do {
		cout << " Coffee Shop Queue Menu:" << endl;
		cout << "1. Add a customer to the queue" << endl;
		cout << "2. Remove the first customer from the queue" << endl;
		cout << "3. Display the number of customers waiting in line" << endl;
		cout << "4. View the first customer in the queue" << endl;
		cout << "5. View the last customer in the queue" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the name of the customer: ";
			cin >> name;
			c.enqueue(name);
			break;
		case 2:
			cout << "customer " << c.dequeue() << " removed from queue." << endl;
			break;
		case 3:
			cout << "Number of customers waiting in line: " << c.getSize() << endl;
			break;
		case 4:
			c.viewFirstCustomer();
			break;
		case 5:
			c.viewLastCustomer();
			break;
		case 0:
			cout << "Exiting program. " << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0);

	return 0;
}
