#include <iostream>
using namespace std;
int fact(int n){
	if (n > 0){
		return n*fact(n - 1);
	}
	if (n == 0){
		return 1;
	}
}
int main(){
	int n;
	cout << "enter number of factorial: ";
	cin >> n;
	cout << "Factorial of " << n << " is: " << fact(n) << endl;
	return 0;
}
