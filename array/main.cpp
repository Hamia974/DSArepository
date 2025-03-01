#include "CustomList.h"
int main() {
		CustomList<int> list;
		int choice, value, index, rotations;
		do {
			cout << "Menu:\n";
			cout << "1. Add element at first index\n";
			cout << "2. Add element at last index\n";
			cout << "3. Remove element from end\n";
			cout << "4. Remove element from start\n";
			cout << "5. Check if empty\n";
			cout << "6. Check if full\n";
			cout << "7. Get size\n";
			cout << "8. Insert at index\n";
			cout << "9. Get last element\n";
			cout << "10. Search element\n";
			cout << "11. Sum of primes\n";
			cout << "12. Second max even\n";
			cout << "13. Second min odd\n";
			cout << "14. Print duplicates\n";
			cout << "15. Rotate clockwise\n";
			cout << "16. Rotate anti-clockwise\n";
			cout << "0. Exit\n";
			cout << "Enter choice: ";
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "Enter value: ";
				cin >> value;
				list.addElementAtFirstIndex(value);
				break;
			case 2:
				cout << "Enter value: ";
				cin >> value;
				list.addElementAtLastIndex(value);
				break;
			case 3:
				cout << "Removed: " << list.removeElementFromEnd() << "\n";
				break;
			case 4:
				list.removeElementFromStart();
				cout << "Element removed from start\n";
				break;
			case 5:
				if (list.empty()){
					cout << "list is empty." << endl;
				}
				break;
			case 6:
				if (list.full()){
					cout << "list is full." << endl;
				}
				else{
					cout << "list is not full." << endl;
				}
					break;
			case 7:
				cout << "Current size: " << list.size() << "\n";
				break;
			case 8:
				cout << "Enter index and value: ";
				cin >> index >> value;
				if (list.insertAt(index, value)) {
					cout << "Inserted at index " << index << "\n";
				}
				else {
					cout << "Failed to insert at index " << index << "\n";
				}
				break;
			case 9:
				cout << "Last element: " << list.last() << "\n";
				break;
			case 10:
				cout << "Enter value to search: ";
				cin >> value;
				if (list.search(value)){
					cout << "Element found" << endl;
				}
				else{
					cout << "Element not found." << endl;
				}
				break;
			case 11:
				cout << "Sum of primes: " << list.sum_ofPrime() << "\n";
				break;
			case 12:
				cout << "Second max even: " << list.secondMaxEven() << "\n";
				break;
			case 13:
				cout << "Second min odd: " << list.secondMinOdd() << "\n";
				break;
			case 14:
				list.printDuplicates();
				break;
			case 15:
				cout << "Enter number of rotations: ";
				cin >> rotations;
				list.rotateClockwise(rotations);
				break;
			case 16:
				cout << "Enter number of anti-clockwise rotations: ";
				cin >> rotations;
				list.rotateAntiClockwise(rotations);
				break;
			case 0:
				cout << "Exiting...\n";
				break;
			default:
				cout << "Invalid choice, try again.\n";
				}
				
			} while (choice != 0);
		
		return 0;
	
}