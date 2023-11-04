/*Given a string s representing an expression, implement a basic calculator to evaluate it.
Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
*/
class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;
        int i = 0, res = 0, sign = 1;
        while (i < n) {
            if (isdigit(s[i])) {
                int len = 0, num = 0;
                while (i + len < n and isdigit(s[i+len])) {
                    num = num * 10 + (s[i+len]-'0');
                    len++;
                }
                
                res += sign * num;
                i += len;
            }
            else if (s[i] == '+') {
                sign = 1;
                i++;
            }
            else if (s[i] == '-') {
                sign = -1;
                i++;
            }
            else if (s[i] == '(') {
                st.push(res);
                st.push(sign);
                sign = 1;
                res = 0;
                i++;
            }
            else if (s[i] == ')') {
                sign = st.top(); st.pop();
                int prevRes = st.top(); st.pop();
                res = res * sign + prevRes;
                i++;
            }
            else i++;
        }
        
        return res;
    }
};