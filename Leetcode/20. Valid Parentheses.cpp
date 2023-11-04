/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true*/

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (char c : s) {
			if (c == '(') st.push(')');
			else if (c == '{') st.push('}');
			else if (c == '[') st.push(']');
			else {
				if (st.empty() or (c != st.top())) return false;
				st.pop();
			}
		}

		return st.empty();
	}
};