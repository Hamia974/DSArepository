#include "Trie.h"
class myTrie :public Trie {
private:
	// Calculate index
	int calculate_index(const string& word) {
		char c = word[0];
		int index;
		if (c >= 'a' && c <= 'z') {
			index = c - 'a';
		}
		else if (c >= 'A' && c <= 'Z') {
			index = c - 'A' + 26;
		}
		else {
			index = -1;
		}
		return index;
	}
	// Insertion
	void insert_recursively(TrieNode* root, const string& word) {
		if (word.length() == 0) {
			root->terminalnode = true;
			return;
		}
		int index = calculate_index(word);
		if (index == -1) {
			insert_recursively(root, word.substr(1));
			return;
		}
		if (root->children[index] == nullptr) {
			root->children[index] = new TrieNode();
		}
		insert_recursively(root->children[index], word.substr(1));
	}
	// display
	void printWords(TrieNode* current, const string& word) {
		if (current->terminalnode) {
			cout << word << endl;
		}
		for (int i = 0; i < 52; ++i) {
			if (current->children[i]) {
				char c;
				if (i < 26) {
					c = 'a' + i;
				}
				else {
					c = 'A' + (i - 26);
				}
				printWords(current->children[i], word + c);
			}
		}
	}

	//search
	bool search_recursively(TrieNode* root, const string& word) {
		if (word.length() == 0) {
			return root->terminalnode;
		}
		int index = calculate_index(word);
		if (index == -1) {
			return false;
		}
		if (root->children[index] == nullptr) {
			return false;
		}

		return search_recursively(root->children[index], word.substr(1));
	}

	//deletion
	TrieNode* delete_recursively(TrieNode* root, const string& word, int depth = 0) {
		if (!root) {
			return nullptr;
		}
		if (depth == word.length()) {
			if (root->terminalnode) {
				root->terminalnode = false;
			}
			if (isEmpty(root)) {
				delete root;
				root = nullptr;
			}

			return root;
		}
		char c = word[depth];
		int index;
		if (c >= 'a' && c <= 'z') {
			index = c - 'a';
		}
		else if (c >= 'A' && c <= 'Z') {
			index = c - 'A' + 26;
		}
		else{
			return root;
		}

		root->children[index] = delete_recursively(root->children[index], word, depth + 1);

		if (isEmpty(root) && !root->terminalnode) {
			delete root;
			root = nullptr;
		}

		return root;
	}

	//count
	int countWords(TrieNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int count = 0;
		if (root->terminalnode) {
			count++;
		}
		for (int i = 0; i < 52; ++i) {
			if (root->children[i]) {
				count += countWords(root->children[i]);
			}
		}

		return count;
	}

	//empty
	bool isEmpty(TrieNode* root) {
		for (int i = 0; i < 52; i++) {
			if (root->children[i]) {
				return false;
			}
		}
		return true;
	}
	//longest word
	void findLongestWord(TrieNode* root, string currentWord, string& longestWord) {
		if (root == nullptr) return;

		if (root->terminalnode) {
			if (currentWord.length() > longestWord.length()) {
				longestWord = currentWord;
			}
			else if (currentWord.length() == longestWord.length()) {
				if (currentWord < longestWord) {
					longestWord = currentWord;
				}
			}
		}
		for (int i = 0; i < 52; ++i) {
			if (root->children[i] != nullptr) {
				char c;
				if (i < 26) {
					c = 'a' + i; 
				}
				else {
					c = 'A' + (i - 26); 
				}
				findLongestWord(root->children[i], currentWord + c, longestWord);
			}
		}
	}


	//shortest word
	void findshortestword(TrieNode* root, string currentWord, string& shortestWord) {
		if (root == nullptr) {
			return;
		}
		if (root->terminalnode) {
			if (shortestWord.empty()) {
				shortestWord = currentWord;
			}
			else if (currentWord.length() < shortestWord.length()) {
				shortestWord = currentWord;
			}
			else if (currentWord.length() == shortestWord.length()) {
				if (currentWord < shortestWord) {
					shortestWord = currentWord;
				}
			}
		}
		for (int i = 0; i < 52; ++i) {
			if (root->children[i] != nullptr) {
				char c;
				if (i < 26) {
					c = 'a' + i; 
				}
				else {
					c = 'A' + (i - 26); 
				}
				findshortestword(root->children[i], currentWord + c, shortestWord);
			}
		}
	}

	//palindrome
	bool isPalindrome(const string& word) {
		int left = 0, right = word.length() - 1;
		while (left < right) {
			if (word[left] != word[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
	bool findPalindromes(TrieNode* root, string currentWord, bool& foundPalindrome) {
		if (root == nullptr) return false;
		if (root->terminalnode && isPalindrome(currentWord)) {
			cout << "Yes!  " << currentWord << endl;
			foundPalindrome = true;
		}
		for (int i = 0; i < 52; ++i) {
			if (root->children[i]) {
				char c;
				if (i < 26) {
					c = 'a' + i; 
				}
				else {
					c = 'A' + (i - 26); 
				}
				findPalindromes(root->children[i], currentWord + c, foundPalindrome);
			}
		}
		return foundPalindrome;
	}
	//height of trie
	int max(int a, int b){
		if (a > b){ return a; }
		else { return b; }
	}
	int findHeight(TrieNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int maxHeight = 0;
		for (int i = 0; i < 52; ++i) {
			if (root->children[i]) {
				maxHeight = max(maxHeight, findHeight(root->children[i]));
			}
		}
		return maxHeight + 1;
	}
	//prefix
	bool checkPrefix(TrieNode* root, const  string& prefix, int& count) {
		TrieNode* currentNode = root;
		string currentWord = prefix;

		for (int i = 0; i < prefix.length(); ++i) {
			char c = prefix[i];
			int index;
			if (c >= 'a' && c <= 'z') {
				index = c - 'a';
			}
			else if (c >= 'A' && c <= 'Z') {
				index = c - 'A' + 26;
			}
			else {
				return false;
			}
			if (currentNode->children[index] == nullptr) {
				return false;
			}
			currentNode = currentNode->children[index];
		}

		printWordsWithPrefix(currentNode, currentWord, count);
		return true;
	}

	void printWordsWithPrefix(TrieNode* node, string currentWord, int& count) {
		if (node->terminalnode) {
			cout << "Word with prefix found: \"" << currentWord << "\"" << endl;
			count++;
			cout << "Count: " << count << endl;
		}
		for (int i = 0; i < 52; ++i) {
			if (node->children[i] != nullptr) {
				char c;
				if (i < 26) {
					c = 'a' + i; 
				}
				else {
					c = 'A' + (i - 26); 
				}
				printWordsWithPrefix(node->children[i], currentWord + c, count);
			}
		}
	}
	//anagram
	string sort(const string& word) {
		string sortedWord = word;
		int n = sortedWord.length();
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (sortedWord[j] > sortedWord[j + 1]) {
					swap(sortedWord[j], sortedWord[j + 1]);
				}
			}
		}
		return sortedWord;
	}
	bool areAnagrams(const string& word1, const string& word2) {
		string sorted_word1 = sort(word1);
		string sorted_word2 = sort(word2);
		return sorted_word1 == sorted_word2;
	}
	bool findAnagram(TrieNode* current, const string& word, string currentWord) {
		if (current == nullptr) return false;
		if (current->terminalnode && areAnagrams(word, currentWord)) {
			cout << "Anagram found: " << currentWord << endl;
			return true;
		}
		bool foundAnagram = false;
		for (int i = 0; i < 52; ++i) {
			if (current->children[i]) {
				char c;
				if (i < 26) {
					c = 'a' + i;
				}
				else {
					c = 'A' + (i - 26);
				}
				bool result = findAnagram(current->children[i], word, currentWord + c);
				if (result) {
					foundAnagram = true;
				}
			}
		}
	}
	//auto
	void findSuggestions(TrieNode* node, string prefix) {
		if (node == nullptr) return;
		if (node->terminalnode) {
			cout << prefix << endl;
		}
		for (int i = 0; i < 52; ++i) {
			if (node->children[i]) {
				char c;
				if (i < 26) {
					c = 'a' + i;
				}
				else {
					c = 'A' + (i - 26);
				}
				findSuggestions(node->children[i], prefix + c);
			}
		}
	}
	void autoSuggestions(TrieNode* root, const string& prefix) {
		TrieNode* node = root;
		int count = 0;
		if (checkPrefix(root, prefix, count)) {
			cout << "Suggestions for prefix \"" << prefix << "\":" << endl;
			findSuggestions(node, prefix);
		}
		else {
			cout << "No suggestions found!" << endl;
		}
	}
public:
	myTrie() :Trie(){}
	void call_insert(const string& word) {
		insert_recursively(root, word);
	}
	void print() {
		printWords(root, "");
	}
	bool call_search(const string& word) {
		return search_recursively(root, word);
	}
	void call_delete(const string& word) {
		root = delete_recursively(root, word);
	}
	bool call_isEmpty() {
		return isEmpty(root);
	}
	int call_count() {
		return countWords(root);
	}

	string call_findLongestWord() {
		string longestWord = "", currentWord = "";
		findLongestWord(root, currentWord, longestWord);
		return longestWord;
	}
	string call_findshortestWord() {
		string shortestWord = "", currentword = "";
		findshortestword(root, currentword, shortestWord);
		return shortestWord;
	}
	void call_findPalindromes() {
		bool foundPalindrome = false;
		if (!findPalindromes(root, "", foundPalindrome)) {
			cout << "No palindrome in trie" << endl;
		}
	}
	void call_checkPrefix(const  string& prefix) {
		int count = 0;

		if (checkPrefix(root, prefix, count)) {
			cout << "Prefix \"" << prefix << "\" found" << endl;
		}
		else {
			cout << "Prefix not found" << endl;
		}
	}
	int call_findHeight() {
		return findHeight(root) - 1;
	}
	bool call_findAnagrams(const string& word) {
		return findAnagram(root, word, "");
	}
	void call_autosuggest(const string& prefix){
		autoSuggestions(root, prefix);
	}

	void menu() {
		cout << "========================" << endl;
		cout << "  TRIE FUNCTIONALITIES " << endl;
		cout << "========================" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Search" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Print" << endl;
		cout << "5. Check if Empty" << endl;
		cout << "6. Count Words" << endl;
		cout << "7. Find Longest Word" << endl;
		cout << "8. Find Shortest Word" << endl;
		cout << "9. Find Palindromes" << endl;
		cout << "10. Find Height" << endl;
		cout << "11. Search a Prefix" << endl;
		cout << "12. Check if word is anagram" << endl;
		cout << "13. Auto suggestion" << endl;
		cout << "14. Exit" << endl;
		cout << "Enter your choice: ";
	}
};
