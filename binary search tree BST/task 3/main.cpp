#include "BST.h"

int main()
{
	BST bst;	
	bst.insert(6);
	bst.insert(3);
	bst.insert(8);
	bst.insert(1);
	bst.insert(4);
	bst.insert(7);
	bst.insert(9);
	cout << "inorder traversal: " << endl;
	bst.inorder();
	bst.printmedian();
	return 0;
}
