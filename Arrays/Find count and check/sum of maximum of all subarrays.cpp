/*Given an array a or size n, find the sum of maximum of all possible subarrays
idea: for any element at index i, find the range around i such that a[i] is the maximum in that range
for that: traverse left of i until the elements are less than a[i] and also calculate the no of elements, say x.
Traverse to the right of i until the elements are less than a[i] and also calculate the no of elements, say y.

Now a[i] will appear in x * y no of subarrays and a[i] will be maximum in those subarrays.
So its total contibution to the sum will be a[i] * x * y

use stack DS to calculate the no of elements less than a[i] on either of its sides
Time complexity: O(N)
*/

int solve(vector<int> a) {
	int n = a.size();
	vector<int> left(n, 0), right(n, 0);

	stack<int> st;

	for (int i = 0; i < n; ++i) {
		while (!st.empty() and a[st.top()] <= a[i]) {
			left[i] += left[st.top()] + 1;
			st.pop();
		}
		st.push(i);
	}

	while (!st.empty()) st.pop();

	for (int i = n - 1; i >= 0; --i) {
		while (!st.empty() and a[st.top()] < a[i]) {
			right[i] += right[st.top()] + 1;
			st.pop();
		}
		st.push(i);
	}

	while (!st.empty()) st.pop();

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i] * (left[i] + 1) * (right[i] + 1);
	}

	return sum;
}