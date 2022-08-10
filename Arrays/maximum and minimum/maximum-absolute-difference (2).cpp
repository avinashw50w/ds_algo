/* You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.


a[i] - a[j] + i - j => (a[i] + i) - (a[j] + j)
a[i] - a[j] - i + j => (a[i] - i) - (a[j] - j)
-a[i] + a[j] + i - j => -(a[i] - i) + (a[j] - j)
-a[i] + a[j] - i + j => -(a[i] + i) + (a[j] + j)

*/

// further improvement, no need to sort
int Solution::maxArr(vector<int> &A) {
    int n = A.size();

    int maxL, minL, maxR, minR;
    minL = minR = INT_MAX;
    maxL = maxR = INT_MIN;

    for (int i = 0; i < n; ++i) {
        minL = min(minL, A[i] + i);
        maxL = max(maxL, A[i] + i);
        minR = min(minR, A[i] - i);
        maxR = max(maxR, A[i] - i);
    }

    int ans = 0;

    return max((maxL - minL), (maxR - minR));
}

int Solution::maxArr(vector<int> &A) {
    int n = A.size();
    
    int l[n], r[n];
    
    for (int i = 0; i < n; ++i) {
        l[i] = A[i] + i;
        r[i] = A[i] - i;
    }
    
    sort(l, l +n);
    sort(r, r+n);
    
    int ans = INT_MIN;
    ans = max(l[n-1] - l[0], r[n-1] - r[0]);
    
    return ans;
}
