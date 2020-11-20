/*Given an array of size n and a number k, find all elements that appear more than n/k times
Given an array of size n, find all elements in array that appear more than n/k times. For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be [2, 3]. Note that size of array is 8 (or n = 8), so we need to find all elements that appear more than 2 (or 8/4) times.*/

vector<int> solve(vector<int> a, int k) {
	int n = a.size();
	int x = n / k;
	vector<int> res;
	if (x < 1) return res;
	sort(a.begin(), a.end());
	int i = 0;
	while (i < n) {
		int len = 1;
		while (i + len < n and a[i + len] == a[i]) len++;
		if (len > x) res.push_back(a[i]);
		i += len;
	}

	return res;
}