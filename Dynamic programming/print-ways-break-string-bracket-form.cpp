/*Print all ways to break a string in bracket form
Given a string, find all ways to to break the given string in bracket form. Enclose each substring within a parenthesis.

Examples:

Input : abc
Output: (a)(b)(c)
        (a)(bc)
        (ab)(c)
        (abc)


Input : abcd
Output : (a)(b)(c)(d)
         (a)(b)(cd)
         (a)(bc)(d)
         (a)(bcd)
         (ab)(c)(d)
         (ab)(cd)
         (abc)(d)
         (abcd)  */

string s;	// string
int N;	// length of the string

void solve(int idx, string out) {

	if(idx == N) {
		cout << out << endl;
		return;
	}

	for(int i = idx; i < N; ++i) {

		solve(i+1, out + "(" + s.substr(idx, i-idx+1) + ")");
	}
}


int main() {
	s = "avinash";
	N = s.length();

	solve(0, "");
}