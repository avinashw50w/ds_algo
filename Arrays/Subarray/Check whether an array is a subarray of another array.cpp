/*Check whether an array is a subarray of another array
eg. A = [2,3,1,4,5] B = [3,1,4]
Keep two pointer i and j, i for A and j for B
if both A[i] and B[j] matches increment both i and j
if not reset j to 0
also keep track of the index where the matching starts
*/


bool solve(int A[], int B[], int n, int m) {

	int i = 0, j = 0, start = -1;

	while (i < n and j < m) {

		if (A[i] == B[j]) {

			if (start == -1) start = i;
			i++; j++;

			if (j == m) return true;
		}
		else {

			i = ++start;
			start = -1;
			j = 0;
		}
	}

	return false;
}