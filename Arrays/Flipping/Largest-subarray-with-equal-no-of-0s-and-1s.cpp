/* Find the largest subarray with equal no of 0's and 1's
Algo:
1. replace all 0's with -1
2. problem reduces to finding the largest subarray with sum = 0
3.subarray sum from i to j can be written as
	 sum(i..j) = 0
	=> sum(0..j) - sum(0..i-1) = 0
4. store the index of all the prefix sums,
	and if the current prefix sum has already appeared then update
	the max length of the subarray so far
*/

pair<int, int> findSubarray(vector<int> a) {
	int n = a.size(), maxlen = -1, start = 0;
	int sum = 0;

	unordered_map<int, int> mp;

	for (int i = 0; i < n; ++i) {
		sum += a[i] == 0 ? -1 : 1;

		if (mp.count(sum) and i - mp[sum] > maxlen) {
			maxlen = i - mp[sum];
			start = mp[sum] + 1;
		}
		else
			mp[sum] = i;
	}

	return { start, start + maxlen };
}
