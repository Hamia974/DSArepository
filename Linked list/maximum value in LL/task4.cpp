#include "myLL.h"
int main()
{
	myLL<int> obj;
	obj.insertAtTail(50);
	obj.insertAtTail(15);
	obj.insertAtTail(78);
	cout << "linked list is:  ";
	obj.display();
	obj.maximum();
	return 0;
}