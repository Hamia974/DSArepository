#include "myLL.h"
int main()
{
	myLL<int> obj;
	obj.insertAtTail(50);
	obj.insertAtTail(15);
	obj.insertAtTail(15);
	obj.insertAtTail(81);
	obj.insertAtTail(98);
	obj.insertAtTail(98);
	cout << "linked list before deletion is:  ";
	obj.display();
	obj.removeduplicates();
	return 0;
}