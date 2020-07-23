#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

bool solve(string s) {
	stack<char> st;
	for (char c: s) {
		if (c == '(') st.push(c);
		else {
			if (st.empty()) return false;
			st.pop();
		}
	}

	return st.empty();
}

int main() {

	string s = ")(()(()))((()))";

	puts(solve(s) ? "YES\n" : "NO\n");
}

/////////////////////////////////////
// without stack

bool solve(string s) {
	int l = 0, r = 0;
	for (char c: s) {
		if (c == '(') l++;
		else l--;
		if (l < 0) return false;
	}

	return l==0;
}
int main() {
	// your code goes here
	string s = "(())()";
	puts(solve(s) ? "YES\n" : "NO\n");
	return 0;
}

/////////////////////////////////////
// follow up: string also contains a "*". The * can be converted to a '(' or  a ')'
// or just empty string ''.  Now check whether the string s
// can be converted to a valid parenthesis sequence.

bool solve(string s) {
	int l = 0, r = 0;
	for (char c: s) {
		if (c == '(') l++, r++;
		if (c == ')') l--, r--;
		if (c == '*') l--, r++;
		if (r < 0) return false;
		l = max(l, 0);
	}

	return r <= l and l == 0;
}
