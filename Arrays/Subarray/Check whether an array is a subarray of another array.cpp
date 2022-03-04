/*Check whether an array is a subarray of another array
eg. A = [2,3,1,4,5] B = [3,1,4]
Keep two pointer i and j, i for A and j for B
if both A[i] and B[j] matches increment both i and j
if not reset j to 0
also keep track of the index where the matching starts
*/


bool solve(int A[], int B[], int n, int m) {

	int l, r;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < m; ++j) {
			if (A[i+j] == B[j]) cnt++;
		}
		if (cnt == m) {
			l = i;
			r = i + m - 1
			return true
		}
	}

	return false;
}