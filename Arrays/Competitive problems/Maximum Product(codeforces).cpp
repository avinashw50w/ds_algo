/*You are given an array of integers 𝑎1,𝑎2,…,𝑎𝑛. Find the maximum possible value of 𝑎𝑖.𝑎𝑗.𝑎𝑘.𝑎𝑙.𝑎𝑡 among all five indices (𝑖,𝑗,𝑘,𝑙,𝑡) (𝑖<𝑗<𝑘<𝑙<𝑡).

Input
The input consists of multiple test cases. The first line contains an integer 𝑡 (1≤𝑡≤2⋅104) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer 𝑛 (5≤𝑛≤105) — the size of the array.

The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (−3×103≤𝑎𝑖≤3×103) — given array.

It's guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅105.

Output
For each test case, print one integer — the answer to the problem.

Example
inputCopy
4
5
-1 -2 -3 -4 -5
6
-1 -2 -3 1 2 -1
6
-1 0 0 0 -1 -1
6
-9 -7 -5 -3 -2 1
outputCopy
-120
12
0
945
Note
In the first test case, choosing 𝑎1,𝑎2,𝑎3,𝑎4,𝑎5 is a best choice: (−1)⋅(−2)⋅(−3)⋅(−4)⋅(−5)=−120.

In the second test case, choosing 𝑎1,𝑎2,𝑎3,𝑎5,𝑎6 is a best choice: (−1)⋅(−2)⋅(−3)⋅2⋅(−1)=12.

In the third test case, choosing 𝑎1,𝑎2,𝑎3,𝑎4,𝑎5 is a best choice: (−1)⋅0⋅0⋅0⋅(−1)=0.

In the fourth test case, choosing 𝑎1,𝑎2,𝑎3,𝑎4,𝑎6 is a best choice: (−9)⋅(−7)⋅(−5)⋅(−3)⋅1=945.*/

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(a.begin(), a.end());
	/**
	 * we care about only the 5 maximum and the 5 minimum
	 * iterate through all posssible combination of any 5 elements out of these 10 elements
	 * and find the product of elements of that combination,
	 * whichever combination has the maximum product is the answer
	 */
	int ans = INT_MIN;
	for (int j = 0 j < 5; ++j) {
		int p = 1;
		// take j elements from the beginning
		for (int i = 0; i < j; ++i) p *= a[i];
		// take 5 - j elements from the end
		for (int i = 0; i < 5 - j; ++i) p *= a[n - 1 - i];
		ans = max(ans, p);
	}

	cout << ans << "\n";
}