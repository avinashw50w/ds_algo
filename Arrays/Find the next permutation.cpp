// find the next permutation, ie, find the next greated element
int search(string s, int l, int r, char x) {
    int mid, ans = -1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (s[mid] >= x) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return ans;
}

int nextPermutation(string s) {
    int n = s.size();
    // find the first no from right which is smaller than its right no
    int i = n - 2;
    while (i >= 0 and s[i] >= s[i + 1]) i--;

    if (i < 0) return -1;

    // search the smallest element on the right side of s[i] which is greater than s[i]
    // int idx = search(s, i+1, n-1, s[i]);
    int idx = i + 1;
    for (int j = i + 2; j < n; ++j)
        if (s[i] < s[j] and s[j] < s[idx]) idx = j;

    swap(s[i], s[idx]);
    sort(s + i + 1, s + n);
    return s;
}