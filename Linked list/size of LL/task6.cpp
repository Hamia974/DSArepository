#include "myLL.h"
int main()
{
	myLL<int> obj;
	obj.insertAtTail(50);
	obj.insertAtTail(15);
	obj.insertAtTail(78);
	obj.insertAtTail(98);
	cout << "linked list is:  ";
	obj.display();
	cout << "\n Number of nodes in linked list are: " << obj.NoOfNodes() << endl;
	return 0;
}