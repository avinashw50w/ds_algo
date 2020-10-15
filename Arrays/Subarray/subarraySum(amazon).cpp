/*Given an array (length n), we need to find the subarray (length k) such that the sum of the first j elements of the subarray
equals the sum of the remaining (k-j) elements of the subarray.
For e.g.
Array: 2,2,13,4,7,3,8,12,9,1,5
Output: 4,7,3,8,12,9,1 [4+7+3+8=12+9+1]
Could this be done with a complexity better than O(n^3) */

/* keep an index i fixed and expand on both sides calculating the left and right sum respectively and check whether the left
and right sum are the same, if same then update the maxlen*/

vector<int> solve(vector<int> a, int K) {
    int n = a.size();
    vector<int> res;
    if (K > n) return res;
    int sum = 0, st;
    for (int i = 0; i < K; ++i) sum += a[i];

    for (int i = 0; i <= n - K; ++i) {
        int l = 0, r = sum;
        for (int j = 0; j < K; ++j) {
            l += a[i + j];
            r -= a[i + j];
            if (l == r) {
                st = i;
            }
        }

        sum -= a[i];
        sum += a[i + K];
    }

    for (int i = 0; i < K; ++i) res.push_back(a[i + st]);

    return res;
}

