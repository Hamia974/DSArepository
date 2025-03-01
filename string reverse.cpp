
#include <iostream>
#include <string>
using namespace std;

string reverse_name(string name, string rev = "", int size = 0) {
	if (size < 0) { 
		return rev;
	}
	return reverse_name(name, rev + name[size], size - 1);
}

int main() {
	string str;
	cout << "Enter a name: ";
	getline(cin, str);
	string reversed = reverse_name(str, "", str.length() - 1);
	cout << "Reversed name is: " << reversed << endl;
	return 0;
}
