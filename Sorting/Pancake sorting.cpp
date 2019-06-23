/*Pancake sorting
Given an an unsorted array, sort the given array. You are allowed to do only following operation on array.

flip(arr, i): Reverse array from 0 to i 
Unlike a traditional sorting algorithm, which attempts to sort with the fewest comparisons possible, the goal is to sort the sequence in as few reversals as possible.

The idea is to do something similar to Selection Sort. We one by one place maximum element at the end and reduce the size of current array by one.

Following are the detailed steps. Let given array be arr[] and size of array be n.
1) Start from current size equal to n and reduce current size by one while it’s greater than 1. Let the current size be curr_size. Do following for every curr_size
……a) Find index of the maximum element in arr[0..curr_szie-1]. Let the index be ‘mi’
……b) Call flip(arr, mi)
……c) Call flip(arr, curr_size-1)*/

int findMaxElementIndex(int a[], int n) {
	int mx = 0;
	for (int i = 1; i < n; ++i) if (a[i] > a[mx]) mx = i;
	return i;
}

void flip(int a[], int n) {
	int l = 0, r = n;

	while(l < r) {
		swap(a[l++], a[r--]);
	}
}

void solve(int a[], int n) {

	while (n) {

		int m = findMaxElementIndex(a, n);

		if (m != n-1) {

			flip(a, m);
			flip(a, n-1);
		}
	}
}