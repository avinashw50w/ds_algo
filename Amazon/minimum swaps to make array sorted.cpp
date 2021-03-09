// GIven an array of size n containing numbers from 1 to n. Find minimum swaps required to make array sorted

int solve(vector<int> a) {
    int n = a.size();
    int index[n+1] = {};
    for (int i = 0; i < n; ++i) index[a[i]] = i;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != i+1) swap(a[i], a[index[i+1]]), cnt++;
    } 

    return cnt;
}