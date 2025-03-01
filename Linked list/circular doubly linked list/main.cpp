#include "DCLL.h"

int main()
{
	DCLL obj;

	obj.insertAtTail(10);
	obj.insertAtTail(20);
	obj.insertAtTail(30);
	obj.insertAtTail(40);
	obj.insertAtTail(50);
	obj.insertAtTail(60);

	obj.printList();
	obj.insertAtPosition(4, 35);
	cout << "List after inserting 35 at position 4: ";
	obj.printList();



	return 0;
}