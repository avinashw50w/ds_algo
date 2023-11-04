/*Given an array of integers and an integer k, you need to find the number of unique k-diff 
pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are 
both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.*/

class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> m;
        int cnt = 0;

        for (int e : a) m[e]++;

        // a - b = k => a + k = b
        if (k) {
            for (auto x : m)
                if (m.count(x.first + k)) cnt++;
        }
        else {
            for (auto x : m)
                if (x.second > 1) cnt++;
        }

        return cnt;
    }
};