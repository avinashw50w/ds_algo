/*Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

Input: "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Input: "aaaaaaaaa"
Output: "a"
explanation: remove only adjacent duplicates
*/

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length(), i = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] == s[i])
                return removeDuplicates(s.substr(0, i - 1) + s.substr(i + 1));
        }
        return s;
    }
};

// stack based (recommended)
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            
            if (st.empty() or st.top() != s[i]) st.push(s[i]);
            else st.pop();
            
        }
        
        string ss = "";
        while (!st.empty()) {
            ss += st.top();
            st.pop();
        }
        
        reverse(ss.begin(), ss.end());
        return ss;
    }
};