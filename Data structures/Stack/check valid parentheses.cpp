#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main() {

	string s = ")(()(()))((()))";

	int n = s.length();

	int i = 0; 

	while(i < n) {
		while(i < n and s[i] == '(') st.push(1), i++;

		if(st.empty()) break;
		
		while(s[i] == ')') {
			if(st.empty()) break;
			st.pop();
			i++;
		}
	}

	if(i == n and st.empty()) cout << "Valid parenthesis" << endl;
	else cout << "Invalid paranthesis" << endl;
}