struct TrieNode {
	bool terminalnode;
	TrieNode* children[52];
	TrieNode() {
		terminalnode = false;
		for (int i = 0; i < 52; i++) {
			children[i] = nullptr;
		}
	}
};