/*Print the string obtained after removal of outermost parentheses
Difficulty Level : Medium
Last Updated : 05 Jan, 2021
Given a valid parenthesis string str consisting of lowercase alphabets, opening, and closing brackets, the task is to find the string by removing the outermost enclosing brackets such that the string remains a valid parenthesis string.

Examples: 

Input: S = “((((a)(bcd)(e)))”
Output: (a)(bcd)(e)
Explanation: 
The outermost enclosing brackets are: { S[0], S[1], S[13], S[14] }. 
Removing the outermost enclosing brackets from str modifies str to “(a)(bcd)(e)”. 
Therefore, the required output is (a)(bcd)(e).

Input: str = “((ab)(bc))d”
Output: ((ab)(bc))d*/

string solve(string s) {
    int cnt = 0, n = s.length();
    while (cnt < n and s[cnt] == '(' and s[n-cnt-1] == ')') cnt++;

    // min #of ( required to balance the remaining substring s[cnt...n-cnt-1]
    int req = 0;
    // the unbalance in the sequence, where unbalance = #of open bracket - #of closing bracket
    int bal = 0;

    for (int i = cnt; i < n-cnt; ++i) {
        if (s[i] == '(') bal++;
        else bal--;
        req = min(req, bal);
    }

    cnt += req;

    return s.substr(cnt, n-cnt-1);

}