/*Segregate 0s and 1s in an array
You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array. 
Traverse array only once.

Input array   =  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
Output array =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1] 

Method 2 (Use two indexes to traverse)
Maintain two indexes. Initialize first index left as 0 and second index right as n-1.

Do following while left < right
a) Keep incrementing index left while there are 0s at it
b) Keep decrementing index right while there are 1s at it
c) If left < right then exchange arr[left] and arr[right] 
*/
void segregate(int a[], int n) {
	int l = 0, r = n-1;
	while(l < r) {
		while(l < r and a[l] == 0) l++; // while there are 0s in the left, move forward
		while(l < r and a[r] == 1) r--; // while there are 1s in the right, move backward

		// if l < r, means a[l] = 1 and a[r] = 0, so swap them and increment l and decrement r
		if(l < r) {
			a[l++] = 0;
			a[r--] = 1;
		} 
	}
}

///////////////////////////////////

// another method

void segregate(int a[], int n) {
	int k = 0;

	for(int i = 0; i < n; ++i) {
		if(a[i] == 0)
			a[k++] = 0;
	}

	while(k < n)
		a[k++] = 1;
}