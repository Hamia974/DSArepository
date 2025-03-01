#include <iostream>
using namespace std;
class maxheap{
protected:
	int* arr;
	int size;
public:
	maxheap(){
		size = 100;
		arr = new int[size];
		arr[0] = 1;
	}
	void insert(int value){
		if (arr[0] == size){
			cout << "cannot add." << endl;
			return;
		}
		else{
			int i = arr[0];
			arr[i] = value;
			arr[0]++;
			while (i > 1 && arr[i / 2] < arr[i]){
				swap(arr[i / 2], arr[i]);
				i = i / 2;
			}
		}
	}
	void print(){
		cout << "maxheap is: ";
		for (int i = 1; i < arr[0]; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	bool isempty(){
		return arr[0] == 1;
	}
	int deleteroot(){
		int root = arr[1];
		int lastindex = arr[0] - 1;
		swap(arr[1], arr[lastindex]);
		arr[0]--;
		heapify(arr, arr[0], 1);
		return root;
	}
	void heapify(int arr[], int s, int i){
		int large = i;
		int left = 2 * i;
		int right = 2 * i + 1;
		if (left<s && arr[left]>arr[large]){
			large = left;
		}
		if (right<s&& arr[right]>arr[large]){
			large = right;
		}
		if (large != i){
			swap(arr[i], arr[large]);
			heapify(arr, s, large);
		}
	}
	void heapsort(){
		int* newarr = new int[arr[0]];
		newarr[0] = 1;
		int i = newarr[0];
		while (!isempty()){
			newarr[i] = deleteroot();
			newarr[0]++;
			i++;
		}
		cout << "heap sort: ";
		for (int i = 1; i < newarr[0]; i++){
			cout << newarr[i] << " ";
		}
		cout << endl;
	}
	~maxheap(){
		delete[] arr;
	}
};