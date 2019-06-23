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
