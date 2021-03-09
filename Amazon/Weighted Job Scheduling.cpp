/*Weighted Job Scheduling in O(n Log n) time
Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
The algorithm is:

Sort the jobs by non-decreasing finish times.
For each i from 1 to n, determine the maximum value of the schedule from the subsequence of jobs[0..i]. Do this by comparing the inclusion of job[i] to the schedule to the exclusion of job[i] to the schedule, and then taking the max.
To find the profit with inclusion of job[i]. we need to find the latest job that doesn’t conflict with job[i]. The idea is to use Binary Search to find the latest non-conflicting job.*/

struct Job {
	int start, end, profit;
};

int search(vector<Job> a, int pos) {
	int l = 0, r = pos, ans = -1, mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (a[mid].end <= a[pos].start) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return -1;
}

int solve(vector<Job> jobs) {
	int n = jobs.size();
	// dp[i] - stores the maximum profit till index i
	// at each step, we can either include the job or exclude it
	// dp[i] = max(dp[i-1], profit if ith job is included)
	vector<int> dp(n);
	sort(jobs.begin(), jobs.end(), [](const Job & a, const Job & b) { return a.end < b.end; });
	dp[0] = job[0].profit;

	for (int i = 1; i < n; ++i) {
		int t = jobs[i].profit;
		// find the latest job that doesn't conflict with jobs[i]
		int pos = search(jobs, i - 1);
		if (pos != -1) t += dp[pos];
		dp[i] = max(t, dp[i - 1]);
	}

	return dp[n - 1];
}
/////////////////////////////////////////
// to also find the jobs, store both value and the list of jobs in dp

struct WeightedJob {
	int value;
	vector<Job> jobs;
};

int solve(vector<Job> jobs) {
	int n = jobs.size();
	// dp[i] - stores the maximum profit till index i including Job[i]
	// dp[i] = max(dp[i-1] + profit if ith job is included)
	vector<WeightedJob> dp(n);
	sort(jobs.begin(), jobs.end(), [](const Job & a, const Job & b) { return a.end < b.end; });
	dp[0].value = job[0].profit;
	dp[0].jobs.push_back(job[0]);

	for (int i = 1; i < n; ++i) {
		int t = jobs[i].profit;
		// find the latest job that doesn't conflict with jobs[i]
		int pos = search(jobs, i - 1);

		if (pos != -1) t += dp[pos].value;

		if (t > dp[i - 1].value) {
			dp[i].value = t;
			dp[i].jobs = dp[l].jobs;
			dp[i].jobs.push_back(jobs[i]);
		}
		else {
			dp[i] = dp[i - 1];
		}
	}

	for (Job j : dp[n - 1].jobs) {
		cout << j.start << " " << j.end << endl;
	}

	return dp[n - 1];
}