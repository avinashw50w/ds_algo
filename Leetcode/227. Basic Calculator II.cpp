/*Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5

We store operators and operands with two stacks.

If current operator is greater than the one on top of the operator stack, we push it in, otherwise we pop out operators and operands and calculate values, until the operator stack is empty or the top operator is less than current operator.

Implementation
There is one interesting thing about /. Initially, I just return a / b, but it fails for test case like -1/2 or 3/-14. I have to make it (int)floor(1.0 * a / b) to pass all the tests.

Time Complexity
O(n), scan the string from left to right

Space Complexity
O(n), just two stacks for operators and operands*/

int prec(char c) {
    switch (c) {
        case '-':
        case '+': 
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
    }
    return -1;
}

int eval(stack<int> &st, stack<char> &op) {
    int b = st.top(); st.pop();
    int a = st.top(); st.pop();
    char c = op.top(); op.pop();

    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return (int) floor(1.0 * a/b);

    return 0;
}

int solve(string s) {
    int n = s.length();
    stack<int> st;
    stack<char> op;
    for (int i = 0, j = 0; j < n; ) {
        if (s[j] == '-') j++;
        while (j < n and isdigit(s[j])) j++;
        int num = stoi(s.substr(i, j-i));
        st.push(num);

        if (j == n) {
            while (op.size()) st.push(eval(st, op));
            break;
        }
        else {
            if (op.empty() or prec(s[j]) > prec(op.top())) {
                op.push(s[j]);
            }
            else {
                while (op.size() and prec(s[j]) <= prec(op.top())) {
                    st.push(eval(st, op));
                }
                op.push(s[j]);
            }
        }

        j++;
        i = j;
    }

    return st.top();
}