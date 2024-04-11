#include <bits/stdc++.h>

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isLeaf;

    TrieNode() : isLeaf(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isLeaf = true;
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false; // Character not found
            }
            curr = curr->children[ch];
        }
        return curr != nullptr && curr->isLeaf;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    cout << boolalpha;
    cout << "Search 'apple': " << trie.search("apple") << endl;    // Output: true
    cout << "Search 'app': " << trie.search("app") << endl;        // Output: true
    cout << "Search 'banana': " << trie.search("banana") << endl;  // Output: true
    cout << "Search 'appl': " << trie.search("appl") << endl;      // Output: false
    cout << "Search 'ban': " << trie.search("ban") << endl;        // Output: false

    return 0;
}
