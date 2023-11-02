/*Given a sorted dictionary of an alien language, find order of characters
Given a sorted dictionary (array of words) of an alien language, find order of characters in the language.
Examples:

Input:  words[] = {"baa", "abcd", "abca", "cab", "cad"}
Output: Order of characters is 'b', 'd', 'a', 'c'
Note that words are sorted and in the given language "baa" 
comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Input:  words[] = {"caa", "aaa", "aab"}
Output: Order of characters is 'c', 'a', 'b' */

/*The idea is to create a graph of characters and then find topological sorting of the created graph. 
Following are the detailed steps.

1) Create a graph g with number of vertices equal to the size of alphabet in the given alien language. 
For example, if the alphabet size is 5, then there can be 5 characters in words. Initially there are no edges in graph.

2) Do following for every pair of adjacent words in given sorted array.
…..a) Let the current pair of words be word1 and word2. One by one compare characters of both words 
and find the first mismatching characters.
…..b) Create an edge in g from mismatching character of word1 to that of word2.

3) Print topological sorting of the above created graph.*/

// Use Topological sorting

vector<int> G[26];
int vis[26];

void dfs(int u, vector<char> &s) {
	vis[u] = 1;

	for (auto v: G[u]) {
		if (!vis[v]) dfs(v, s);
	}

	s.push_back(u);
}

void topologicalSort(vector<char> &res){
	memset(vis, 0, sizeof(vis));

	for (int i = 0; i < 26; ++i) {
		if (!vis[i]) dfs(i, st);
	}

	reverse(res.begin(), res.end());
	return res;
}

vector<char> getOrder(vector<string> words) {
	int N = words.size();
	vector<char> res;

	for (int i = 0; i < N-1; ++i) {

		string s1 = words[i], s2 = words[i+1];

		for (int j = 0; j < min(s1.size(), s2.size()); ++j) {
			if (s1[j] != s2[j]) {
				G[s1[j]-'a'].push_back(s2[j]-'a');
				break;
			}
		}
	}

	topologicalSort(res);

	return res;
}