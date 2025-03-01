#include <iostream>
using namespace std;
template<typename T>
class List{
protected:
	T *arr;
	int maxsize;
	int currentsize;
public:
	virtual void addElementAtFirstIndex(T) = 0;
	virtual void addElementAtLastIndex(T) = 0;
	virtual T removeElementFromEnd() = 0;
	virtual void removeElementFromStart() = 0;
	//parameterized constructor
	List(int size = 0){
		maxsize = size;
		currentsize = 0;
		arr = new T[maxsize];

	}
	//copy constructor
	List(List &l){
		maxSize = l.maxSize;
		currentSize = l.currentSize;
		arr = new T[maxSize];
		for (int i = 0; i < currentSize; i++) {
			arr[i] = l.arr[i];
		}
	}
	//destructor
	~List(){
		delete[] arr;
	}

};