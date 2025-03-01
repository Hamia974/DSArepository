#include <iostream>
#include <string>
using namespace std;
template <typename t>
int  linearSearch(t arr[], t value){
	for (int i = 0; i < 6; i++){
		if (arr[i] == value){
			return i;
		}
	}
}
template<typename y>
void printSearchResult(int b, y a){
	cout << a << " found at " << b << endl;
}
int main(){
	// Test with an integer array of size 5
	int intArray[5] = { 64, 25, 12, 22, 11 };
	int intKey = 12;
	int intIndex = linearSearch(intArray, intKey);
	printSearchResult(intIndex, intKey);

	// Test with a float array of size 4
	float floatArray[4] = { 3.14, 2.71, 1.62, 0.57 };
	float floatKey = 1.62;
	int floatIndex = linearSearch(floatArray, floatKey);
	printSearchResult(floatIndex, floatKey);
	// Test with a string array of size 4
	string stringArray[4] = { "apple", "orange", "banana", "grape" };
	string stringKey = "banana";
	int stringIndex = linearSearch(stringArray, stringKey);
	printSearchResult(stringIndex, stringKey);

	return 0;



}
