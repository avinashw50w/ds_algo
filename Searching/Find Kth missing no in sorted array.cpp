/*Given an array a of unique numbers. Find the Kth missing number starting from the leftmost part of the array.
Example 1:

Input: A = [4,7,9,10], K = 1
Output: 5
Explanation: 
The first missing number is 5.
Example 2:

Input: A = [4,7,9,10], K = 3
Output: 8
Explanation: 
The missing numbers are [5,6,8,...], hence the third missing number is 8.
Example 3:

Input: A = [1,2,4], K = 3
Output: 6
Explanation: 
The missing numbers are [3,5,6,7,...], hence the third missing number is 6.

1 <= A[i] <= 1e7
1 <= K <= 1e8
*/

// O(n) sol
int solve(vector<int> a, int k) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        int gap = a[i] - a[i-1] - 1;
        if (gap < k) k -= gap;
        else return a[i-1] + k;
    }
    return a[n-1] + k;
}

// O(logN) sol
// IDEA: find the smallest index i such that the # of missing elements upto index i is >= k,
// then the ans will be a[i-1] + (k - missing numbers upto i)
// the # of missing nos upto i = (a[i] - a[0] - 1) - (i - 1) = a[i] - a[0] - i

int solve(vector<int> a, int k) {
    int n = a.size();
    int l = 0, r = n-1, ans = 0;
    auto getMissingCount = [&](int i) { return a[i] - a[0] - i; };

    int totalMissing = getMissingCount(n-1);
    if (k >= totalMissing) {
        return a[n-1] + k - totalMissing;
    }
    while (l < r) {
        int mid = l + (r-l)/2;
        if (getMissingCount(mid) < k)
            l = mid + 1;
        else
            r = mid;
    }

    // now l == r
    return a[r-1] + (k - getMissingCount(r-1));
}