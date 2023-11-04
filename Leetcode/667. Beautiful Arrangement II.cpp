/*Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement:
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

If there are multiple answers, print any of them.

Example 1:
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.

IDEA: 
for k = n-1 : 
    1, n, 2, n-1, 3, n-2,... 
=> diff = n-1, n-2, n-3,...
Another way to explain concept 2 (and the way the intuition came to me in my brain) was to achieve k unique differences ("unique difference" being absolute value between two subsequent element pairs) is to simply do this:

choose one from top
choose one from bottom
and then repeat steps (1,2) k times. and then fill in the rest of the array in asc or desc order (depending on if we choose from top or bottom on the last iteration.*/
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        for (int i = 0; i < n; ++i) res[i] = i + 1;
        if (n <= 1) return res;
        
        int l = 0, r = n+1;
        for (int i = 0; i < k; ++i) {
            if (i&1^1) res[i] = ++l;
            else res[i] = --r;
        }
        
        if (res[k-1] == l) {
            for (int i = k; i < n; ++i) {
                res[i] = ++l;
            }
        }
        else {
            for (int i = k; i < n; ++i) {
                res[i] = --r;
            }
        }
        
        return res;
    }
};