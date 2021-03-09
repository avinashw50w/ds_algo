/* A top down approach */
void LCS(string X, string Y, int i, int j) {
	if (i == 0 || j == 0) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	if (X[i - 1] == Y[j - 1])
		return dp[i][j] = 1 + LCS(i - 1, j - 1);
	else
		return dp[i][j] = max(LCS(i - 1, j) , LCS(i, j - 1));
}
//////////////////////////////////
// bottom up
void LCS(string X, string Y) {
	int m = X.size();
	int n = Y.size();
	int dp[m + 1][n + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[i - 1] == Y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;

			else
				dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
		}
	}
	cout << "The length of the longest common subsequence is : " << T[m][n] << "\n";
}

//////////////////////////////////
// print the lcs
string printLCS(string X, string Y) {
	LCS(X, Y); // fill the dp table
	int i = X.size() + 1;
	int j = Y.size() + 1;
	string res = "";

	while (i > 0 and j > 0) {
		if (X[i - 1] == Y[j - 1]) {
			res += X[i - 1];
			--i; --j;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
			--i;
		else
			--j;
	}

	reverse(res.begin(), res.end());
	return res;
}
////////////////////////////////////
// print all possible lcs
set<string> getAllLCS(string X, string Y) {
	LCS(X, Y); // fill the dp table

	vector<string> v = LCS(X, Y, X.size(), Y.size());

	set<string> lcs(v.begin(), v.end());

	return lcs;
}

vector<string> LCS(string X, string Y, int i, int j) {
	if (i == 0 or j == 0) return vector<string> v(1);

	// if last character of X and Y matches
	if (X[i - 1] == Y[j - 1]) {
		// ignore last characters of X and Y and find all LCS of substring
		// X[0..m-2], Y[0..n-2] and store it in a vector
		vector<string> lcs = LCS(X, Y, i - 1, j - 1);

		// append current character X[m - 1] or Y[n - 1] to all LCS of
		// substring X[0..m-2] and Y[0..n-2]
		for (string &str : lcs) {
			str.push_back(X[i - 1]);
		}

		return lcs;
	}

	if (dp[i - 1][j] > dp[i][j - 1])
		return LCS(X, Y, i - 1, j);

	if (dp[i - 1][j] < dp[i][j - 1])
		return LCS(X, Y, i, j - 1);

	// if top cell has equal value to the left cell, then consider
	// both characters
	vector<string> top = LCS(X, Y, i - 1, j);
	vector<string> left = LCS(X, Y, i, j - 1);

	// merge two vectors and return
	top.insert(top.end(), left.begin(), left.end());
	// copy(left.begin(), left.end(), back_inserter(top));

	return top;
}
////////////////////////////////////
int main() {
	string X = "abcdaf";
	string Y = "acbcf";

	LCS(X, Y);
	return 0;
}


