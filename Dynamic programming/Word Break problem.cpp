/*Given a list of words in a dictionary and a string s.
FInd whether the string can be partitioned into words such that
each word exists in the dictionary*/

// Recursive, Time complexity: O(2^n)
int solve(string s, set<string> dict) {
	int n = s.size();

	if (n == 0) return true;

	for (int i = 0; i < n; ++i) {
		string left = s.substr(0, i + 1);
		string right = s.substr(i + 1, n - i);
		if (dict.count(left) and solve(right, dict)) return true;
	}

	return false;
}

// using trie
// Time complexity: O(2^n)
Trie t;
int go(string s) {
	int n = s.length();
	if (n == 0) return true;
	for (int i = 0; i < n; ++i) {
		if (t.search(s.substr(0, i + 1)) and go(s.substr(i + 1))) return true;
	}

	return false;
}

int solve(string s, set<string> dict) {
	int n = s.size();
	for (string str : dict) t.insert(str);

	return go(s);
}

// DP, Time complexity: O(n^2)
// Dp[i] denotes whether it is possible for substring s[0..i]
int solve(string s, set<string> dict) {
	int N = s.size();
	if (N == 0) return false;
	vector<bool> dp(N, false);

	for (int i = 0; i < N; ++i) {
		if (dict.count(s.substr(0, i + 1))) dp[i] = true;

		if (dp[i]) {
			if (i == N - 1) return true;

			for (j = i + 1; j < N; ++j) {
				if (dict.count(s.substr(i + 1, j - i))) dp[j] = true;
			}

			if (dp[N - 1] == true) return true;
		}
	}

	return false;
}

// to print all possible partitions
set<string> dict

void solve(string s, vector<string> buff, vector<vector<string>> &res) {

	int n = s.size();

	for (int i = 0; i < n; ++i) {
		string left = s.substr(0, i + 1);
		string right = s.substr(i + 1, n - i);

		if (dict.count(left)) {
			buff.push_back(left);

			if (right.size() == 0) {
				res.push_back(buff);
			}
			else {
				solve(right, buff, res);
			}
			buff.pop_back();
		}
	}
}

int main() {
	dict.insert("on");
	dict.insert("pin");
	dict.insert("pins");
	dict.insert("sand");
	dict.insert("and");
	dict.insert("needles");

	string s = "onpinsandneedles";
	vector<string> buff;
	vector<vector<string>> res;
	solve(s, buff, res);

	for (auto i : res) {
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
}

////////////////////////////////////////////////////
// return the min no of such partitions
// recursive, O(2^n)
int solve(string s) {
	int n = s.size();

	if (n == 0) return 0;

	int res = INT_MAX;

	for (int i = 0; i < n; ++i) {
		string left = s.substr(0, i + 1);
		string right = s.substr(i + 1, n - i);

		if (dict.count(left)) {

			if (right.size() == 0) return 0;

			int t = solve(right);

			if (t != INT_MAX) res = min(res, 1 + t);
		}
	}

	return res;
}

// DP solution, O(n^2)
// let dp[i] be the min count of partitions required for subtring s[0..i]

int solve(string s) {
	int n = s.size();

	int dp[n];
	fill(dp,  dp + n, INT_MAX);

	for (int i = 0; i < n; ++i) {
		string left = s.substr(0, i + 1);
		if (dict.count(left)) dp[i] = 0;
		else {
			for (int j = 0; j < i; ++j) {
				string right = s.substr(j + 1, i - j);
				if (dict.count(right) and dp[j] != INT_MAX)
					dp[i] = min(dp[i], 1 + dp[j]);
			}
		}
	}

	return dp[n - 1];
}