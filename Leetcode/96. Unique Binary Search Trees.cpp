/*Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

   if i is chosen as the root then the nodes from 0..i-1 falls in the left subtree and the nodes
   from i+1...n falls in the right subtree. So the total no of uniqueBSTs(0..n) = ∑ uniqueBSTs(0..i-1) * uniqueBSTs(i+1..n) for all i
   */

class Solution {
public:
    int numTrees(int n) {
        
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        
        // i: no of nodes in the tree
        for (int i = 2; i <= n; ++i) {
            // j: pick j as the root;
            for (int j = 1; j <= i; ++j)
                dp[i] += dp[j-1] * dp[i-j];
        }
        
        return dp[n];
    }
};