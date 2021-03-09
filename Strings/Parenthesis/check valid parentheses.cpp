#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

bool solve(string s) {
	stack<char> st;
	for (char c : s) {
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
	for (char c : s) {
		if (c == '(') l++;
		else l--;
		if (l < 0) return false;
	}

	return l == 0;
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
/* case 1: when there are more no of ) than (, then we need * to counter the extra )
 and the * should appear before ), here we use the variable r. When ) appears increment r
 and when ( appears then decrement r, when * appears then increment r. So whenever r
 becomes -ve means there are not enough * before ) to counter it

case 2: when there are more no of ( than ), then we need * to counter the extra ( and the
* should appear after (. here we use l to check the status of (. Increment l if ( appears,
* decrement it when ) appears, decrement l if * appears. So it can be the case that the no
* of * are more than the no of ( and the value of l can go -ve. But since a * can be
* converted to "" string so update l to 0 if l goes -ve.
*/
bool solve(string s) {
	int l = 0, r = 0;
	for (char c : s) {
		if (c == '(') l++, r++;
		if (c == ')') l--, r--;
		if (c == '*') l--, r++;
		if (r < 0) return false;
		l = max(l, 0);
	}

	return r <= l and l == 0;
}
