/*Find position of an element in a sorted array of infinite numbers
Suppose you have a sorted array of infinite numbers, how would you search an element in the array?

Source: Amazon Interview Experience.

Since array is sorted, the first thing clicks into mind is binary search, but the problem here is that we don’t know size of array.
If the array is infinite, that means we don’t have proper bounds to apply binary search. So in order to find position of key, 
first we find bounds and then apply binary search algorithm.

Let low be pointing to 1st element and high pointing to 2nd element of array, Now compare key with high index element,
->if it is greater than high index element then copy high index in low index and double the high index.
->if it is smaller, then apply binary search on high and low indices found.
Below are implementations of above algorithm*/

int findPos(int a[], int key) {

	int l = 0, h = 1;
	int val = a[0];

	while(val < key) {
		l = h;
		h = 2*h;
		val = a[h];
	}

	return Bsearch(a, l, h, key);
}

int Bsearch(int a[], int l, int h, int key) {
	int mid;
	if(l <= h) {
		mid = (l+r)>>1;
		if(a[mid] == key) return mid;
		else if(key < a[mid]) return Bsearch(a, l, mid-1, key);
		else return Bsearch(a, mid+1, h, key);
	}
	return -1;
}