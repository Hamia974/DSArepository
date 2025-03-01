#include <iostream>
#include "Node.h"
using namespace std;
class tree{
protected:
	Node* root;
	virtual void INORDER(Node* t) = 0;
	virtual void PREORDER(Node* t) = 0;
	virtual void POSTORDER(Node* t) = 0;
	virtual void INORDER2(Node* t) = 0;
	virtual void PREORDER2(Node* t) = 0;
	virtual void POSTORDER2(Node* t) = 0;
public:
	tree(){
		root = nullptr;
	}
	virtual void insert(int key) = 0;
    virtual Node* search(Node* t, int value) = 0;
	virtual void inorder() = 0;
	virtual void preorder() = 0;
	virtual void postorder() = 0;
	virtual void inorder2() = 0;
	virtual void preorder2() = 0;
	virtual void postorder2() = 0;
	virtual void parentSearch(Node* , int , int p) = 0;
	virtual void destroyTree(Node* t) = 0;
	virtual void deleteNode(Node*& root, int value) = 0;
};