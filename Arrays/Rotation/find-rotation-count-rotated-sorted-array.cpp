/*Find the Rotation Count in Rotated Sorted array
2.3
Consider an array of distinct numbers sorted in increasing order. The array has been rotated (anti-clockwise) k number of times. 
Given such an array, find the value of k.

Examples:

Input : arr[] = {15, 18, 2, 3, 6, 12}
Output: 2
Explanation : Initial array must be {2, 3,
6, 12, 15. 18}. We get the given array after 
rotating the initial array twice.

Input : arr[] = {7, 9, 11, 12, 5}
Output: 4

Input: arr[] = {7, 9, 11, 12, 15};
Output: 0*/

/*explanation: if the next no is smaller than the previous(anamoly), then the array is sorted upto that index. Use binary search 
to find that index.*/

int countRotations(int a[], int l, int r) {
	if(l > r) return 0; // no anomalies found

	if(l == r) return l;

	int mid = (l+r)>>1;

	if(mid < r and a[mid] > a[mid+1]) return mid+1; // when next no is smaller than the previous no

	if(mid > l and a[mid-1] > a[mid]) return mid;

	if(a[mid] < a[r]) return countRotations(a, l, mid-1);

	return countRotations(a, mid+1, r);
}