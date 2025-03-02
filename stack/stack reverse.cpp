#include <iostream>
#include <string>
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
	T pop(){
		return stack[--currentsize];

	}
	T top(){
		return stack[currentsize - 1];
	}
	bool isempty(){
		return currentsize == 0;
	}
	bool isFull(){
		return currentsize == maxsize;
	}
	void display() {
		cout << "Values in stack: ";
		for (int i = 0; i < currentsize; i++) {
			cout << stack[i] << " ";
		}
		cout << endl;
	}
};
void reversed(Stack<string> &s, Stack<string> &reverse){
	while (!s.isempty()){
		reverse.push(s.pop());
	}

}
int main(){
	Stack<string> s(3);
	s.push("BOOK A");
	s.push("Book B");
	s.push("Book C");
	s.display();
	Stack<string> reverse(3);
	reversed(s, reverse);
	reverse.display();
}
