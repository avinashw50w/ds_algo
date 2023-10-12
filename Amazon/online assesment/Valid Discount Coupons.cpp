/*
A coupon is a string.
There are 3 rules for a valid string:

An empty string is valid
You can add same character to a valid string X, and create another valid string yXy
You can concatenate two valid strings X and Y, so XY will also be valid.
Ex: vv, xbbx, bbccdd, xyffyxdd are all valid.
*/

bool isValid(string coupon) {
	stack<char> st;

	for (char c: coupon) {
		if (st.empty() or c != st.top()) st.push(c);
		else if (c == st.top()) st.pop();
	}

	return st.empty();
}