#include "Tree.h"

class BST :public Tree
{
	void INORDER(Node*);
	void INORDER2(Node*);
	
public:
	void insert(int);
	void inorder();
	
};


void BST::INORDER(Node* p)
{
	if (p != nullptr)
	{
		INORDER(p->leftChild);
		cout << p->data << endl;
		INORDER(p->rightChild);
	}
}

void BST::INORDER2(Node* p)
{
	if (p != nullptr)
	{
		INORDER2(p->rightChild);
		cout << p->data << endl;
		INORDER2(p->leftChild);
	}
}


void BST::inorder()
{
	if (root != nullptr)
		INORDER(root);

	else
		cout << "Tree is empty" << endl;
}

void BST::insert(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->leftChild = nullptr;
	nn->rightChild = nullptr;

	if (root == nullptr)
		root = nn;

	else
	{
		Node* t = root;
		while (1)
		{
			if (value < t->data) //left side case
			{
				if (t->leftChild == nullptr) //add value here
				{
					t->leftChild = nn;
					break;
				}

				else
					t = t->leftChild;
			}

			else //right child case
			{
				if (t->rightChild == nullptr) //add value here
				{
					t->rightChild = nn;
					break;
				}

				else
					t = t->rightChild;
			}
		}
	}
}
