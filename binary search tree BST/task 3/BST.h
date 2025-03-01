#include "Tree.h"

class BST :public Tree
{
	void INORDER(Node*);
	void INORDER2(Node*);
	void PREORDER(Node*);
	void POSTORDER(Node*);
	void COUNT(Node*, int&);
public:
	void insert(int);
	void inorder();
	void preorder();
	void postorder();
	int countNodes();
	bool deleteNode(int);
	int median(){
		int n = countNodes();
		if (n % 2 == 0){
			return ((n / 2) + ((n / 2) + 1)) / 2;
		}
		else {
			return (n + 1) / 2;
		}
	}
	void printmedian() {
		const int size = countNodes(); 
		int* arr = new int[size]; 
		int sizeIndex = 0; 
		inOrderToArray(root, arr, sizeIndex); 
		int m = median();
		cout << "median of tree is: " << arr[m-1] << endl;
		delete[] arr;
	}

	void inOrderToArray(Node* root, int arr[], int& size) {
		if (root == nullptr) return;
		inOrderToArray(root->leftChild, arr, size); 
		arr[size++] = root->data; 
		inOrderToArray(root->rightChild, arr, size); 
	}
	Node* search(Node* t, int value){
		if (t == nullptr || t->data == value){
			return t;
		}
		if (value > t->data){
			return search(t->rightChild, value);
		}
		if (value < t->data){
			return search(t->leftChild, value);
		}
	}
	void search1(){
		if (search(root, 40)){
			cout << "value 40 found." << endl;
		}
		else{
			cout << "value not found." << endl;
		}
	}
	int max(int a,int b){
		if (a > b){
			return a;
		}
		else
			return b;
	}
	int height(Node* t){
		if (t == nullptr){
			return 0;
		}
		else
			return max(height(t->leftChild), height(t->rightChild)) + 1;
	}
	void height1(){
		cout << "height of a tree is: " << height(root) << endl;
	}
};

bool BST::deleteNode(int value)
{
	if (root == nullptr)
		return false;

	else if (root->leftChild == nullptr && root->rightChild == nullptr) //single node case
	{
		if (root->data == value)
		{
			delete root;
			root = nullptr;
			return true;
		}

		else
			return false;
	}

	// I solemnely declare that I will write the cases of root as discussed in the class
	// I == YOU
	// YOU == Student

	else
	{
		Node* p = root;
		Node* c = root;

		while (1)
		{
			if (c == nullptr)
				return false;

			if (c->data == value)
			{
				break;
			}

			if (value < c->data)
			{
				p = c;
				c = c->leftChild;
			}

			else
			{
				p = c;
				c = c->rightChild;
			}

			
		}

		//cout << p->data << endl;
		//cout << c->data << endl;
		//while (1);

		if (c->leftChild != nullptr && c->rightChild != nullptr)
		{
			//2 children
			Node* t = c;

			p = c;
			c = c->rightChild;

			while (1)
			{
				
				if (c->leftChild == nullptr)
				{
					t->data = c->data;
					value = c->data;
					break;
				}
				else
				{
					p = c;
					c = c->leftChild;
				}
			}
		}

		

		//leaf node deletion:
		if (c->leftChild == nullptr && c->rightChild == nullptr)
		{
			if (c->data < p->data) // left child of parent
			{
				delete c;
				c = nullptr;
				p->leftChild = nullptr;
			}

			else //right child of parent
			{
				delete c;
				c = nullptr;
				p->rightChild = nullptr;
			}

			return true;
		}
	
		else if (c->leftChild != nullptr && c->rightChild == nullptr)
		{
			if (c->data < p->data) //leftChild of parent
			{
				p->leftChild = c->leftChild;
				delete c;
				c = nullptr;
				return true;
			}

			else //right child of parent
			{
				p->rightChild = c->leftChild;
				delete c;
				c = nullptr;
				return true;
			}
		}

		else if (c->leftChild == nullptr && c->rightChild != nullptr)
		{
			if (c->data < p->data) //leftChild of parent
			{
				p->leftChild = c->rightChild;
				delete c;
				c = nullptr;
				return true;
			}

			else //right child of parent
			{
				p->rightChild = c->rightChild;
				delete c;
				c = nullptr;
				return true;
			}

		}
	}

}

void BST::COUNT(Node* p, int &count)
{
	if (p != nullptr)
	{
		COUNT(p->leftChild, count);
		count++;
		COUNT(p->rightChild, count);
	}
}

int BST::countNodes()
{
	int c = 0;
	if (root != nullptr)
		COUNT(root, c);

	else
		cout << "Tree is empty" << endl;

	return c;
}

void BST::POSTORDER(Node* p)
{
	if (p != nullptr)
	{
		POSTORDER(p->leftChild);
		POSTORDER(p->rightChild);
		cout << p->data << endl;
	}
}

void BST::PREORDER(Node* p)
{
	if (p != nullptr)
	{
		cout << p->data << endl;
		PREORDER(p->leftChild);
		PREORDER(p->rightChild);
	}
}

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

void BST::postorder()
{
	if (root != nullptr)
		POSTORDER(root);

	else
		cout << "Tree is empty" << endl;
}

void BST::preorder()
{
	if (root != nullptr)
		PREORDER(root);

	else
		cout << "Tree is empty" << endl;
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
