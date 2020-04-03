/*Find a peak element
Given an array of integers. Find a peak element in it. An array element is peak if it is NOT smaller than its neighbors. For corner elements, we need to consider only one neighbor. For example, for input array {5, 10, 20, 15}, 20 is the only peak element. For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90. Note that we need to return any one peak element.

Following corner cases give better idea about the problem.
1) If input array is sorted in strictly increasing order, the last element is always a peak element. For example, 50 is peak element in {10, 20, 30, 40, 50}.
2) If input array is sorted in strictly decreasing order, the first element is always a peak element. 100 is the peak element in {100, 80, 60, 50, 20}.
3) If all elements of input array are same, every element is a peak element.*/

//find the peak element
int find(int a[], int n) {
    int l = 0, r = n-1, mid;

    while(l <= r) {
        mid = (l+r)>>1;
        if ((mid == 0 or a[mid-1] <= a[mid]) 
            && (mid == n-1 or a[mid] >= a[mid+1]))
        return a[mid];

        if (mid > 0 and a[mid-1] > a[mid]) r = mid-1;
        else l = mid+1;
    }

return 0;
}

/*Find a peak element in a 2D array
An element is a peak element if it is greater than or equal to its four neighbors, left, right, top and bottom. For example neighbors for A[i][j] are A[i-1][j], A[i+1][j], A[i][j-1] and A[i][j+1]. For corner elements, missing neighbors are considered of negative infinite value.

Examples:

Input : 10 20 15
        21 30 14
        7  16 32 
Output : 30
30 is a peak element because all its 
neighbors are smaller or equal to it. 
32 can also be picked as a peak.

Input : 10 7
        11 17
Output : 17 

Method 1: (Brute Force)
Iterate through all the elements of Matrix and check if it is greater/equal to all its neighbors. If yes, return the element.

Time Complexity: O(rows * columns)
Auxiliary Space: O(1)

Method 2 : (Efficient)
This problem is mainly an extension of Find a peak element in 1D array. We apply similar Binary Search based solution here.

Consider mid column and find maximum element in it.
Let index of mid column be ‘mid’, value of maximum element in mid column be ‘max’ and maximum element be at ‘mat[max_index][mid]’.
If max >= A[index][mid-1] & max >= A[index][pick+1], max is a peak, return max.
If max < mat[max_index][mid-1], recur for left half of matrix.
If max < mat[max_index][mid+1], recur for right half of matrix.*/

int findMax(int arr[][MAX], int rows, int mid, int &max) 
{ 
    int max_index = 0; 
    for (int i = 0; i < rows; i++) 
    { 
        if (max < arr[i][mid]) 
        { 
            // Saving global maximum and its index 
            // to check its neighbours 
            max = arr[i][mid]; 
            max_index = i; 
        } 
    } 
    return max_index; 
} 
  
// Function to find a peak element 
int findPeakRec(int arr[][MAX], int rows, int columns, 
                                              int mid) 
{ 
    // Evaluating maximum of mid column. Note max is 
    // passed by reference. 
    int max = 0; 
    int max_index = findMax(arr, rows, mid, max); 
  
    // If we are on the first or last column, 
    // max is a peak 
    if (mid == 0 || mid == columns-1) 
        return max; 
  
    // If the max at mid is greater than its left and right elements( the max at mid is already greater than its top and bottom elements)
    if (max >= arr[max_index][mid-1] && 
            max >= arr[max_index][mid+1]) 
        return max; 
  
    // If max is less than its left 
    if (max < arr[max_index][mid-1]) 
        return findPeakRec(arr, rows, columns, mid - mid/2); 
  
    // If max is less than its left 
    // if (max < arr[max_index][mid+1]) 
    return findPeakRec(arr, rows, columns, mid+mid/2); 
} 
  
// A wrapper over findPeakRec() 
int findPeak(int arr[][MAX], int rows, int columns) 
{ 
    return findPeakRec(arr, rows, columns, columns/2); 
} 
  
