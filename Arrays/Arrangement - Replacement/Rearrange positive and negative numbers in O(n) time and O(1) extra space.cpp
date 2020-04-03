/*Rearrange positive and negative numbers in O(n) time and O(1) extra space
An array contains both positive and negative numbers in random order. Rearrange the array elements so that positive and 
negative numbers are placed alternatively. Number of positive and negative numbers need not be equal. If there are more 
positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

For example, if the input array is [-1, 2, -3, 4, 5, 6, -7, 8, 9], then the output should be [9, -7, 8, -3, 5, -1, 2, 4, 6]

The solution is to first separate positive and negative numbers using partition process of QuickSort. In the partition process, 
consider 0 as value of pivot element so that all negative numbers are placed before positive numbers. Once negative and 
positive numbers are separated, we start from the first negative number and first positive number, 
and swap every alternate negative number with next positive number.*/

void rearrange(int a[], int n) {

	int i = 0;
	// put all negative nos at the beginning
	for(int j = 0; j < n; ++j) {
		if(a[j] < 0) {
			swap(a[i++], a[j]);
		}
	}

	int pos = i, neg = 0;

	while(pos < n and neg < pos and a[neg] < 0) {
		swap(a[neg], a[pos]);
		pos++;
		neg += 2;
	}
}