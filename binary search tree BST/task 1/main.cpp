#include "BST.h"

int main()
{
	BST bst;	
	bst.insert(50);
	bst.insert(30);
	bst.insert(20);
	bst.insert(40);
	bst.insert(70);
	bst.insert(60);
	bst.insert(80);
	cout << "inorder traversal: " << endl;
	bst.inorder();
	bst.search1();
	cout << "delete node 20: " << bst.deleteNode(20) << endl;
	cout << "after deletion,tree is: " << endl;
	bst.inorder();
	bst.height1();
	return 0;
}
