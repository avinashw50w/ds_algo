/*Given an array consisting of n integers, find the contiguous subarray of given length k
that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75


Note:

1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].*/

double findMaxAverage(vector<int>& a, int k) {
    int mx = INT_MIN, sum = 0;
    for (int i = 0; i < k; ++i) sum += a[i];
    mx = max(mx, sum);

    for (int i = k; i < a.size(); ++i) {
        sum += a[i] - a[i - k];
        mx = max(mx, sum);
    }

    return (double) mx / k;
}