/*Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
 

Note:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.
*/

class Solution {
public:
    bool isPredecessor(string a, string b) {
        vector<int> f(26, 0);
        for (char c: a) f[c-'a']--;
        for (char c: b) f[c-'a']++;
        int cnt = 0;
        for (int i: f) cnt += i > 0;
        return cnt == 1;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string a, string b) { return a.size() < b.size(); });
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (words[i].size() - words[j].size() == 1 and 
                    isPredecessor(words[j], words[i]) and dp[i] < dp[j]+1) {
                    
                    dp[i] = dp[j]+1;
                    ans = max(ans, dp[i]);
                }
            }
        }
        
        return ans;
        
    }
};