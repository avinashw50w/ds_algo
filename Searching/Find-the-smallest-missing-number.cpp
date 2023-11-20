/* Find the smallest/first missing number
Given a sorted array of n integers where each integer is in the range from 0 to m-1 and m > n. Find the smallest number that is missing from the array.

Examples
Input: {0, 1, 2, 6, 9}, n = 5, m = 10
Output: 3

Input: {4, 5, 10, 11}, n = 4, m = 12
Output: 0

Input: {0, 1, 2, 3}, n = 4, m = 5
Output: 4

Input: {0, 1, 2, 3, 4, 5, 6, 7, 10}, n = 9, m = 11
Output: 8 

IDEA: find the smallest index where i != a[i] */

int find(vector<int> a) {
	int n = a.size(), l = 0, r = n-1;
	
	if (a[n-1] == n-1) return n;
	
	while (l < r) {
		int mid = (l+r)>>1;
		if (mid != a[mid]) r = mid;
		else l = mid+1;
	}
	return l;
}

// recursive
int find(int a[], int start, int end) {
	if(start  > end) return end+1;

	if(start != a[start]) return start;

	int mid = (start+end)>>1;
	if(a[mid] > mid) 
		return find(a, start, mid);
	else
		return find(a, mid+1, end);
}

// driver program to test above function
int main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf(" First missing element is %d",
		findFirstMissing(arr, 0, n-1));
	getchar();
	return 0;
}