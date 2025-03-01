#include "myLL.h"
int main()
{
	myLL<int> obj;
	obj.insertSorted(990);
	obj.insertSorted(500);
	obj.insertSorted(300);
	obj.insertSorted(150);
	obj.insertSorted(6);
	cout << "linked list is:  ";
	obj.display();
	obj.middle(obj);
	return 0;
}