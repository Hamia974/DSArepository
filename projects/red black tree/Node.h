struct Node
{
	int data;
	Node* left;
	Node* right;
	char colour;
	//constructor
	Node(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
		colour = 'R';
	}
};