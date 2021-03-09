/* eg. [{}(()){{{}}}[]]*/


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