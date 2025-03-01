AbstractStack.h
#include <iostream>
using namespace std;
template<typename T>
class AbstractStack{
protected:
	T* stack;
	int currentsize;
	int maxsize;
public:
	virtual void push(T value) = 0;
	virtual T pop() = 0;
	virtual T top() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;

	//default constructor
	AbstractStack(){

	}
	//parameterized constructor
	AbstractStack(int s){
		currentsize = 0;
		maxsize = s;
		stack = new T[s];
	}
	~AbstractStack(){

	}

};
myStack.h
#include “AbstractClass.h”
template<typename T>
class myStack :public AbstractStack<T>{
public:
	//default constructor
	myStack() :AbstractStack<T>(){

	}
	//parameterized constructor
	myStack(int s) :AbstractStack<T>(s){
	}
	void push(T value)override{
		stack[currentsize] = value;
		currentsize++;
	}
	T pop(){
		return stack[--currentsize];
		
	}
	T top()const{
		return stack[currentsize-1];
	}
	bool isEmpty()const{
		return currentsize == 0;
	}
	bool isFull()const{
		return currentsize == maxsize;
	}
	void display(){
		cout << “values of stack is: “;
		for (int i = 0; i < currentsize; i++){
			cout << stack[i] << “ “;
		}
	}
	~myStack(){
		delete[] stack;
		stack = nullptr;
	}
};
Main.cpp
#include “myStack.h”
int main(){
	myStack<int> s(5);		
	int choice, value;
		do {
			cout << “Menu:\n”;
			cout << “1. Push\n”;
			cout << “2. Pop\n”;
			cout << “3. Top\n”;
			cout << “4. Is Empty?\n”;
			cout << “5. Is Full?\n”;
			cout << “6. Display\n”;
			cout << “0. Exit\n”;
			cout << “Enter your choice: “;
			cin >> choice;
			switch (choice) {
			case 1:
				cout << “Enter value to push: “;
				cin >> value;
				s.push(value);
				break;

			case 2:
				if (!s.isEmpty()) {
					cout << “Popped value: “ << s.pop() << endl;
				}
				else {
					cout << “Stack is empty, cannot pop!\n”;
				}
				break;

			case 3:
				if (!s.isEmpty()) {
					cout << “Top value: “ << s.top() << endl;
				}
				else {
					cout << “Stack is empty!\n”;
				}
				break;

			case 4:
				if (s.isEmpty()){
					cout << “stack is empty.” << endl;
				}
				else{
					cout << “stack is not empty.” << endl;
				}
				break;

			case 5:
				if (s.isFull()){
					cout << “stack is full.” << endl;
				}
				else{
					cout << “stack is not full.” << endl;
				}
				break;

			case 6:
				s.display();
				break;

			case 0:
				cout << “Exiting…\n”;
				break;

			default:
				cout << “Invalid choice! Please try again.\n”;
			}

			cout << endl;

		} while (choice != 0);

		return 0;
	
}

