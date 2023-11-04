/*Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array 
can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 109 + 7.*/
class Solution {
public:
    typedef long long ll;
    
    int kConcatenationMaxSum(vector<int>& a, int k) {
        const int mod = 1e9 + 7;
        long long n = a.size(), curr_sum = 0, ans = 0, prev_sum;
        /* perform kadane two times and store the maximum continguous sums ending at index 
        n-1(prev_sum) and 2n-1(curr_sum). If there is an increase in sum (curr_sum > prev_sum) 
        means that concatenating the array 2 times increases the sum. Therefore on concatenating 
        an array one time increase the sum by (curr_sum - prev_sum). Lets say, prev_sum is 5 and 
        curr_sum is 10, so the increase is 5, then after concatenating the remaining (k-2) 
        arrays the total sum would be (max sum of two arrays, ie, 10) + (k-2) * 5
        */
        for (int i = 0; i < min(k, 2); i++) {
            prev_sum = curr_sum;
            for (int e: a) {
                curr_sum = max((ll)e, curr_sum + (ll)e);
                ans = max(ans, curr_sum);
                curr_sum %= mod;
                ans %= mod;
            }
        }
        
        if (curr_sum > prev_sum and k > 1) {
            ans = (ans + (curr_sum - prev_sum) * (ll)(k - 2) % mod) % mod;
        }
        
        return ans;
    }
};