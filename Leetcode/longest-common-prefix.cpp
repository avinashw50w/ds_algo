

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int node = 0, sz = 1;
        unordered_map<char, int> trie[(int)1e4];
        int minlen = 1e5;
        string minWord;

        for (string word : s) {
            node = 0;

            if (word.size() < minlen) {
                minlen = word.size();
                minWord = word;
            }

            for (char c : word) {
                if (trie[node].count(c) == 0)
                    trie[node][c] = sz++;
                node = trie[node][c];
            }
        }

        string res = "";
        node = 0;

        for (int i = 0; i < minWord.size(); ++i) {
            if (trie[node].size() > 1) break;
            res += minWord[i];
            node = trie[node][minWord[i]];
        }

        return res;
    }
};

// simple approach

string longestCommonPrefix(vector<string>& strs) {
    string ans;
    if (strs.empty()) return ans;
    if (strs.size() == 1) return strs[0];
    int minLen = INT_MAX;

    for (string s : strs)
        if (s.size() < minLen)
            minLen = s.size();

    for (int i = 0; i < minLen; ++i) {
        for (string s : strs) {
            if (s[i] != strs[0][i]) return ans;
        }
        ans += strs[0][i];
    }

    return ans;
}

// python solution
/*
class Solution(object):
        def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        shortest_len = min([len(i) for i in strs])
        for i in range(shortest_len, -1, -1) :
            if len(set([j[0:i] for j in strs])) == 1:
                return strs[0][0:i]

            return ""
*/