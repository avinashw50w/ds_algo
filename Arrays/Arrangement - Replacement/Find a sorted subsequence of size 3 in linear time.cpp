/*Find a sorted subsequence of size 3 in linear time

Given an array of n integers, find the 3 elements such that a[i] < a[j] < a[k] and i < j < k in 0(n) time.
If there are multiple such triplets, then print any one of them.

Examples:

Input:  arr[] = {12, 11, 10, 5, 6, 2, 30}
Output: 5, 6, 30*/

void solve(vector<int> a) {
	int n = a.size();
	if (n < 3) return;
	int maxx = n-1, mini = 0; // to store the maximum and minimum indexes
	// smaller[i] will store the index of the smallest no to the left of a[i]
	int smaller[n];
	smaller[0] = -1;

	for (int i = 1; i < n; ++i) {
		if (a[i] <= a[mini]) {
			mini = i;
			smaller[i] = -1;
		}
		else smaller[i] = mini;
	}

	// greater[i] will store the index of the greatest no to the right of a[i]
	int greater[n];
	greater[n - 1] = -1;

	for (int i = n - 2; i >= 0; --i) {
		if (a[i] >= a[maxx]) {
			maxx = i;
			greater[i] = -1;
		}
		else greater[i] = maxx;
	}

	for (int i = 1; i < n - 2; ++i) {
		if (smaller[i] != -1 and greater[i] != -1) {
			cout << a[smaller[i]] << " " << a[i] << " " << a[greater[i]] << endl;
			return;
		}
	}

	cout << "No triplets found\n";
}

