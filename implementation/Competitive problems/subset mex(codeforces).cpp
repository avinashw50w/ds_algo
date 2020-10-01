/*Given a set of integers (it can contain equal elements).

You have to split it into two subsets 𝐴 and 𝐵 (both of them can contain equal elements or be empty). You have to maximize the value of 𝑚𝑒𝑥(𝐴)+𝑚𝑒𝑥(𝐵).

Here 𝑚𝑒𝑥 of a set denotes the smallest non-negative integer that doesn't exist in the set. For example:

𝑚𝑒𝑥({1,4,0,2,2,1})=3
𝑚𝑒𝑥({3,3,2,1,3,0,0})=4
𝑚𝑒𝑥(∅)=0 (𝑚𝑒𝑥 for empty set)
The set is splitted into two subsets 𝐴 and 𝐵 if for any integer number 𝑥 the number of occurrences of 𝑥 into this set is equal to the sum of the number of occurrences of 𝑥 into 𝐴 and the number of occurrences of 𝑥 into 𝐵.

Input
The input consists of multiple test cases. The first line contains an integer 𝑡 (1≤𝑡≤100) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer 𝑛 (1≤𝑛≤100) — the size of the set.

The second line of each testcase contains 𝑛 integers 𝑎1,𝑎2,…𝑎𝑛 (0≤𝑎𝑖≤100) — the numbers in the set.

Output
For each test case, print the maximum value of 𝑚𝑒𝑥(𝐴)+𝑚𝑒𝑥(𝐵).

Example
inputCopy
4
6
0 2 1 5 0 1
3
0 1 2
4
0 2 0 1
6
1 2 3 4 5 6
outputCopy
5
3
4
0*/

int mex(set<int> st) {
	for (int i = 0; i < 102; ++i) if (!st.count(i)) return i;
}
// O(NlogN)
void solve() {
	int n; cin >> n;
	set<int> used, used2;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (used.count(x)) used2.insert(x);
		else used.insert(x);
	}

	cout << (mex(used) + mex(used2)) << "\n";
}
// another method
// O(N)
void solve2() {
	int n, x, i; cin >> n;
	int a[101] = {};
	for (int i = 0; i < n; ++i) cin >> x, a[x]++;
	int ans = 0;
	for (i = 0; a[i]; ++i) a[i]--;
	ans += i;
	for (i = 0; a[i]; ++i);
	ans += i;
	cout << ans << "\n";
}

int main() {
	int t; cin >> t;
	while (t--) {

		solve();
	}
}