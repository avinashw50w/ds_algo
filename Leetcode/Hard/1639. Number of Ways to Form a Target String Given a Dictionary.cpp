/* https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/
You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:

target should be formed from left to right.
To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in 
words if target[i] = words[j][k].
Once you use the kth character of the jth string of words, you can no longer use the xth character of any 
string in words where x <= k. In other words, all characters to the left of or at index k become 
unusuable for every string.
Repeat the process until you form the string target.
Notice that you can use multiple characters from the same string in words provided the conditions above 
are met.

Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

Example 1:

Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 1000
All strings in words have the same length.
1 <= target.length <= 1000
words[i] and target contain only lowercase English letters.
*/

typedef long long ll;

class Solution {
    vector<vector<int>> dp, wcnt;
    vector<string> words;
    string target;
    const int mod = 1e9 + 7;
public:
    int solve(int k, int i) {
        if (i == target.length()) return 1;
        if (k >= words[0].length()) return 0;
        
        if (dp[k][i] != -1) return dp[k][i];

        ll ans = 0;
        ll cnt = wcnt[k][target[i]-'a'];

        if (cnt)
            ans += cnt * solve(k+1, i+1);
        
        ans += solve(k+1, i);

        return dp[k][i] = ans % mod;
    }   

    int numWays(vector<string>& words, string target) {
        this->words = words;
        this->target = target;
        int n = words[0].size(), m = target.size();
        // dp[k][i] - # of ways to for the string upto index i from word chars 
        // upto index k
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        
        // wcnt[i][j] stores the freq of char j at pos i of each of the words
        wcnt = vector<vector<int>>(n, vector<int>(26,0));
        for (string word: words) {
            for (int i = 0; i < word.size(); ++i) {
                wcnt[i][word[i]-'a']++;
            }
        }
        return solve(0, 0);
    }
};