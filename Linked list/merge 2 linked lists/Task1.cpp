#include "myLL.h"
int main()
{
	myLL<int> obj;
	obj.insertSorted(990);
	obj.insertSorted(500);
	obj.insertSorted(300);
	obj.insertSorted(150);
	cout << "linked list one is:  " << endl;
	obj.display();
	myLL<int> obj1;
	obj1.insertSorted(1024);
	obj1.insertSorted(50);
	obj1.insertSorted(1000);
	cout << "\nLinked list two is: " << endl;
	obj1.display();
	cout << "\nmerged linked list is: ";
	myLL<int> l;
	l = l.mergesorted(obj, obj1);
	l.display();
	return 0;
}