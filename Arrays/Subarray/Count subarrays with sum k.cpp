/*Count the no of subarrays whose sum is K.
∑a[i..j] = K
=> ∑a[0..j] - ∑a[0..i-1] = K
=> ∑a[0..j] - K = ∑a[0..i-1]

keep calculating the prefix sums and
just count the previously occured prefix sums whose value matches with the
current prefix sums
- Another approach can be to first store the frequency of all the prefix sums in a map
and then for each prefix sums, count the no of ways to choose any two of them
, ie, add up nC2 values
*/

int solve(vector<int> a, int K) {
	int n = a.size();
	unordered_map<int, int> mp;
	int sum = 0, cnt = 0;

	for (int i = 0; i < n; ++i) {
		sum += a[i];
		cnt += sum == K;
		cnt += mp[sum - K];
		mp[sum]++;
	}

	return cnt;
}