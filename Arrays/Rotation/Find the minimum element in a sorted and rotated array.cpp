/*Find the minimum element in a sorted and rotated array
Input: {5, 6, 1, 2, 3, 4}
Output: 1

Input: {1, 2, 3, 4}
Output: 1

Input: {2, 1}
Output: 1*/

/*This question is just like the question 'find rotation count in rotated sorted array'. In this question, we have to
return the no at the index instead of returning the index itself.*/

int findMin(int a[], int l, int r) {
	if(l > r) return a[0]; // no anomalies found, ie no rotation found so the min element is the first element

	if(l == r) return a[l];

	int mid = (l+r)>>1;

	if(mid < r and a[mid] > a[mid+1]) return a[mid+1]; // when next no is smaller than the previous no

	if(mid > l and a[mid-1] > a[mid]) return a[mid];

	if(a[mid] < a[r]) return findMin(a, l, mid-1);

	return findMin(a, mid+1, r);
}