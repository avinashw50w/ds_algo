#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1e3; // no of nodes in the trie
const int CHARSET = 255; // length of the character set
int ROOT = 0;
int sz = 1;

int trie[MAXN][CHARSET];
int leaf[MAXN];

void init() {
	memset(trie, -1, sizeof(trie));
}

void insert(string word) {
	int node = ROOT;

	for(int i = 0; i < word.size(); ++i) {
		if(trie[node][word[i]] == -1)
			trie[node][word[i]] = sz++;
		
		node = trie[node][word[i]];
	}
	++leaf[node];
}

bool search(string word) {
	int node = ROOT;

	for(int i = 0; i < word.size(); ++i) {
		if(trie[node][word[i]] == -1)
			return false;

		node = trie[node][word[i]];
	}

	return leaf[node] > 0;
}

int main() {
	init();

	string words[] = {"hello", "world", "avinash", "kumar"};
	string output[] = {"NO", "YES"};

	int n = sizeof(words)/sizeof(words[0]);

	for(int i = 0; i < n; ++i)
		insert(words[i]);

	cout << output[search("avinash")] << endl;
	cout << output[search("hi")] << endl;
}