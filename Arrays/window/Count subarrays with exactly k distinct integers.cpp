/*Find the count of subarrays having exactly k distinct integers.
IDEA: let fun(k) = # of subarrays having atmost k distinct integers
then ans = fun(k) - fun(k-1)
*/

int atmostK(vector<int> a, int k) {
    int n = a.size();
    map<int, int> mp;
    int st = 0, end = 0, cnt = 0;
    while (end < n) {
        mp[a[end]]++;
        
        while (mp.size() > k) {
            mp[a[st]]--;
            if (mp[a[st]] == 0) mp.erase(a[st]);
            st++;
        }

        cnt += end - st + 1;
        end++;
    }

    return cnt;
}

int solve(vector<int> a, int k) {
    return atmostK(a, k) - atmostK(a, k-1);
}