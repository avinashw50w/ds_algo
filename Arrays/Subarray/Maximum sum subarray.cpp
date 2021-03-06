/*ind the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.*/

int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();

    int prefix = 0;
    int mx = INT_MIN;

    for (int i = 0; i < n; ++i) {
        prefix = max(A[i], prefix + A[i]);
        mx = max(mx, prefix);
    }

    return mx;
}
