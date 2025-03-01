#include <iostream>
using namespace std;
int natural(int n){
	if (n ==0){
		return 0;
	}
	if (n > 0){
		natural(n - 1);
		cout << n << " ";
		
	}
}
int main(){
	int n;
	cout << "enter number: ";
	cin >> n;
	cout << "natural number till " << n << " are: ";
	natural(n);
	cout << endl;
	return 0;
}
