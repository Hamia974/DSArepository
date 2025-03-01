#include <iostream>
#include "list.h" 
using namespace std;
template<typename T>
class mylist : public List<T> {
public:
	// Default constructor
	mylist() : List<T>() {}
	// Parameterized constructor
	mylist(int s) : List<T>(s) {}
	//copy constructor
	//MyList(const MyList& o) : List<T>(o) {}
	// Add an element at the first index
	void addElementAtFirstIndex(T v) {
		cout << "value at index: " << currentsize << ": " << v << endl;
		arr[currentsize] = v;
		currentsize++;

	}
	// Add an element at the last index
	void addElementAtLastIndex(T v) {
		cout << "value at index: " << maxsize - 1 << ": " << v << endl;
		arr[maxsize - 1] = v;
	}
	void othervalues(){
		if (currentsize < maxsize){
			for (int i = currentsize; i < maxsize - 1; i++){
				cout << "enter value at index: " << i << endl;
				cin >> arr[i];
				currentsize++;
			}
		}

	}
	T removeElementFromEnd() {
		if (currentsize > 0) {
			return arr[--currentsize];
		}
		else {
			cout << "List is empty, cannot remove element from end." << endl;
			return T();
		}
	}

	// Remove the element from the start
	void removeElementFromStart() {
		if (currentsize > 0) {
			for (int i = 0; i < currentsize - 1; ++i) {
				arr[i] = arr[i + 1]; // Shift elements to the left
			}
			currentsize--; // Decrement size
		}
		else {
			cout << "List is empty, cannot remove element from start." << endl;
		}
	}
	// Display the elements in the list
	void display() {
		cout << "array is: ";
		for (int i = 0; i < maxsize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;

	}
	bool empty(){
		return currentsize == 0;
	}
	bool full(){
		return currentsize == maxsize;
	}
	int size(){
		return currentsize;
	}
	bool insertAt(int index, T value) {
		arr[index] = value;
		if (index >= currentsize && index < maxsize && arr[index] == value) {
			return true;
		}
		else{
			return false;
		}
	}
	T last(){
		if (empty()) {
			cout << "array is empty: ";
		}
		else{
			return arr[currentsize];
		}
	}
	bool search(T num){
		for (int i = 0; i < currentsize; i++){
			if (arr[i] == num){
				return true;
			}
		}
		return false;
	}
};