/*Union and Intersection of two sorted arrays
Given two sorted arrays, find their union and intersection.

For example, if the input arrays are: 
arr1[] = {1, 3, 4, 5, 7}
arr2[] = {2, 3, 5, 6}
Then your program should print Union as {1, 2, 3, 4, 5, 6, 7} and Intersection as {3, 5}. 

Algorithm Union(arr1[], arr2[]): similar to merge process of merge sort
For union of two arrays, follow the following merge procedure.
1) Use two index variables i and j, initial values i = 0, j = 0
2) If arr1[i] is smaller than arr2[j] then print arr1[i] and increment i.
3) If arr1[i] is greater than arr2[j] then print arr2[j] and increment j.
4) If both are same then print any of them and increment both i and j.
5) Print remaining elements of the larger array.*/
// time : O(n+m)
int* Union(int a[], int b[], int n, int m) {

	int *tmp = new int[m+n];
	int i = 0, j = 0, k = 0;
	
	while(i < n and j < m) {
	
		if(a[i] < b[j]) tmp[k++] = a[i++];
	
		else if(a[i] > b[j]) tmp[k++] = b[j++];
	
		else {
			tmp[k++] = a[i++];
			j++;
		}
	}
	while(i < n) tmp[k++] = a[i++];
	while(j < m) tmp[k++] = b[j++];

	return tmp;
}

/*Algorithm Intersection(arr1[], arr2[]):
For Intersection of two arrays, print the element only if the element is present in both arrays.
1) Use two index variables i and j, initial values i = 0, j = 0
2) If arr1[i] is smaller than arr2[j] then increment i.
3) If arr1[i] is greater than arr2[j] then increment j.
4) If both are same then print any of them and increment both i and j.
time : O(n+m) */

int* intersection(int a[], int b[], int n, int m) {
	int *tmp = a[n];
	int i = 0, j = 0, k = 0;

	while(i < n and j < m) {

		if(a[i] < b[j]) i++;

		else if(a[i] > b[j]) j++;

		else {
			tmp[k++] = a[i++];
			j++;
		}
	}

	return tmp;
}
