#include <iostream>
#include "myList.h" 
using namespace std;
template<typename T>
class CustomList :public mylist<T>{
public:
	//default constructor
	CustomList(){

	}
	//parameterized constructor
	CustomList(int s) :mylist<T>(s){ }
	//CustomList(const CustomList& other) : MyList<Type>(other) {}
	//destructor
	~CustomList(){ }
	bool isPrime(T n) {
		if (n < 2)
			return false;
		for (T i = 2; i * i <= n; ++i) {
			if (n % i == 0) return false;
		}
		return true;
	}
	T sum_ofPrime() {
		int sum = 0;
		for (int i = 0; i < currentsize; ++i) {
			if (isPrime(arr[i])) {
				sum += arr[i];
			}
		}
		return sum;
	}
	T secondMaxEven() {
		int maxEven = -1;
		int secondMaxEven = -1;
		for (int i = 0; i < currentsize; ++i) {
			if (arr[i] % 2 == 0) {
				if (arr[i] > maxEven) {
					secondMaxEven = maxEven;
					maxEven = arr[i];
				}
				else if (arr[i] > secondMaxEven && arr[i] != maxEven) {
					secondMaxEven = arr[i];
				}
			}
		}
		return secondMaxEven;
	}
	int secondMinOdd() {
		int minOdd = -1;
		int secondMinOdd = -1;
		for (int i = 0; i < currentsize; ++i) {
			if (arr[i] % 2 != 0) {
				if (minOdd == -1 || arr[i] < minOdd) {
					secondMinOdd = minOdd;
					minOdd = arr[i];
				}
				else if ((secondMinOdd == -1 || arr[i] < secondMinOdd) && arr[i] != minOdd) {
					secondMinOdd = arr[i];
				}
			}
		}
		return secondMinOdd;
	}
	void printDuplicates() {
		bool foundDuplicate = false;
		for (int i = 0; i < currentsize; ++i) {
			int count = 1;
			for (int j = i + 1; j < currentsize; ++j) {
				if (arr[i] == arr[j]) {
					count++;
					arr[j] = -1;
				}
			}
			if (count > 1) {
				cout << arr[i] << " occurs " << count << " times." << endl;
				foundDuplicate = true;
			}
		}	
		if (!foundDuplicate) {
			cout << "No duplicates found." << endl;
		}	
}
	void rotateClockwise(int r) {
		if (currentsize == 0) return; 
		r = r % currentsize; 
		// Find the middle index
		int mid = currentsize / 2;
		// Rotate first half
		for (int i = 0; i < r; ++i) {
			int temp = arr[mid - 1]; // Last element of first half
			for (int j = mid - 1; j > 0; --j) {
				arr[j] = arr[j - 1];
			}
			arr[0] = temp; // Insert last element at the front
		}

		// Rotate second half
		for (int i = 0; i < r; ++i) {
			int temp = arr[currentsize - 1]; // Last element of second half
			for (int j = currentsize - 1; j > mid; --j) {
				arr[j] = arr[j - 1];
			}
			arr[mid] = temp; // Insert last element at the mid
		}
	}
	void rotateAntiClockwise(int rt) {
		if (currentsize == 0) return; 
		rt = rt % currentsize; 
		// Find the middle index
		int mid = currentsize / 2;
		// Rotate first half
		for (int i = 0; i < rt; ++i) {
			int temp = arr[0]; // First element of the first half
			for (int j = 0; j < mid - 1; ++j) {
				arr[j] = arr[j + 1];
			}
			arr[mid - 1] = temp; // Place the first element at the end of the first half
		}
		// Rotate second half
		for (int i = 0; i < rt; ++i) {
			int temp = arr[mid]; // First element of the second half
			for (int j = mid; j < currentsize - 1; ++j) {
				arr[j] = arr[j + 1];
			}
			arr[currentsize - 1] = temp; // Place the first element at the end of the second half
		}
	}
};