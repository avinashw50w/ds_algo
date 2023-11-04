/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]*/
class Solution {
    vector<string> ans;
    int n;
public:

    void solve(string s, int open, int close) {
        if (close == n) {
            ans.push_back(s);
            return;
        }
  
        if (open > close) {
            solve(s + ")", open, close + 1);
        }

        if (open < n) {
            solve(s + "(", open + 1, close);
        }
    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        solve("", 0, 0);

        return ans;
    }
};