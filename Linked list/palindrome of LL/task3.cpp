#include "myLL.h"
int main()
{
	myLL<char> obj;
	obj.insertAtTail('p');
	obj.insertAtTail('o');
	obj.insertAtTail('p');
	cout << "linked list is:  ";
	obj.display();
	if (obj.ispalindrome()){
		cout << "\nLinked list is palindrome." << endl;
	}
	else{
		cout << "\nLinked list is not palindrome." << endl;
	}
	return 0;
}