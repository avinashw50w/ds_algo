/*Minimum number of Parentheses to be added to make it valid
Given a string S of parentheses ‘(‘ or ‘)’ where, 0\leq len(S)\leq 1000. 
The task is to find minimum number of parentheses ‘(‘ or ‘)’ (at any positions) 
we must add to make the resulting parentheses string is valid.

Examples:

Input: str = "())"
Output: 1
One '(' is required at beginning.

Input: str = "((("
Output: 3
Three ')' is required at end.*/

int solve(string s) {
	int n = s.size();

	int bal = 0, add = 0;

	for (int i = 0; i < n; ++i) {

		bal += s[i] == '(' ? 1 : -1;

		if (bal == -1) bal++, add++;
	}

	return bal + add;
}