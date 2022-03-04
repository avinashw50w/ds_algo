/*Find the length of the longest subarray with even sum*/

int solve(vector<int> a) {
    int n = a.size(), ans = 0, sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    // if total sum is even
    if (sum & 1 ^ 1) return n;

    // if total sum is odd, then we need to remove 1 odd element to make it even
    // if current element is odd, then ans = max lenght of the left subarray or the right 
    // subarray around the elemet
    for (int i = 0; i < n; ++i) {
        if (a[i] & 1) {
            ans = max({ans, n - i - 1, i});
        }
    }

    return ans;
}