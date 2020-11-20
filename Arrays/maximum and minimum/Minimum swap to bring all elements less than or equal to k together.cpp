/*Given an array of n positive integers and a number k. Find the minimum number of swaps
required to bring all the numbers less than or equal to k together.
IDEA:
- Find count of all elements which are less than or equals to ‘k’.
Let’s say the count is ‘cnt’
- Using two pointer technique for the window of length ‘cnt’, each time keep track of how many elements in this range are greater than ‘k’. Let’s say the total count is ‘bad’.
- Repeat step 2, for every window of length ‘cnt’ and take the minimum of count ‘bad’ among them. This will be the final answer.
*/

int solve(vector<int> a, int k) {
	int cnt = 0, n = a.size();
	for (int e : a) if (e <= k) cnt++;
	int bad = 0, ans = n;
	for (int i = 0; i < cnt; ++i) if (a[i] > k) bad++;
	ans = min(ans, bad);
	for (int i = cnt; i < n; ++i) {
		if (a[i - cnt] <= k and a[i] > k) bad++;
		else if (a[i - cnt] > k and a[i] <= k) bad--;
		ans = min(ans, bad);
	}
	return ans;
}