/*A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words such that:

The first word in the sequence is beginWord.
The last word in the sequence is endWord.
Only one letter is different between each adjacent pair of words in the sequence.
Every word in the sequence is in wordList.
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog" with 5 words.*/

class Solution {
    static const int maxn = 5001;
    vector<int> g[maxn];
public:
    
    bool isAdjacent(string a, string b) {
        if (a.length() != b.length()) return false;
        int cnt = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) cnt++;
        }
        return cnt == 1;
    }
    
    int bfs(vector<string> words, int src, string dest) {
        queue<int> q;
        q.push(src);
        vector<int> dist(words.size(), -1);
        dist[src] = 0;

        while (q.size()) {
            int u = q.front();
            q.pop();

            if (words[u] == dest) return dist[u];
            
            for(int v: g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return 0;
    }
    // T: O(N^2) where N is the # of words
    // S: O(N)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> words;
        words.push_back(beginWord);
        for (string w: wordList) words.push_back(w);
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isAdjacent(words[i], words[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
    
        return bfs(words, 0, endWord);
    }
};

////////////////////////////////////////////////////////////////
// another approach
// T: O(n*w*26) where n is the #of words in wordlist,
// w is the maximum length of a word in wordlist
int ladderLength(string src, string dest, vector<string>& wordList) {
    unordered_set<string> st;
    for (string s: wordList) st.insert(s);
    queue<string> q;
    unordered_map<string,int> dist;
    q.push(src);
    dist[src] = 0;

    while (q.size()) {
        string u = q.front();
        q.pop();
        string v = u;
        for (int i = 0; i < v.length(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (v[i] == c) continue;
                v[i] = c;
                if (st.count(v)) {
                    if (dist.count(v) == 0) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
                v[i] = u[i];
            }
        }
    }

    return dist[dest];
}