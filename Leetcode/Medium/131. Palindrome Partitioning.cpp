/*Given a string s, partition s such that every substring of the partition is a palindrome. Return all 
possible palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.*/
class Solution {
    vector<vector<int>> p;
    vector<vector<string>> res;
public:
    bool isPalindrome(string str) {
        for (int l = 0, r = (int)str.size()-1; l < r; ++l, --r) {
            if (str[l] != str[r]) return false;
        } 
        return true;
    }
    void solve(string s, vector<string> t) {
        if ((int)s.size() == 0) {
            res.push_back(t);
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            string left = s.substr(0, i+1);
            string right = s.substr(i+1);
            if (isPalindrome(left)) {
                t.push_back(left);
                solve(right, t);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        solve(s, {});
        return res;
    }
};