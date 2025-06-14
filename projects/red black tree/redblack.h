#include "tree.h"
class RedBlack:public tree{
public:
	//  function to find the parent of a node
	Node* findParentNode(Node* root, Node* child) {
		if (root == nullptr){
			return nullptr;
		}
		else if (root->left == child || root->right == child) {
			return root;
		}

		else if (child->data < root->data) {
			return findParentNode(root->left, child);
		}
		else {
			return findParentNode(root->right, child);
		}
	}

	// Rotate left
	void rotateLeft(Node*& root, Node*& node) {
		Node* rightChild = node->right;
		node->right = rightChild->left; 
		rightChild->left = node;        // Move the current node to be the left child of its right child

		// Update the root or parent connection
		if (node == root) {
			root = rightChild;
		}
		else {
			Node* parent = findParentNode(root, node);
			if (parent->left == node) {
				parent->left = rightChild;
			}
			else {
				parent->right = rightChild;
			}
		}
	}

	void RotateRight(Node*& root, Node*& node) {
		Node* leftChild = node->left;
		node->left = leftChild->right; // Update the left subtree of the current node
		leftChild->right = node;       // Move the current node to be the right child of its left child

		if (node == root) {
			root = leftChild; 
		}
		else {
			Node* parent = findParentNode(root, node);
			if (parent->left == node) {
				parent->left = leftChild; // Update parent's left child
			}
			else {
				parent->right = leftChild; // Update parent's right child
			}
		}
	}
	// Fix colours
	void fixcolour(Node*& root, Node*& n) {
		while (n != root && n->colour == 'R' && findParentNode(root, n) != nullptr && findParentNode(root, n)->colour == 'R') {
			Node* p = findParentNode(root, n); //p is parent
			Node* grandparent = findParentNode(root, p);
			if (p == grandparent->left) {
				Node* uncle = grandparent->right;
				if (uncle != nullptr && uncle->colour == 'R') {
					grandparent->colour = 'R';
					p->colour = 'B';
					uncle->colour = 'B';
					n = grandparent;
				}
				else {
					if (n == p->right) {
						rotateLeft(root, p);
						n = p;
						p = findParentNode(root, n);
					}
			
					RotateRight(root, grandparent);
					
					swap(p->colour, grandparent->colour);
					n = p;
				}
			}
			else {
				Node* uncle = grandparent->left;
				if (uncle != nullptr && uncle->colour == 'R') {
					grandparent->colour = 'R';
					p->colour = 'B';
					uncle->colour = 'B';
					n = grandparent;
				}
				else {
					if (n == p->left) {
						RotateRight(root, p);
						n = p;
						p = findParentNode(root, n);
					}
				
						rotateLeft(root, grandparent);
					
					swap(p->colour, grandparent->colour);
					n = p;
				}
			}
		}
		root->colour = 'B';
	}
	// Insert a new value into the tree
	void insert(int value) {
		Node* nn = new Node(value);
		if (root == nullptr) {
			root = nn;
			root->colour = 'B';
			return;
		}
		Node* c = root;
		Node* p = nullptr;
		while (1) {
			p = c;
			if (nn->data < c->data) {
				c = c->left;
			}
			else {
				c = c->right;
			}
			if (c == nullptr){
				break;
			}
		}
		if (nn->data < p->data) {
			p->left = nn;
		}
		else {
			p->right = nn;
		}
		fixcolour(root, nn);
	}

	//searching values
	Node* search(Node* t, int value) {
		if (t==nullptr || t->data == value) {
			return t;
		}
		if (value < t->data) {
			return search(t->left, value);
		}
		if (value > t->data){
			return search(t->right, value);
		}
	}
	void search1(int value){
		if (search(root,value)){
			cout << "value found." << endl;
		}
		else{
			cout << "value don't exist." << endl;
		}
	}
	//inorder
	void INORDER(Node* t){
		if (t != nullptr){
			INORDER(t->left);
			cout << t->data << " (";
			cout << t->colour <<") "<< endl;
			INORDER(t->right);
		}
	}
	void inorder(){
		if (root!= nullptr){
			INORDER(root);
		}
		else{
			cout << "Tree is empty." << endl;
		}
	}
	//preorder
	void PREORDER(Node* t){
		if (t != nullptr){
			cout << t->data << " (";
			cout << t->colour << ") " << endl;
			PREORDER(t->left);
			PREORDER(t->right);
		}
	}
	void preorder(){
		if (root != nullptr){
			PREORDER(root);
		}
		else{
			cout << "Tree is empty." << endl;
		}
	}
	//postorder
	void POSTORDER(Node* t){
		if (t != nullptr){
			POSTORDER(t->left);
			POSTORDER(t->right);
			cout << t->data << " (";
			cout << t->colour << ") " << endl;
		}
	}
	void postorder(){
		if (root != nullptr){
			POSTORDER(root);
		}
		else{
			cout << "Tree is empty." << endl;
		}
	}
	//for descending
	//inorder
	void INORDER2(Node* t){
		if (t != nullptr){
			INORDER2(t->right);
			cout << t->data << " (";
			cout << t->colour << ") " << endl;
			INORDER2(t->left);
		}
	}
	void inorder2(){
		if (root != nullptr){
			INORDER2(root);
		}
		else{
			cout << "Tree is empty." << endl;
		}
	}
	//preorder
	void PREORDER2(Node* t){
		if (t != nullptr){
			cout << t->data << " (";
			cout << t->colour << ") " << endl;	
			PREORDER2(t->right);
			PREORDER2(t->left);
		}
	}
	void preorder2(){
		if (root != nullptr){
			PREORDER2(root);
		}
		else{
			cout << "Tree is empty." << endl;
		}
	}
	//postorder
	void POSTORDER2(Node* t){
		if (t != nullptr){
			POSTORDER2(t->right);
			POSTORDER2(t->left);
			cout << t->data << " (";
			cout << t->colour << ") " << endl;
		}
	}
	void postorder2(){
		if (root != nullptr){
			POSTORDER2(root);
		}
		else{
			cout << "Tree is empty." << endl;
		}
	}
	////parent search
	void parentSearch(Node* c, int value, int p = -1) {
		if (c==nullptr) {
			return;
		}
		if (c->data == value) {
			cout << "Parent of " << value << ": ";
			if (p == -1) {
				cout << "No parent" << endl;
			}
			else {
				cout << p << endl;
			}
			return;
		}
		parentSearch(c->left, value, c->data);
		parentSearch(c->right, value, c->data);
	}
	void parent(int value) {
		parentSearch(root, value);
	}
	//destroy tree
	void destroyTree(Node* t) {
		if (t==nullptr) {
			return;
		}
		destroyTree(t->left);
		destroyTree(t->right);
		delete t;
		t = nullptr;
	}
	void destroy_tree() {
		destroyTree(root);
	}

	// Fix the colors after deletion
	void fixDelete(Node*& root, Node*& n) {
		while (n != root && n->colour == 'B') {
			Node* p = findParentNode(root, n); // p is the parent of n
			if (n == p->left) {
				Node* sibling = p->right;
				if (sibling->colour == 'R') {
					sibling->colour = 'B';
					p->colour = 'R';
					rotateLeft(root, p);
					sibling = p->right;
				}
				if (sibling->left->colour == 'B' && sibling->right->colour == 'B') {
					sibling->colour = 'R';
					n = p;
				}
				else {
					if (sibling->right->colour == 'B') {
						sibling->left->colour = 'B';
						sibling->colour = 'R';
						RotateRight(root, sibling);
						sibling = p->right;
					}
					sibling->colour = p->colour;
					p->colour = 'B';
					sibling->right->colour = 'B';
					rotateLeft(root, p);
					n = root;
				}
			}
			else {
				Node* sibling = p->left;
				if (sibling->colour == 'R') {
					sibling->colour = 'B';
					p->colour = 'R';
					RotateRight(root, p);
					sibling = p->left;
				}
				if (sibling->left->colour == 'B' && sibling->right->colour == 'B') {
					sibling->colour = 'R';
					n = p;
				}
				else {
					if (sibling->left->colour == 'B') {
						sibling->right->colour = 'B';
						sibling->colour = 'R';
						rotateLeft(root, sibling);
						sibling = p->left;
					}
					sibling->colour = p->colour;
					p->colour = 'B';
					sibling->left->colour = 'B';
					RotateRight(root, p);
					n = root;
				}
			}
		}
		n->colour = 'B';
	}
	void deleteValue(int value){
		deleteNode(root, value);
	}
	// Delete a node from the tree
	void deleteNode(Node*& root, int value) {
		Node* nodeToDelete = findNode(root, value);  // Find the node to delete
		if (nodeToDelete == nullptr) {
			return;  // Node not found
		}

		Node* replacement = nullptr;
		if (nodeToDelete->left == nullptr || nodeToDelete->right == nullptr) {
			replacement = nodeToDelete;
		}
		else {
			replacement = getSuccessor(nodeToDelete);
		}

		Node* child = (replacement->left != nullptr) ? replacement->left : replacement->right;

		if (child != nullptr) {
			Node* parent = findParentNode(root, replacement);
			if (parent != nullptr) {
				if (replacement == parent->left) {
					parent->left = child;
				}
				else {
					parent->right = child;
				}
			}
			child->colour = 'B';
		}

		if (replacement != nodeToDelete) {
			nodeToDelete->data = replacement->data;
		}

		// Handle root deletion
		if (replacement == root) {
			root = child;
		}

		if (replacement->colour == 'B') {
			fixDelete(root, child);
		}

		delete replacement;
	}

	// Helper function to find the node by value
	Node* findNode(Node* root, int value) {
		while (root != nullptr) {
			if (value < root->data) {
				root = root->left;
			}
			else if (value > root->data) {
				root = root->right;
			}
			else {
				return root;
			}
		}
		return nullptr;
	}

	// Helper function to find the in-order successor
	Node* getSuccessor(Node* node) {
		Node* successor = node->right;
		while (successor->left != nullptr) {
			successor = successor->left;
		}
		return successor;
	}

};