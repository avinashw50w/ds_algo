/*   infix: (A+B)*(C-D)
eg : prefix: *+AB-CD
    postfix: AB+CD-*

Algo:
1. Read the Prefix expression in reverse order (from right to left)
2. If the symbol is an operand, then push it onto the Stack
3. If the symbol is an operator, then pop two operands from the Stack
4. Create a string by concatenating the two operands and the operator after them.
    string = operand1 + operand2 + operator
    And push the resultant string back to Stack
5. Repeat the above steps until end of Prefix expression.
 */

bool isOperator(char c) {
    return c == '+' or c == '-' or c == '/' or c == '*' or c == '^';
}

string solve(string prefix) {
    int n = prefix.length();
    stack<string> st;
    for (int i = n - 1; i >= 0; --i) {
        if (isOperator(prefix[i])) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push(op1 + op2 + string(1, prefix[i]));
        }
        else {
            st.push(string(1, prefix[i]));
        }
    }

    return st.top();
}