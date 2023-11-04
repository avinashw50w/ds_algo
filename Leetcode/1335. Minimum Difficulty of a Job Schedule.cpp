/*You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the i-th 
job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of 
difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a 
job done in that day.

Given an array of integers jobDifficulty and an integer d. The difficulty of the i-th job is 
jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs 
return -1.*/
class Solution {
    typedef long long ll;
    const int INF = 1e9 + 7;
public:
    int minDifficulty(vector<int>& jobs, int d) {
        int n = jobs.size();
        if (d > n) return -1;
        
        ll dp[d][n];
        memset(dp, INF, sizeof(dp));
        ll mx = -INF;
        
        for (int i = 0; i < n; ++i) {
            mx = max(mx, (ll)jobs[i]);
            dp[0][i] = mx;
        }
        
        for (int p = 1; p < d; ++p) {
            for (int i = p; i < n; ++i) {
                ll mx = -INF;
                for (int j = i; j < n; ++j) {
                    mx = max(mx, (ll)jobs[j]);
                    dp[p][j] = min(dp[p][j], mx + dp[p-1][i-1]);
                }
            }
        }
        
        ll ans = dp[d-1][n-1];
        return ans == INF ? -1 : ans;
    }
};