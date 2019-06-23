/* eg. [{}(()){{{}}}[]]*/


bool check(string s) {

	stack<char> st;
	char c;

	for (int i = 0; i < s.size(); ++i) {
		c = s[i];

		if (c == '[' or c == '{' or c == '(') {
			st.push(c);
			continue;
		}

		if (st.empty()) return false;

		char x = st.top();

		switch (c) {
			case ']':
				if (x == '{' or x == '(') return false;
				st.pop();
				break;

			case '}':
				if (x == '[' or x == '(') return false;
				st.pop();
				break;

			case ')':
				if (x == '[' or x == '{') return false;
				st.pop();
				break;
		}
	}

	return st.empty();
}