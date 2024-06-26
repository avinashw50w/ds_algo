/*Given a list of integers nums and an integer k, return the length of the longest sublist where 
the absolute difference between the largest and smallest element of the sublist is ≤ k.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 3, 5, 9]
k = 4
Output
3*/
int solve(vector<int>& a, int k) {
    int n = a.size(), ans = 0;
    map<int, int> mp;
    for (int start = 0, end = 0; end < n; ++end) {
        mp[a[end]]++;
        while (start < end and (*mp.rbegin()).first - (*mp.begin()).first > k) {
            mp[a[start]]--;
            if (mp[a[start]] == 0) mp.erase(a[start]);
            start++;
        }

        ans = max(ans, end - start + 1);
    }
    return ans;
}