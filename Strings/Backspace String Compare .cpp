/*Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
*/

class Solution {
public:
    void solve(string &s) {
        int k = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '#') k = max(0, k-1);
            else s[k++] = s[i];
        }
        
        s.resize(k);
    }
    
    bool backspaceCompare(string S, string T) {
        solve(S);
        solve(T);
        
        return S == T;
    }
};