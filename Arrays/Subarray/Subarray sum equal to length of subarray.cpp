/*count the no of subarrays whose sum is equal to the length of the subarray
∑(Ai) = r-l+1 , l <= i <= r
∑(Ai) - (r-l+1) = 0
∑(Ai) - ∑(1) = 0
∑(Ai - 1) = 0, l <= i <= r
*/

int solve(vector<int> a) {
    int n = a.size();
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    for (int x : a) {
        sum += x - 1;
        ans += sum == 0;
        ans += mp[sum];
        mp[sum]++;
    }
    return ans;
}