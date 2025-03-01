#include <iostream>
using namespace std;
class minheap{
protected:
	int* arr;
	int size;
public:
	minheap(){
		 size = 100;
		arr = new int[size];
		arr[0] = 1;
	}
	void insert(int value){
		if (arr[0] == size){
			cout << "array is full.cannot insert more values." << endl;
			return;
		}
		else{
			int i = arr[0];
			arr[i] = value;
			arr[0]++;
			while (i>1 && arr[i / 2] > arr[i]){
				swap(arr[i], arr[i / 2]);
				i = i / 2;
			}
		}
	}
	int deleteroot(){
		int root = arr[1];
		int lastindex = arr[0] - 1;
		swap(arr[1], arr[lastindex]);
		arr[0]--;
		heapify(arr, arr[0], 1);
		return root;
	}
	void heapify(int arr[], int size, int i){
		int small = i;
		int left = 2 * i;
		int right = 2 * i + 1;
		if (left < size && arr[left] < arr[small]){
			small = left;
		}
		if (right < size && arr[right] < arr[small]){
			small = right;
		}
		if (small != i){
			swap(arr[i], arr[small]);
			heapify(arr, size, small);
		}
	}
	bool isempty(){
		return arr[0] == 1;
	}
	void heapsort(){
		int* newarr = new int[arr[0]];
		newarr[0] = 1;
		int i = newarr[0];
		while (!isempty()){
			newarr[i] = deleteroot();
			i++;
			newarr[0]++;
		}
		cout << "heap is: ";
		for (int i = 1; i < newarr[0]; i++){
			cout << newarr[i] << " ";
		}
		cout << endl;
	}
	void print(){
		cout << "heap is: ";
		for (int i = 1; i < arr[0]; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	~minheap(){
		delete[] arr;
	}
};