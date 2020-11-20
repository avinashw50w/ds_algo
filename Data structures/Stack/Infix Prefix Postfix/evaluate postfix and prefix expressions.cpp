/*1) Create a stack to store operands (or values).
2) Scan the given expression and do following for every scanned element.
…..a) If the element is a number, push it into the stack
…..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
3) When the expression is ended, the number in the stack is the final answer

*/

int solve(string postfix) {
	int res = 0;
	stack<int> st;

	for (int i = 0; postfix[i]; ++i) {
		if (isdigit(postfix[i])) st.push(postfix[i] - '0');
		else {
			int a = st.top(); st.pop();
			int b = st.top(); st.pop();
			switch (postfix[i]) {
			case '+':  st.push(a + b); break;
			case '-':  st.push(a - b); break;
			case '*':  st.push(a * b); break;
			case '/':  st.push(a / b); break;
			}
		}
	}

	return st.top();
}