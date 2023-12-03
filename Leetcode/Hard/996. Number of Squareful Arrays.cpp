/*An array is squareful if the sum of every pair of adjacent elements is a perfect square.

Given an integer array nums, return the number of permutations of nums that are squareful.

Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].

Example 1:

Input: nums = [1,17,8]
Output: 2
Explanation: [1,8,17] and [17,8,1] are the valid permutations.
Example 2:

Input: nums = [2,2,2]
Output: 1
 
Constraints:

1 <= nums.length <= 12
0 <= nums[i] <= 109

idea: [a1, a2, a3, a4, a5]
let's say we are at index i, swap a[i] with a[j] (j > i) and check if (a[i] + a[i-1])
is a perfect square. If yes, then proceed further, otherwise swap with other element and check.
We should consider only distinct permutation to avoid double count

*/
class Solution {
    int ans, n;
    vector<int> a;
public:
    bool isPerfectSquare(int n) {
        int t = sqrt(n);
        return (t*t) == n;
    }
    void solve(int pos = 0) {
        if (pos >= n) {
            ans++;
            return;
        }
        for (int i = pos; i < n; ++i) {
            // avoid duplicates
            if (i > pos and a[i] == a[pos]) continue;
            if (i > pos and a[i] == a[i-1]) continue;
            // swap a[pos] with a[i] iff a[i] + a[pos-1] is perfect square
            if (pos == 0 or (pos > 0 and isPerfectSquare(a[i] + a[pos-1]))) {
                swap(a[i], a[pos]);
                solve(pos+1);
                swap(a[i], a[pos]);
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        a = nums;
        n = a.size();
        ans = 0;
        sort(a.begin(), a.end());
        solve();
        return ans;
    }
};

// another approach
class Solution {
public:
   unordered_map<int, int> count;
   unordered_map<int, unordered_set<int>> cand;
   int res = 0;
   int numSquarefulPerms(vector<int>& A) {
    for (int a : A) count[a]++;
        for (auto i : count) {
            for (auto j : count) {
                int x = i.first, y = j.first, s = sqrt(x + y);
                if (s * s == x + y)
                    cand[x].insert(y);
            }
        }
        for (auto e : count)
            dfs(e.first, A.size() - 1);
        return res;
    }

    void dfs(int x, int left) {
        count[x]--;
        if (!left) res++;
        for (int y : cand[x])
            if (count[y] > 0)
                dfs(y, left - 1);
            count[x]++;
        }
    };