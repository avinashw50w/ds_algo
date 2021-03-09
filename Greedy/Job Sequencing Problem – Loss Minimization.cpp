/*We are given N jobs numbered 1 to N. For each activity, let Ti denotes the number of days
 required to complete the job. For each day of delay before starting to work for job i,
 a loss of Li is incurred.
We are required to find a sequence to complete the jobs so that overall loss is minimized.
We can only work on one job at a time.

If multiple such solutions are possible, then we are required to give the lexicographically
 least permutation (i.e earliest in dictionary order).

Examples:

Input : L = {3, 1, 2, 4} and
        T = {4, 1000, 2, 5}
Output : 3, 4, 1, 2
Explanation: We should first complete
job 3, then jobs 4, 1, 2 respectively.

Let us consider two extreme cases and we shall deduce the general case solution from them.

- All jobs take same time to finish, i.e Ti = k for all i. Since all jobs take same time to
finish we should first select jobs which have large Loss (Li). We should select jobs which
have the highest losses and finish them as early as possible.
Thus this is a greedy algorithm. Sort the jobs in descending order based on Li only.
- All jobs have the same penalty. Since all jobs have the same penalty we will do those jobs
 first which will take less amount of time to finish. This will minimize the total delay, and
 hence also the total loss incurred.
- This is also a greedy algorithm. Sort the jobs in ascending order based on Ti. Or we can also
sort in descending order of 1/Ti.
- From the above cases, we can easily see that we should sort the jobs not on the basis of Li or
Ti alone. Instead, we should sort the jobs according to the ratio Li/Ti, in descending order.*/

struct Job {
	int id;
	int loss;
	int days;
};

void solve(vector<int> L, vector<int> T) {
	int n = L.size();

	vector<Job> jobs;
	for (int i = 0; i < n; ++i)
		jobs.push_back(Job(i + 1, L[i], T[i]));

	stable_sort(jobs.begin(), jobs.end(),
	[](auto & a, auto & b) { return a.loss * b.days > b.loss * a.days; });

	for (int i = 0; i < n; ++i) {
		cout << jobs[i].id << " ";
	}
}

