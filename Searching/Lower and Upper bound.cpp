// lower_bound function
// first element >= target
int lower_bound(vector<int> A, int x) {
    if (A.empty() || A.back() < x) return A.size();
    int l = 0, r = A.size() - 1, mid, ans = 0;

    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (A[mid] >= x) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}

// upper_bound function
// first element > target
int upper_bound(vector<int> A, int x) {
    if (A.empty() || A.back() <= x) return A.size();
    int l = 0, r = A.size() - 1, mid, ans = 0;

    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (A[mid] > x) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}