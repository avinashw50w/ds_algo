/* given an array of N integers. Also given an integer S, in one operation, you can pick
a subarray of size S and increment each array value by 1. You can perform this operation M times.
You are required to maximize the minimum value among all the array elements. Find the minimum value
after performing the described operation atmost M times.*/

vector<int> A;
int S, M;

// check if it is possible to convert the minimum value in the array to x in atmost M operations
bool possible(int x) {
	int mini = *min_element(A.begin(), A.end());
	int operations = x - mini;
	return x <= M;
}

int solve() {
	int n = A.size();

	int l = 1, r = (int)1e9;
	int mid, ans = 1;

	while (l <= r) {
		mid = (l + r) / 2;
		if (possible(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	return ans;
}