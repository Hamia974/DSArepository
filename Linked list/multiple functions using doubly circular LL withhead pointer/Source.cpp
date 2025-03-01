#include "myLL.h"
int main()
{
	myLL obj;
	obj.insertAtTail(1);
	obj.insertAtTail(2);
	obj.insertAtTail(3);
	obj.insertAtTail(4);
	obj.insertAtTail(5);
	obj.insertAtTail(6);
	obj.insertAtTail(7);
	obj.insertAtTail(8);
	obj.insertAtTail(9);
	obj.insertAtTail(10);
	obj.display();
	int k;
	cout << "\nenter kth element: ";
	cin >> k;
	cout << "Result: " << obj.findKthToLast(k) << endl;
	return 0;
}