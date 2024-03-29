// 1 2 3 4 5 6 7 8 -> 5 6 7 8 1 2 3 4

int SearchCircularArray(int A[], int n, int x) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (A[mid] == x) return mid;
		if (A[mid] <= A[high]) { // we lie on the right half
			if (A[mid] < x && x <= A[high])
				low = mid + 1;
			else high = mid - 1;
		}
		else {          //  we lie on the left half
			if (A[low] <= x && x < A[mid])
				high = mid - 1;
			else low = mid + 1;
		}
	}
}

/* Let's say array is like this : 5 6 7 8 9 1 2 3 4    */
