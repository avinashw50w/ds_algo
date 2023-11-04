/*Given an array a of size n. Find for each element ai, the no of elements
smaller than ai and lies on left and right side of it.
Store the left side elements in array left and right side elements in array right

IDEA:
let left[i] = the no of elements less than ai and lies on the left side
so if a[i] > a[j], then left[i] = left[i] + left[j]
*/

void solve(vector<int> a) {
	int n = a.size();
	vector<int> left(n), right(n);
	stack<int> st;

	for (int i = 0; i < n; ++i) {
		while (!st.empty() and a[st.top()] < a[i]) {
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

	for (int e : left) cout << e << " ";
	cout << endl;
	for (int e : right) cout << e << " ";
}