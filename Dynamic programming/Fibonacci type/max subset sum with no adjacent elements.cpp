/*Given an array of integers, find the subset of non-adjacent elements with the maximum sum. 
Calculate the sum of that subset. It is possible that the maximum sum is 0, the case when all 
elements are negative.
constraints:
0 <= n <= 10^5
-10^4 <= a[i] <= 10^4 */

int maxSubsetSum(vector<int> a) {
    int n = a.size();
    vector<int> dp(n+1);
    int x = 0, y = a[0] > 0 ? a[0] : 0, z = max(x, y);
    
    for (int i = 1; i < n; ++i) {
        if (a[i] >= 0) z = max(y, a[i] + x);
        x = y;
        y = z;
    }    
    
    return z;
}