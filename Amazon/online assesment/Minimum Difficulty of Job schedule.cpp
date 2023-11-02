/* https://cybergeeksquad.co/2023/03/minimum-difficulty-of-a-job-schedule-solution-amazon-oa.html
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the i-th job, you have to 
finish all the jobs j where 0 <= j < i).
You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of 
each day of the d days. The difficulty of a day is the maximum difficulty of a job done in that day.
Given an array of integers jobDifficulty and an integer d. The difficulty of the i-th job is jobDifficulty[i].
Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1

input:  jobDifficulty = [6,5,4,3,2,1], d = 2
output: 7
explanation:  First day you can finish the first 5 jobs, total difficulty = 6. Second day you can finish the last job, total difficulty = 1. 
The difficulty of the schedule = 6 + 1 = 7

let dp[i][d] = min difficulty for first i jobs done in d days.
We need to find the difficulty of the first i jobs done in d days.
In d days atleast first d jobs should be done to proceed.
If we know the difficulties of first k jobs done in d-1 days, where k can lie btw [d-1, i-1]
then dp[i][d] = min(dp[i][d], mx + dp[k][d-1]), where mx is the maximum job difficulty from i-1 to k
*/

int solve(vector<int> jobs, int days) {
	int n = jobs.size();
	if (n < days) return -1;
	vector<vector<int>> dp(n + 1, vector<int>(days+1, INT_MAX));

	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int d = 1; d <= days; ++d) {
			int mx = 0;
			for (int k = i-1; k >= d-1; --k) {
				mx = max(mx, jobs[k]);
				if (dp[k][d-1] != INT_MAX) {
					dp[i][d] = min(dp[i][d], mx + dp[k][d-1]);
				}
			}
		}
	}

	return dp[n][days] == INT_MAX ? -1 : dp[n][days];
}

