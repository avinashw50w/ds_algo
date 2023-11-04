/*A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words such that:

The first word in the sequence is beginWord.
The last word in the sequence is endWord.
Only one letter is different between each adjacent pair of words in the sequence.
Every word in the sequence is in wordList.
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists.

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]*/

class Solution {
    unordered_map<string, unordered_set<string>> adj;
    vector<vector<string>> ans;
public:
    // NOTE : taking adj as not &adj gave TLE, so always take & 
    void dfs(string src, string dest, vector<string> path) {
        path.push_back(src);
        
        if (src == dest) {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        for (string s: adj[src]) {
            dfs(s, dest, path, adj);
        }
        
        path.pop_back();
    }
    
    vector<vector<string>> findLadders(string src, string dest, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<string> q;
        unordered_map<string, int> dist;
        
        q.push(src);
        dist[src] = 0;
        
        while (q.size()) {
            string top = q.front(); q.pop();
            string t = top;
            // change a char in t and check if it exists in the dictionary
            for (int i = 0; i < t.length(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    // change 1 character in t
                    if (t[i] == c) continue;
                    t[i] = c;
                    if (words.count(t)) {
                        // if t is not visited yet
                        if (dist.count(t) == 0) {
                            dist[t] = dist[top] + 1;
                            adj[top].insert(t);
                            q.push(t);
                        }
                        // if t has been visited and is 1 dist away from its parent 
                        else if (dist[t] == dist[top] + 1) {
                            adj[top].insert(t);
                        }
                    }
                    // revert back that changed character
                    t[i] = top[i];
                }
            }
        }
        
        vector<string> path;
        
        dfs(src, dest, path);
        
        return ans;
    }
};