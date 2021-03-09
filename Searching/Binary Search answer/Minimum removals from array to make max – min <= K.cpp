/*Minimum removals from array to make max – min <= K
Given N integers and K, find the minimum number of elements that should be removed such that Amax-Amin<=K. After the removal of elements, Amax and Amin is considered among the remaining elements.
Examples:

Input : a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20}
          k = 4
Output : 5
Explanation: Remove 1, 3, 4 from beginning
and 17, 20 from the end.

IDEA:
First sort the array, then for an element at index i, find the rightmost index j
such that a[j] - a[i] <= K, then ans = min(ans, n - (j - i + 1))
*/

int find(vector<int> a, int i, int K) {
    int l = i + 1, r = a.size() - 1, ans = -1;
    int mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (a[mid] - a[i] <= K) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

int solve(vector<int> a, int K) {
    int n = a.size();

    int ans = n;
    for (int i = 0; i < n; ++i) {
        int j = find(a, i, K);

        if (j != -1) {
            ans = min(ans, n - (j - i + 1));
        }
    }

    return ans;
}