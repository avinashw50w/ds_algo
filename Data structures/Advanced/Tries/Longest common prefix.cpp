#include <bits/stdc++.h>
using namespace std;

class Trie {
	
	unordered_map<char, int> *trie;
	vector<int> leaf;
	int ROOT;
	int sz;
	
public:
	Trie(int N) {
		ROOT = 0;
		sz = 1;
		trie = new unordered_map<char, int> [N];
		leaf.assign(N, 0);
	}
	
	void insert(string s) {
		
		int node = ROOT;
		for (int i = 0; i < s.size(); ++i) {
			
			if(trie[node].count(s[i]) == 0)
				trie[node][s[i]] = sz++;
			
			node = trie[node][s[i]];
		}
		
		leaf[node] = 1;
	}
	
	int check(string s) {
		
		int node = ROOT;
		for (int i = 0; i < s.size(); ++i) {
			
			if (trie[node].count(s[i]) == 0) return false;
			node = trie[node][s[i]];
		}
		
		return leaf[node];
	}
	
	string LCP() {
		
		string res = "";
		int node = ROOT;
		while(trie[node].size() == 1) {
			char c = trie[node].begin()->first;
			res += c;
			node = trie[node][c];
		}
		
		return res;
	}
};

string solve(vector<string> s) {
	int n = s.size();
	int minLen = 1;
	Trie t(1000);
	for (int i = 0; i < n; ++i) t.insert(s[i]);
	
	return t.LCP();
}

int main() {
	
	vector<string> s = {"avinash", "avik", "avishek"};
	
	cout << solve(s);
}