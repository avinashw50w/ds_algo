/*You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].



Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.


Constraints:

0 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4 */

class Solution {
    static const int maxn = 1e5 + 5;
    int bit[maxn];
public:
    void update(int i, int val) {
        for (; i < maxn; i += (i & -i)) bit[i] += val;
    }
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= (i & -i)) res += bit[i];
        return res;
    }
    vector<int> countSmaller(vector<int>& a) {
        int n = a.size();
        if (n == 0) return vector<int> {};
        int zeroes = 0;
        int b[n];
        for (int i = 0; i < n; ++i) b[i] = a[i];
        sort(b, b + n);
        for (int i = 0; i < n; ++i) {
            int d = lower_bound(b, b + n, a[i]) - b;
            a[i] = d + 1;
        }

        vector<int> res(n);
        res[n - 1] = 0;

        update(a[n - 1], 1);
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] != 0) {
                update(a[i], 1);
                res[i] = sum(a[i] - 1) + zeroes;
            }
            else zeroes++;
        }

        return res;
    }
};