/*Count all possible interleavings of two strings*/
/*C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.
eg. a = "AB" and b = "CD"
then all possible interleavings are 6:
    ABCD
    ACBD
    ACDB
    CABD
    CADB
    CDAB
*/

int solve(int n, int m) {
    if (n <= 0 or m <= 0) return 0;
    if ((n == 0 and m == 1) or (n == 1 and m == 0)) return 1;

    return solve(n - 1, m) + solve(n, m - 1);
}

int count(string a, string b) {
    int n = a.size(), m = b.size();

    return solve(n, m);
}

// print all interleavings of two strings
int n, m;
void solve(string a, string b, string res, int p, int q) {

    if (p == n and q == m) {
        cout << res << endl;
        return;
    }

    if (p != n) {
        res += a[p];
        solve(a, b, res, p + 1, q);
        res.pop_back();
    }

    if (q != m) {
        res += b[q];
        solve(a, b, res, p, q + 1);
        res.pop_back();
    }
}

void print(string a, string b) {
    n = a.size(), m = b.size();
    string res = "";
    solve(a, b, "", 0, 0);
}

////////////////////////////////////////////////////////////////////////
/*Find if a string is interleaved of two other strings | DP-33
Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B. C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.

We have discussed a simple solution of this problem here. The simple solution doesn’t work if strings A and B have some common characters. For example A = “XXY”, string B = “XXZ” and string C = “XXZXXXY”. To handle all cases, two possibilities need to be considered.

a) If first character of C matches with first character of A, we move one character ahead in A and C and recursively check.

b) If first character of C matches with first character of B, we move one character ahead in B and C and recursively check.

If any of the above two cases is true, we return true, else false. Following is simple recursive implementation of this approach*/
// check whether c is a interleaving of a and b
bool solve(char *A, char *B, char *C) {
    if (!(*A or * B or * C)) return true;

    if (*C == '\0') return false;

    return ( (*C == *A) and solve(A + 1, B, C + 1) ) or ( (*C == *B) and solve(A, B + 1, C + 1));
}
// using strings
bool interleaved(string a, string b, string c) {
    if (!a.size() and !b.size() and !c.size()) return true;
    if (!c.size()) return false;

    bool x = a.size() && c.size() && a[0] == c[0] && interleaved(a.substr(1), b, c.substr(1));
    bool y = b.size() && c.size() && b[0] == c[0] && interleaved(a, b.substr(1), c.substr(1));

    return x or y;
}

// DP recursive
unordered_map<string, bool> dp;
bool interleaved(string a, string b, string c) {
    if (!a.size() and !b.size() and !c.size()) return true;
    if (!c.size()) return false;

    string key = a + "|" + b + "|" + c;

    if (dp.count(key)) return dp[key];

    bool x = a.size() and a[0] == c[0] and interleaved(a.substr(1), b, c.substr(1));
    bool y = b.size() and b[0] == c[0] and interleaved(a, b.substr(1), c.substr(1));

    return dp[key] = x or y;
}

// DP solution
bool solve(string A, string B, string C) {
    int N = A.size(), M = B.size();

    if (C.size() != N + M) return false;

    bool dp[N + 1][M + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == 0 and j == 0) dp[i][j] = true;
            else if (i == 0 and B[j - 1] == C[j - 1]) dp[i][j] = dp[i][j - 1];
            else if (j == 0 and A[i - 1] == C[i - 1]) dp[i][j] = dp[i - 1][j];
            else if (A[i - 1] == C[i + j - 1] and B[j - 1] != C[i + j - 1]) dp[i][j] = dp[i - 1][j];
            else if (A[i - 1] != C[i + j - 1] and B[j - 1] == C[i + j - 1]) dp[i][j] = dp[i][j - 1];
            else if (A[i - 1] == C[i + 1j - 1] and B[j - 1] == C[i + j - 1]) dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }
}