/*Longest consecutive subsequence
Given an array arr[] of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Input:
The first line of input contains T, number of test cases. First line of line each test case contains a single integer N.
Next line contains N integer array.

Output:
Print the output of each test case in a seprate line.

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= a[i] <= 105

Example:
Input:
2
7
2 6 1 9 4 5 3
7
1 9 3 10 4 20 2

Output:
6
4

Explanation:
Testcase 1:  The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.

Testcase2: 1, 2, 3, 4 is the longest consecutive subsequence.

IDEA: since the order of the subsequence doesn't matter, the problem reduces to
finding the longest subset with all consecutive nos.
- sort the array
- remove duplicates
- find the longest subarray with consecutive nos
*/

int solve(vector<int> a) {
	int n = a.size(), i = 0;
	sort(a.begin(), a.end());
	// remove duplicates
	int k = 0;
	while (i < n) {
		int len = 1;
		while (i + len < n and a[i + len] == a[i]) len++;
		a[k++] = a[i];
		i += len;
	}

	a.resize(k);

	n = a.size();
	i = 0;
	int ans = 1;
	while (i < n) {
		int len = 1;
		while (i + len < n and a[i + len] == a[i] + len) len++;
		ans = max(ans, len);
		i += len;
	}

	return ans;
}