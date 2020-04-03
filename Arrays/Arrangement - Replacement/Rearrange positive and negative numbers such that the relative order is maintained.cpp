/*Rearrange positive and negative numbers with constant extra space such that the relative order is maintained
3.6
Given an array of positive and negative numbers, arrange them such that all negative integers appear before all the positive
integers in the array without using any additional data structure like hash table, arrays, etc.
The order of appearance should be maintained.

Examples:

Input:  [12 11 -13 -5 6 -7 5 -3 -6]
Output: [-13 -5 -7 -3 -6 12 11 6 5]*/

/*Use merge process of merge sort:
Let Ln and Lp denotes the negative part and positive part of left sub-array respectively.
Similarly, Rn and Rp denotes the negative and positive part of right sub-array respectively.
Below are the steps to convert [Ln Lp Rn Rp] to [Ln Rn Lp Rp] without using extra space.

1. Reverse Lp and Rn. We get [Lp] -> [Lp'] and [Rn] -> [Rn']
    [Ln Lp Rn Rp] -> [Ln Lp’ Rn’ Rp]

2. Reverse [Lp’ Rn’]. We get [Rn Lp].
	[Ln Lp’ Rn’ Rp] -> [Ln Rn Lp Rp]
*/

void reverse(int a[], int l, int r) {
	while(l < r) {
		swap(a[l++], a[r--]);
	}
}

void merge(int a[], int l, int m, int r) {
	int i = l; // Initial index of 1st subarray
    int j = m + 1; // Initial index of IInd

    while (i <= m && arr[i] < 0)
        i++;

    // arr[i..m] is positive

    while (j <= r && arr[j] < 0)
        j++;

    // arr[j..r] is positive

    // reverse positive part of left sub-array (arr[i..m])
    reverse(arr, i, m);

    // reverse negative part of right sub-array (arr[m+1..j-1])
    reverse(arr, m + 1, j - 1);

    // reverse arr[i..j-1]
    reverse(arr, i, j - 1);
}

void solve(int a[], int l, int r) {
	if(l < r) {
		int mid = (l+r)>>1;
		solve(a, l, mid);
		solve(a, mid+1, r);

		merge(a, l, m, r);
	}
}
