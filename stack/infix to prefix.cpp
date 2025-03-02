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

string reverse(string& s, int size) {
	string reversestring(size, '\0');
	for (int i = 0; i < size; i++) {
		reversestring[i] = s[size - i - 1];
		if (reversestring[i] == '(') {
			reversestring[i] = ')';
		}
		else if (reversestring[i] == ')') {
			reversestring[i] = '(';
		}
	}
	return reversestring;
}
string infixtopreffix(string exp, int size){
	string result;
	Stack<char> s(size);
	for (int i = 0; i < size; i++){
		if (exp[i] == '('){
			s.push(exp[i]);
		}
		if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A'&& exp[i] <= 'Z'){
			result += exp[i];
		}
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' || exp[i] == '^'){
			s.push(exp[i]);
		}
		if (exp[i] == ')'){
			result += s.pop();
			s.pop();
		}
	}
	while (!s.isEmpty()){
		result += s.pop();
	}
	return result;
}
int main(){
	string infix = "(((A+B)*(C-E))/(F+G))";
	int length = infix.length();
	cout << "Infix expression: " << infix << endl;
	string reversed_expression = reverse(infix, length);
	cout << "Reversed: " << reversed_expression << endl;
	string prefix = infixtopreffix(reversed_expression, length);
	cout << "Prefix before final reverse: " << prefix << endl;
	string final_prefix = reverse(prefix, prefix.length());
	cout << "Final Prefix: " << final_prefix << endl;

	return 0;
}
