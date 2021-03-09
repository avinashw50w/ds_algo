/*Sum of minimum and maximum elements of all subarrays of size k
Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.

Examples:

Input : arr[] = {2, 5, -1, 7, -3, -1, -2}
        K = 4
Output : 18
Explanation : Subarrays of size 4 are :
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4
     Sum of all min & max = 6 + 4 + 4 + 4 = 18 */
// just find the maximum and minimum of all subarrays of size k

int solve(vector<int> a, int k) {
	// p stores the maximum and q minimum
	deque<int> p, q;

	for (int i = 0; i < k; ++i) {
		while (!p.empty() and a[p.back()] <= a[i]) p.pop_back();
		while (!q.empty() and a[q.back()] >= a[i]) q.pop_back();

		p.push_back(i);
		q.push_back(i);
	}

	int sum = 0;
	for (int i = k; i < n; ++i) {
		sum += a[p.front()] + a[q.front()];
		while (!p.empty() and i - p.front() >= k) p.pop_front();
		while (!q.empty() and i - q.front() >= k) q.pop_front();

		while (!p.empty() and a[p.back()] <= a[i]) p.pop_back();
		while (!q.empty() and a[q.back()] >= a[i]) q.pop_back();

		p.push_back(i);
		q.push_back(i);
	}

	sum += a[p.front()] + a[q.front()];

	return sum;
}