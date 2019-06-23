/* Find the smallest missing number
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

Method 3 (Use Modified Binary Search)
Thanks to yasein and Jams for suggesting this method.
In the standard Binary Search process, the element to be searched is compared with the middle element and on 
the basis of comparison result, we decide whether to search is over or to go to left half or right half.
In this method, we modify the standard Binary Search algorithm to compare the middle element with its index and 
make decision on the basis of this comparison.

…1) If the first element is not same as its index then return first index
…2) Else get the middle index say mid
…………a) If arr[mid] greater than mid then the required element lies in left half.
…………b) Else the required element lies in right half.*/

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