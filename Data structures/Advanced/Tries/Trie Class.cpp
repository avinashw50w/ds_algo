#include <bits/stdc++.h>
using namespace std;

class Trie {

	int ROOT;
	int sz;
	vector<int> leaf;
	unordered_map<char, int> *trie;

public:
	Trie(int N) {
		ROOT = 0;
		sz = 1;
		leaf.assing(N, 0);
		trie = new unordered_map<char,int> [N];
	}

	void insert(string s) {
		int node = ROOT;

		for (int i = 0; i < s.size(); ++i) {
			if (trie[node].count(s[i]) == 0)
				trie[node][s[i]] = sz++;

			node = trie[node][s[i]];
		}

		leaf[node]++;
	}

	int check(string s) {
		int node = ROOT;

		for (int i = 0; i < s.size(); ++i) {
			if (trie[node].count(s[i]) == 0) return false;
			node = trie[node][s[i]];
		}

		return leaf[node] > 0;
	}

	vector<string> prefixQuery(string prefix) {
		int n = prefix.size();
		vector<string> res;
		int node = ROOT;

		for (int i = 0; i < n; ++i) {
			if (trie[node].count(prefix[i]) == 0) return res;
			node = trie[node][prefix[i]]; 
		}

		searchSubtree(node, prefix, res);

		return res;
	}

	void searchSubtree(int node, string s, vector<string> &res) {
		if (leaf[node]) {
			res.push_back(s);
		}

		for (auto i: trie[node]) {
			char c = i.first;
			int newNode = i.second;
			searchSubtree(newNode, s + char(c), res);
		}
	}
};

int main() {
	Trie t;

	t.insert("avinash");
	t.insert("kumar");
	t.insert("makal");
	t.insert("avik");
	vector<string> res =  t.prefixQuery("av");
	for (string s: res) cout << s << " ";
}

///////////////////////////////////////////////////////////////////////

class Trie {

	static const int MAXN = 1e3;
	static const int CHARSET = 255;
	int trie[MAXN][CHARSET];
	bool leaf[MAXN];
	int ROOT;
	int sz;
public:
	Trie() {
		memset(trie, -1, sizeof(trie));
		memset(leaf, 0, sizeof(leaf));
		ROOT = 0;
		sz = 1;
	}

	void insert(string word) {
		int node = ROOT;
		for (int i = 0; i < word.size(); ++i) {
			if (trie[node][word[i]] == -1)
				trie[node][word[i]] = sz++;
			node = trie[node][word[i]];
		}
		leaf[node] = true;
	}

	bool query(string word) {
		int node = ROOT;
		for (int i = 0; i < word.size(); ++i) {
			if (trie[node][word[i]] == -1) return false;
			node = trie[node][word[i]];
		}

		return leaf[node];
	}

	vector<string> prefixQuery(string prefix) {
		vector<string> res;
		int node = ROOT;
		for (int i = 0; i < prefix.size(); ++i) {
			if (trie[node][prefix[i]] == -1) return res;
			node = trie[node][prefix[i]];
		}
		searchSubtree(node, prefix, res);
	}

	void searchSubtree(int node, string prefix, vector<string> &res) {
		if (leaf[node]) {
			res.push_back(prefix);
		}

		for (int i = 0; i < CHARSET; ++i) {
			if (trie[node][i] != -1) {
				searchSubtree(trie[node][i], prefix + char(i), res);
			}
		}

	}
};

