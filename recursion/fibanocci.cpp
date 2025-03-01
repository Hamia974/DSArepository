#include <iostream>
using namespace std;
void fib(int n, int a = 0, int b = 1) {
	if (n == 0) {
		return;
	}
	cout << a << " ";
	fib(n - 1, b, a + b);
}
int main() {
	int n;
	cout << "Enter number: ";
	cin >> n;
	cout << "Fibonacci series up to " << n << " terms is: ";
	fib(n);

	cout << endl;
	return 0;
}
