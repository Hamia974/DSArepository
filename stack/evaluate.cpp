#include <iostream>
using namespace std;
template<typename T>
class Stack{
protected:
	T* stack;
	int currentsize;
	int maxsize;
public:
	//default constructor
	Stack(){
	}
	//parameterized constructor
	Stack(int s){
		currentsize = 0;
		maxsize = s;
		stack = new T[s];
	}
	void push(T value){
		stack[currentsize] = value;
		currentsize++;
	}
	char pop(){
		return stack[--currentsize];

	}
	char top(){
		return stack[currentsize - 1];
	}
	bool isEmpty(){
		return currentsize == 0;
	}
	bool isFull(){
		return currentsize == maxsize;
	}
	void display(){
		cout << "values of stack is : ";
		for (int i = 0; i < currentsize; i++){
			cout << stack[i] << " ";
		}
	}
};

Main.cpp
#include <cstring>
#include "stack.h"
using namespace std;
void evaluate(char* stk, int size){
	int op1 = 0;
	int op2 = 0;
	char waste = 0;
	int result = 0;
	Stack<int> s(size);
	for (int i = 0; i < size; i++){
		if (stk[i] >= '0' && stk[i] <= '9'){
			s.push(stk[i] - '0');
		}
		else if (stk[i] == '+' || stk[i] == '-' || stk[i] == '*' || stk[i] == '/') {
			op2 = s.pop();
			op1 = s.pop();
			switch (stk[i]) {
			case '+':
				result = op1 + op2;
				break;
			case '-':
				result = op1 - op2;
				break;
			case '*':
				result = op1 * op2;
				break;
			case '/':
				result = op1 / op2;
				break;
			}
			s.push(result);
		}
		else {
			waste = stk[i];
		}
	}
	cout << "\nFinal output: " <<static_cast<int>(s.pop()) << endl;
}

int main() {
	char infix[] = "6 3 + 2 *";
	int length = strlen(infix);
	cout << "input is: ";
	for (int i = 0; i < length; i++){
		cout << infix[i];
	}
	evaluate(infix,length);
	return 0;
}
