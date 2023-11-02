/*Let the array be [a_1, a_2, ... a_n]. Then each element, a_i, may appear in many subarrays. 
There are i * (n - i + 1) subarrays that contain a_i, because there are i left endpoints and (n - i + 1) right endpoints, 
and each (left, right) pair uniquely defines a subarray.
eg. 1 2 3
1,2,3,12,23,123*/

int findSum(int a[], int n) {
	int res = 0;

	REP(i, 0, n) 
		res += a[i] * (i+1) * (n-i);

	return res;
}