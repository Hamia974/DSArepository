#include <iostream>
#include "string"
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
		return stack[currentsize - 1];
	}
	bool isEmpty()const{
		return currentsize == 0;
	}
	bool isFull()const{
		return currentsize == maxsize;
	}
	void display(){
		cout << "values of stack is: ";
		for (int i = 0; i < currentsize; i++){
			cout << stack[i] << " ";
		}
	}
	~myStack(){
		delete[] stack;
		stack = nullptr;
	}
};

bool checkbalance(int length, string str){
	myStack<char> s(length);
	for (int i = 0; i <length; i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			s.push(str[i]);
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			if (s.isEmpty()) {
				return false;
			}
			if (str[i] == ')' && s.top() == '(' || str[i] == '}' && s.top() == '{' || str[i] == ']' && s.top() == '[') {
				s.pop();
			}
			else {
				return false;
			}
		}
	}
	return s.isEmpty();
}

int main(){
	int choice;
	string str;
	int length;
	do{
		cout << "...........MENU........." << endl;
		cout << "1. Input expression. " << endl;
		cout << "2. check the balance expression. " << endl;
		cout << "0. exit" << endl;
		cout << "enter the choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "enter the string: ";
			cin >> str;
			length = str.length();
			break;

		case 2:
			if (checkbalance(length, str)){
				cout << "brackets in expression are balanced." << endl;
			}
			else{
				cout << "brackets in expression are not balanced." << endl;
			}
			break;

		case 0:
			cout << "Exiting....." << endl;
			break;

		default:
			cout << "Invalid choice! Please try again.\n";
		}

	} while (choice != 0);
	return 0;
}
