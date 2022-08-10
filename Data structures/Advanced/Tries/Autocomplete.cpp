struct Node {
    char c;
    vector<Node*> children;
    bool isLeaf;

    Node (char c) {
        this->c = c;
        this->children = new vector<Node*>(26, NULL);
        this->isLeaf = false;
    } 
};

class Solution {
    Node *trie;

public:
    Solution(vector<string> dict) {
        this->trie = new Node("");
        for (string word: dict) insert(word);
    } 

    void insert(string word) {
        Node *curr = trie;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (curr->children[c-'a'] == NULL) {
            	curr->chlildren[c-'a'] = new Node(c);
            }
        	curr = curr->children[c-'a'];
        }

        curr->isLeaf = true;
    }

    vector<string> getWords(string prefix) {
        vector<string> res;

        Node *curr = trie;

        for (char c: prefix) {
            if (curr->children[c-'a'] != NULL) {
                curr = curr->children[c-'a'];
            }
            else return res;
        }

        getWordsRec(curr, res, prefix);

        return res;
    }

    void getWordsRec(Node *curr, vector<stirng> &res, string prefix) {
        if (curr->isLeaf) {
            res.push_back(prefix);
        }

        for (int i = 0; i < 26; ++i ) {
            if (curr->children[i] != NULL) {
                prefix += curr->children[i]->c;
                getWordsRec(curr->children[i], res, prefix);
            }
        }
    }

};

#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Node {
	string prefix;
	map<char, Node*> *children;
	bool isWord;

	Node(string prefix) {
		this -> prefix = prefix;
		this -> isWord = false;
		this -> children = new map<char, Node*>;
	}
};

class Autocomplete {
	Node *trie;

public:
	Autocomplete(vector<string> dict) {
		trie = new Node("");
		for(string s: dict) insertWord(s);
	}

	void insertWord(string s) {
		Node *curr = trie;
		
		for(int i = 0; i < s.length(); ++i) {
			char c = s[i];
			if(curr -> children -> count(c) == 0) {
				curr -> children -> insert({c, new Node(s.substr(0, i+1))});
			}

			auto it = curr -> children -> find(c);
			curr = it -> second;

			if(i == s.length() - 1) curr -> isWord = true;
		}
	}

	vector<string> getWordsForPrefix(string pre) {
		vector<string> res;
		
		Node *curr = trie;

		for(char c: pre) {
			if(curr -> children -> count(c) != 0)
				curr = curr -> children -> find(c) -> second;
			else 
				return res;
		}	

		findAllChildWords(curr, res);

		return res;
	}

	void findAllChildWords(Node *n, vector<string> &res) {
		if(n -> isWord) res.push_back(n -> prefix);

		for(auto i: *(n -> children)) {
			findAllChildWords(i.second, res);
		}
	}
};


int main() {

	vector<string> words = {"avinash", "kumar", "saw", "kushal", "sagar", "karan"};

	Autocomplete *ac = new Autocomplete(words);

	vector<string> w = ac -> getWordsForPrefix("k");

	for(auto i: w) cout << i << endl;
}
