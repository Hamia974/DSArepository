#include "TrieNode.h"
#include <iostream>
#include <string>
using namespace std;
class Trie{
protected:
	TrieNode* root;
	Trie() {
		root = new TrieNode();
	}
public:
	virtual void insert_recursively(TrieNode*, const string&) = 0;
	virtual void printWords(TrieNode* , const string& ) = 0;
	virtual bool search_recursively(TrieNode* , const string&) = 0;
	virtual TrieNode* delete_recursively(TrieNode* , const string& , int depth = 0) = 0;
	virtual int countWords(TrieNode*) = 0;
	virtual bool isEmpty(TrieNode*) = 0;
	virtual void findLongestWord(TrieNode* , string , string& ) = 0;
	virtual void findshortestword(TrieNode* , string , string& ) = 0;
	virtual bool findPalindromes(TrieNode* , string , bool& ) = 0;
	virtual int findHeight(TrieNode* ) = 0;
	virtual bool checkPrefix(TrieNode* , const  string&, int&) = 0;
	virtual bool findAnagram(TrieNode* , const string& , string) = 0;
	virtual void findSuggestions(TrieNode*, string ) = 0;
	virtual void menu() = 0;

};