#include"myTrie.h"
int main() {
	myTrie t;
	int choice;
	string input;
	string prefix;
	while (true) {
		t.menu();
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter a word to insert: ";
			cin >> input;
			t.call_insert(input);
			cout << "!!!Word inserted successfully!!!" << endl;
			break;
		case 2:
			cout << "Enter a word to search: ";
			cin >> input;
			if (t.call_search(input)) {
				cout << "!!!Word found!!!" << endl;
			}
			else {
				cout << "!!!Word not found!!!" << endl;
			}
			break;
		case 3:
			cout << "Enter a word to delete: ";
			cin >> input;
			t.call_delete(input);
			cout << "!!!Word deleted successfully!!!" << endl;
			break;
		case 4:
			cout << "Words in the Trie:" << endl;
			t.print();
			break;
		case 5:
			if (t.call_isEmpty()) {
				cout << "Trie is empty." << endl;
			}
			else {
				cout << "Trie is not empty." << endl;
			}
			break;
		case 6:
			cout << "Total number of words: " << t.call_count() << endl;
			break;
		case 7:
			cout << "Longest word: " << t.call_findLongestWord() << endl;
			break;
		case 8:
			cout << "Shortest word: " << t.call_findshortestWord() << endl;
			break;
		case 9:
			cout << "Is There A Palindrome?" << endl;
			t.call_findPalindromes();
			break;
		case 10:
			cout << "Height of the Trie: " << t.call_findHeight() << endl;
			break;
		case 11:
			cout << "Enter prefix to search" << endl;
			cin >> prefix;
			t.call_checkPrefix(prefix);
			break;
		case 12:
			cout << "Enter a word to check anagram: ";
			cin >> input;
			t.call_insert(input);
			t.call_findAnagrams(input);
			break;
		case 13:
			cout << "Enter a word to auto suggest ";
			cin >> prefix;
			t.call_autosuggest(prefix);
		case 14:
			cout << "Exiting program." << endl;
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}

	return 0;
}