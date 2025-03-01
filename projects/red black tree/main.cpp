#include "redblack.h"
#include <fstream>
int main(){
	RedBlack t;
	int choice, value;
	do {
		cout << "----------------------Main Menu------------------------" << endl;
		cout << "Press 1 to insert values in the tree(one by one)" << endl;
		cout << "Press 2 for searching a value from the tree" << endl;
		cout << "Press 3 for pre - order traversal NLR " << endl;
		cout << "Press 4 for in - order traversal LNR " << endl;
		cout << "Press 5 for post - order traversal LRN " << endl;
		cout << "Press 6 for pre - order traversal 2 NRL " << endl;
		cout << "Press 7 for in - order traversal 2 RNL " << endl;
		cout << "Press 8 for post - order traversal 2 RLN " << endl;
		cout << "Press 9 for displaying parent of a node present in Tree " << endl;
		cout << "Press 10 to read integer values from the fin (input.txt) to create a red - black tree "<<endl;
		cout << "Press 11 to destroy the complete tree. " << endl;
		cout << "Press 12 to delete values. " << endl;
		cout << "Press 13 to EXIT. " << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter value to insert: ";
			cin >> value;
			t.insert(value);
			break;
		case 2:
			cout << "Enter value to search: ";
			cin >> value;
			t.search1(value);
			break;
		case 3:
			t.preorder();
			break;
		case 4:
			t.inorder();
			break;
		case 5:
			t.postorder();
			break;
		case 6:
			t.preorder2();
			break;
		case 7:
			t.inorder2();
			break;
		case 8:
			t.postorder2();
			break;
		case 9:
			cout << "Enter node value to find parent: ";
			cin >> value;
			t.parent(value);
			break;
		case 10: {
					 ifstream fin;
					 fin.open("input.txt");
					 if (!fin.is_open()) {
						 cout << "file not found." << endl;
					 }
					 else {
						 while (fin >> value) {
							 t.insert(value);
						 }
					 }
					 fin.close();
					 break;
		}
		case 11:
			t.destroy_tree();
			cout << "Tree destroyed successfully."<<endl;
			break;
		case 12:
			cout << "enter value to be delted: ";
			cin >> value;
			t.deleteValue(value);
			break;
		case 13:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice."<<endl;
		}
	} while (choice != 13);

}