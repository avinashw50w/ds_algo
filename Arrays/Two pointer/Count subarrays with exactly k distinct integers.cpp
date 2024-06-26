/*Find the count of subarrays having exactly k distinct integers.
IDEA: let fun(k) = # of subarrays having atmost k distinct integers
then ans = fun(k) - fun(k-1)
*/

int atmostK(vector<int> a, int k) {
    int n = a.size();
    map<int, int> mp;
    cnt = 0;
    for (int st = 0, end = 0; end < n; ++end) {
        mp[a[end]]++;
        
        while (mp.size() > k) {
            mp[a[st]]--;
            if (mp[a[st]] == 0) mp.erase(a[st]);
            st++;
        }

        cnt += end - st + 1;
    }

    return cnt;
}

int solve(vector<int> a, int k) {
    return atmostK(a, k) - atmostK(a, k-1);
}

/* NOTE: the reason why we didn't count the subarrays on the condition when mp.size() == k
we could have used 
if (mp.size() == k) cnt++;
BUT, it will give wrong ans. For eg.

arr = [1 1 1 2 3 4 6], k = 3
mp.size() becomes 3 when we reach 3(index 4), and the cnt is incemented only once, whereas the 
cnt should be 3 because there are 3 1's in the begining.
*/