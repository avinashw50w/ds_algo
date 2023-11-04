/*Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].*/
class Solution {
public:
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
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atmostK(A, K) - atmostK(A, K-1);
    }
};