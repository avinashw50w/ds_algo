/* Find the largest subarray with equal no of 0's and 1's
If we replace 0's with -1, then the problem reduces to finding the max size subarray with sum of elements = 0
If the subarray is from [i..j], then sum([i..j]) = 0
=> sum([0..j]) - sum([0..i-1]) = 0
=> sum([0..j]) = sum([0..i-1])

keep add the numbers and check if the calculated sum has appeared before or not. If appeared, then check at what index it appeared,
and if the distance between the curr and that index is > than the maxlen, then update maxlen
*/

void findSubarray(int a[], int n) {

	int maxLen = 0;

	unordered_map<int, int> mp;
	int sum = 0, startIdx = 0;

	for (int i = 0; i < n; ++i) {
		sum += a[i] == 0 ? -1 : 1;
		if (sum == 0) {
			maxLen = i + 1;
			startIdx = 0;
		}

		if (mp.count(sum) == 0)
			mp[sum] = i;
		else {
			if (i - mp[sum] > maxLen) {
				maxLen = i - mp[sum];
				startIdx = mp[sum] + 1;
			}
		}
	}

	if (maxLen == 0)
		printf("No such array\n");
	else
		printf("%d to %d", startIdx, startIdx + maxLen - 1);

	return maxLen;

}