/*Print all combinations of balanced parentheses
Write a function to generate all possible n pairs of balanced parentheses.
Examples:

Input : n=1
Output: {}

Input : n=2
Output: 
{}{}
{{}}*/

void solve(string s, int N, int open, int close, vector<string> &res) {

	if (open == N and close == N)  {
		res.push_back(s);
		return;
	}

	if (open < N) 
		solve(s + "{", N, open+1, close, res);

	if (open > close) 
		solve(s + "}", N, open, close+1, res);
}

vector<string> print(int N) {

	string s = "";
	vector<string> res;

	solve(s, N, 0, 0, res);
	return res;
}

int main()
{
	vector<string> res = print(3);
	for (string s: res) cout << s << endl;
}