#include "Node.h"
#include <iostream>
using namespace std;

class Tree
{
protected:
	Node* root;
public:
	Tree();
	virtual void insert(int) = 0;
	virtual void inorder() = 0;
	virtual void preorder() = 0;
	virtual void postorder() = 0;
	virtual bool deleteNode(int) = 0;
	virtual Node* search(Node* t,int value) = 0;
	virtual int height(Node*) = 0;
};

Tree::Tree()
{
	root = nullptr;
}
