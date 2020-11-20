/*
prefix: *+AB-CD
Infix : (A+B) * (C-D)

Algo:
1. Read the Prefix expression in reverse order (from right to left)
2. If the symbol is an operand, then push it onto the Stack
3. If the symbol is an operator, then pop two operands from the Stack
4. Create a string by concatenating the two operands and the operator between them.
	string = (operand1 + operator + operand2)
	And push the resultant string back to Stack
5. Repeat the above steps until end of Prefix expression.

NOTE: for postfix iterate from left to right
 */

string solve(string prefix) {
	int n = prefix.length();
	stack<string> st;

	for (int i = n - 1; i >= 0; --i) {
		if (isOperator(prefix[i])) {
			string op1 = st.top(); st.pop();
			string op2 = st.top(); st.pop();
			string s = "(" + op1 + prefix[i] + op2 + ")";
			st.push(s);
		}
		else {
			st.push(string(1, prefix[i]));
		}
	}

	return st.top();
}

/////////////////////////////////
// FOLLOW UP: use minimum no of '('
struct Node {
	string exp;
	char opr;
	Node(string exp, char opr) : exp(exp), opr(opr) {}
};

bool isOperator(char c) {
	return c == '+' or c == '-' or c == '/' or c == '*' or c == '^';
}
int prec(char c) {
	switch (c) {
	case '+': case '-': return 0; break;
	case '*': case '/': return 1; break;
	case '^': return 2; break;
	}
	return -1;
}
string solve(string prefix) {
	int n = prefix.length();
	stack<Node> st;

	for (int i = n - 1; i >= 0; --i) {
		if (isOperator(prefix[i])) {
			Node op1 = st.top(); st.pop();
			Node op2 = st.top(); st.pop();
			string s = "";

			if (op1.opr != '#' and prec(op1.opr) < prec(prefix[i]))
				op1.exp = "(" + op1.exp + ")";

			if (op2.opr != '#' and prec(op2.opr) < prec(prefix[i]))
				op2.exp = "(" + op2.exp + ")";

			s = op1.exp + prefix[i] + op2.exp;
			st.push(Node(s, prefix[i]));
		}
		else {
			st.push(Node(string(1, prefix[i]), '#'));
		}
	}

	return st.top().exp;
}

int main() {

	cout << solve("*-A/BC-/AKL") << endl;

	return 0;
}