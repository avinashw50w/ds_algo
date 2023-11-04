/*A certain bug's home is on the x-axis at position x. Help them get there from position 0.

The bug jumps according to the following rules:

It can jump exactly a positions forward (to the right).
It can jump exactly b positions backward (to the left).
It cannot jump backward twice in a row.
It cannot jump to any forbidden positions.
The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers.

Given an array of integers forbidden, where forbidden[i] means that the bug cannot jump to the 
position forbidden[i], and integers a, b, and x, return the minimum number of jumps needed for 
the bug to reach its home. If there is no possible sequence of jumps that lands the bug on 
position x, return -1.*/
class Solution {
public:
    static const int maxn = 7001;
    const int INF = 1e9 + 7;
    int dp[maxn][2];
    unordered_set<int> st;
    
    int solve(int a, int b, int x, int pos, int backward) {
        if (pos == x) return 0;
        if (pos < 0 or st.count(pos) or pos > 6000) return INF;
        if (dp[pos][backward] != -1) return dp[pos][backward];
        
        int &res = dp[pos][backward];
        // go forward
        res = 1 + solve(a, b, x, pos + a, 0);
        // go backward only if the previous step was not backward
        if (!backward) res = min(res, 1 + solve(a, b, x, pos - b, 1));
        
        res = min(res, INF);
        return res;
    }    
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        memset(dp, -1, sizeof(dp));
        for (int e: forbidden) st.insert(e);
        int ans = solve(a, b, x, 0, 0);
        
        return ans == INF ? -1 : ans;
    }
};