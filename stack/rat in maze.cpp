#include <iostream>  
#include <fstream>
#include <stack>
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
	int pop(){
		return stack[--currentsize];

	}
	int top(){
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
class location {
public:
	int a;
	int b;
};

bool RatCanMove(int** maze, int x, int y, int size) {
	if (x >= 0 && y >= 0 && x < size && y < size && maze[x][y] == 1){
		return true;
	}
	else{
		return false;
	}
}

bool RatInMaze(int** maze, int n, int** ResultantMaze) {
	stack<location> st;
	st.push({ 0, 0 });
	while (!st.empty()) {
		location curr = st.top();
		st.pop();
		int a = curr.a;
		int b = curr.b;
		if (a == n - 1 && b == n - 1) {
			ResultantMaze[a][b] = 1;
			return true;
		}
		if (RatCanMove(maze, a, b, n) && ResultantMaze[a][b] == 0) {
			ResultantMaze[a][b] = 1;

			if (RatCanMove(maze, a + 1, b, n)) {
				st.push({ a + 1, b });
			}
			if (RatCanMove(maze, a, b + 1, n)) {
				st.push({ a, b + 1 });
			}
		}
	}
	return false;
}

void SolveMaze(const string& input, const string& output) {
	ifstream fin(input);
	ofstream fout(output);

	if (!fin.is_open() || !fout.is_open()) {
		cout << "cannot open input or output file" << endl;
	}

	int size;
	fin >> size;
	//2d array
	int** maze = new int*[size];
	for (int i = 0; i < size; i++) {
		maze[i] = new int[size];
	}
	//input from file
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fin >> maze[i][j];
		}
	}
	int** ResultantMaze = new int*[size];
	for (int i = 0; i < size; i++) {
		ResultantMaze[i] = new int[size];
		for (int j = 0; j < size; j++) {
			ResultantMaze[i][j] = 0;
		}
	}
	//result in output file
	if (RatInMaze(maze, size, ResultantMaze)) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				fout << ResultantMaze[i][j] << " ";
			}
			fout << endl;
		}
	}
	else {
		fout << "No solution ." << endl;
	}

	cout << "Resultant maze successfully stored in Output.txt file." << endl;;

	//deletion of array
	for (int i = 0; i < size; i++) {
		delete[] maze[i];
		delete[] ResultantMaze[i];
	}
	delete[] maze;
	delete[] ResultantMaze;

	fin.close();
	fout.close();
}

int main() {
	SolveMaze("input.txt", "output.txt");
	return 0;
}
