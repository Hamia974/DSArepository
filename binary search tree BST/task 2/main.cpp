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

	return 0;
}
