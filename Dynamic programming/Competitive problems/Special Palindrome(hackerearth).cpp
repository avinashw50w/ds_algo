/*Given a String S and a character C, find the length of the longest palindromic subsequence of S containing the character C.

Input

The First Line contains an integer T denoting the number of testcases.
Each testcase is of 2 lines.
The First line contains one character C
The Second line contains the string S
Output

For every testcase print the maximum length on a new line.

Constraints

1 <= T <= 10
1 <= |S| <= 1000
Both C and S are made up of small English alphabets.
SAMPLE INPUT
2
a
dcbabcd
b
bbbb
SAMPLE OUTPUT
7
4
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 2;
string s;
char c;
vector<int> pos;
int n;
int in[maxn][maxn], out[maxn][maxn];

int get_in(int l, int r) {
    if (l > r) return 0;
    if (in[l][r] != -1) return in[l][r];
    if (l == r) return in[l][r] = 1;
    if (s[l] == s[r]) return in[l][r] = 2 + get_in(l + 1, r - 1);
    else return in[l][r] = max(get_in(l + 1, r), get_in(l, r - 1));
}

int get_out(int l, int r) {
    if (l < 0 or r >= n) return 0;
    if (out[l][r] != -1) return out[l][r];
    if (s[l] == s[r]) return out[l][r] = 2 + get_out(l - 1, r + 1);
    return out[l][r] = max(get_out(l - 1, r), get_out(l, r + 1));
}

void driveout(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    get_out(mid, mid + 1);
    get_out(mid - 1, mid);
    driveout(l, mid);
    driveout(mid + 1, r);
}

void solve() {
    cin >> c;
    cin >> s;
    n = s.size();
    pos.clear();

    memset(in, -1, sizeof(in));
    memset(out, -1, sizeof(out));

    for (int i = 0; i < n; ++i) {
        if (s[i] == c) pos.push_back(i);
    }

    if (pos.empty()) {
        cout << 0 << "\n";
        return;
    }

    driveout(0, n - 1);
    get_in(0, n - 1);

    int ans = 1;

    for (int i = 0; i < pos.size(); ++i) {
        for (int j = i + 1; j < pos.size(); ++j) {
            // get the no of palindromic subsequence within the range [i+1, j-1]
            int inside = (pos[i] + 1 != pos[j]) ? in[pos[i] + 1][pos[j] - 1] : 0;
            // get the no fo palindromic subsequence outside the range [i, j] including i and j
            int outside = (pos[i] - 1 >= 0 and pos[j] + 1 < n)
                          ? 2 + out[pos[i] - 1][pos[j] + 1] : 2;
            ans = max(ans, inside + outside);
        }
        // get the no fo palindromic subsequence outside of index i including i itself
        int outside = (pos[i] - 1 >= 0 && pos[i] + 1 < n)
                      ? 1 + out[pos[i] - 1][pos[i] + 1] : 1;
        ans = max(ans, outside);
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}