/* Given 2 sorted arrays A and B, sorted in increasing order, find the minimum value of |A[i]-B[j]| 
for all i belonging to A and all j belonging to B. Preffered order O(m+n) in the worst case. 
m being size of array A and n being size of array B. 

Then he extended the same question to n sorted arrays with k elements each. 
I was required to find the minimum range in which the values fall.*/

// apply merge process

int solve(int A[], int N, int B[], int M) {

	int i = 0, j = 0, ans = INT_MAX;

	while(i < N and j < M) {

		if(A[i] == B[j]) {
			ans = 0;
			break;
		}

		else if(A[i] < B[j]) {
			ans = min(ans, abs(A[i]-B[j]));
			i++;
		}

		else {
			ans = min(ans, abs(A[i]-B[j]));
			j++;
		}
	}
	return ans;
}
