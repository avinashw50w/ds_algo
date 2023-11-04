/*Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []*/
class Solution {
    set<string> dict;
    vector<vector<string>> res;
public:
    void solve(string s, vector<string> buff) {
        if (s.empty()) return;
        
        for (int i = 0; i < s.size(); ++i) {
            string left = s.substr(0, i + 1);
            string right = s.substr(i + 1);
            
            if (dict.count(left)) {
                buff.push_back(left);
                if (right.empty()) {
                    res.push_back(buff);
                }
                
                solve(right, buff);
                buff.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string e: wordDict) dict.insert(e);
        
        vector<string> buff;
        solve(s, buff);
        
        vector<string> ans;
        for (auto v: res) {
            string t;
            for (int i = 0; i < v.size(); ++i) {
                if (i) t += " ";
                t += v[i];
            }
            ans.push_back(t);
        }
        return ans;
    }
};