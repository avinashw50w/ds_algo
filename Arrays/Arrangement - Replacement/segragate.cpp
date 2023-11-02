/*Segregate 0s and 1s in an array
You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array.
Traverse array only once.

Input array   =  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0]
Output array =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1]

Method 2 (Use two indexes to traverse)
Maintain two indexes. Initialize first index left as 0 and second index right as n-1.
*/
// another method

void segregate(int a[], int n) {
	int k = 0;

	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) swap(a[k++], a[i]);
	}
}

///////////////////////////////////
/*segregate even and odd elements of array so that all the even nos comes before all the odd nos*/
void solve(vector<int> &a) {
    int k = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] % 2 == 0) swap(a[k++], a[i]);
    }
}
