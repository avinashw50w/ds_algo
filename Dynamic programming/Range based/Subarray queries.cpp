/*Given an array A containing n elements and q queries. Each query is of the form li, ri.
For each query i find the sum of all the elements in that range [li,ri] inclusive*/
// IDEA: use prefix sums

void solve(vector<int> a, vector<vector<int>> queries) {
    int n = a.size(), q = queries.size();
    vector<int> pre(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        pre[i] = s;
    }
    for (auto e: queries) {
        int l = e[0], r = e[1];
        cout << pre[r] - pre[l-1] << "\n";
    }
}

// another problem of the same type, here u have to find the XOR of elements in the range [l,r]
// IDEA: XOR(A[l..r]) = XOR(A[0..r]) ^ XOR(A[0..l-1])
void solve(vector<int> a, vector<vector<int>> queries) {
    int n = a.size(), q = queries.size();
    vector<int> pre(n);
    int x = 0;
    for (int i = 0; i < n; ++i) {
        x ^= a[i];
        pre[i] = x;
    }
    for (auto e: queries) {
        int l = e[0], r = e[1];
        cout << pre[r] ^ pre[l-1] << "\n";
    }
}