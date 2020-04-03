/* Binary Search. Time complexity : O(logn)  */
/* Note : it can be used iff the array is sorted */
/* A recursive approach */

int BinarySeach(int x, int l, int r) {
	if(l > r) return -1;
    int mid = l + (r-l)/2;
    if(x == A[mid]) return mid;
    if(x < A[mid]) return BinarySearch(x, l, mid-1);
    else return BinarySeach(x, mid+1, r);
}
/*Problem Statement: Given a sorted array of N distinct elements. Find a key in the array using least number of comparisons. 
(Do you think binary search is optimal to search a key in sorted array?)

Without much theory, here is typical binary search algorithm.*/

// Returns location of key, or -1 if not found
int BinarySearch(int A[], int l, int r, int key)
{
    int m;
 
    while( l <= r )
    {
        m = l + (r-l)/2;
 
        if( A[m] == key ) // first comparison
            return m;
 
        if( A[m] < key ) // second comparison
            l = m + 1;
        else
            r = m - 1;
    }
 
    return -1;
}
/*Theoretically we need log N + 1 comparisons in worst case. If we observe, we are using two comparisons per iteration except during 
final successful match, if any. In practice, comparison would be costly operation, it won’t be just primitive type comparison. 
It is more economical to minimize comparisons as that of theoretical limit.*/

// Invariant: A[l] <= key and A[r] > key
// Boundary: |r - l| = 1
// Input: A[l .... r-1]
int BinarySearch(int A[], int l, int r, int key)
{
    int m;
 
    while( r - l > 1 )
    {
        m = l + (r-l)/2;
 
        if( A[m] <= key )
            l = m;
        else
            r = m;
    }
 
    if( A[l] == key )
        return l;
    else
        return -1;
}

/*Problem Statement: Given an array of N distinct integers, find floor value of input ‘key’. 
Say, A = {-1, 2, 3, 5, 6, 8, 9, 10} and key = 7, we should return 6 as outcome.*/

// largest value <= key
// Invariant: A[l] <= key and A[r] > key
// Boundary: |r - l| = 1
// Input: A[l .... r-1]
// Precondition: A[l] <= key <= A[r]
int Floor(int A[], int l, int r, int key)
{
    int m;
 
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( A[m] <= key )
            l = m;
        else
            r = m;
    }
 
    return A[l];
}
 
// Initial call
int Floor(int A[], int size, int key)
{
    // Add error checking if key < A[0]
    if( key < A[0] )
        return -1;
 
    // Observe boundaries
    return Floor(A, 0, size, key);
}

/*Problem Statement: Given a sorted array with possible duplicate elements. Find number of occurrences of input ‘key’ in log N time.

The idea here is finding left and right most occurrences of key in the array using binary search. We can modify 
floor function to trace right most occurrence and left most occurrence. Here is implementation,*/

// Input: Indices Range [l ... r)
// Invariant: A[l] <= key and A[r] > key
int GetLastOccurence(int A[], int l, int r, int key)
{
    int m;
 
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( A[m] <= key )
            l = m;
        else
            r = m;
    }
 
    return l;
}
 
// Input: Indices Range (l ... r]
// Invariant: A[r] >= key and A[l] > key
int GetFirstOccurence(int A[], int l, int r, int key)
{
    int m;
 
    while ( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if ( key <= A[m] )
            r = m;
        else
            l = m;
    }
 
    return r;
}
 
int CountOccurances(int A[], int size, int key)
{
    // Observe boundary conditions
    int left = GetFirstOccurence(A, 0, size, key);
    int right = GetLastOccurence(A, 0, size, key);
 
    // What if the element doesn't exists in the array?
    // The checks helps to trace that element exists
    return (A[left] == key && key == A[right])?
           (right - left + 1) : 0;
}

/*Problem Statement: Given a sorted array of distinct elements, and the array is rotated at an unknown position. Find minimum element in the array.

eg : 6 7 8 9 10 1 2 3 4 5			

We converge the search space till l and r points single element. If the middle location falls in the first pulse, 
the condition A[m] < A[r] doesn’t satisfy, we exclude the range A[m+1 … r]. If the middle location falls in the second pulse, 
the condition A[m] < A[r] satisfied, we converge our search space to A[m+1 … r]. At every iteration we check for search space size, 
if it is 1, we are done.*/

int BinarySearchIndexOfMinimumRotatedArray(int A[], int l, int r)
{
    // extreme condition, size zero or size two
    int m;
 
    // Precondition: A[l] > A[r]
    if( A[l] <= A[r] )
        return l;
 
    while( l <= r )
    {
        // Termination condition (l will eventually falls on r, and r always
        // point minimum possible value)
        if( l == r )
            return l;
 
        m = l + (r-l)/2; // 'm' can fall in first pulse,
                        // second pulse or exactly in the middle
 
        if( A[m] < A[r] )
            // min can't be in the range
            // (m < i <= r), we can exclude A[m+1 ... r]
            r = m;
        else
            // min must be in the range (m < i <= r),
            // we must search in A[m+1 ... r]
            l = m+1;
    }
 
    return -1;
}
 
int BinarySearchIndexOfMinimumRotatedArray(int A[], int size)
{
    return BinarySearchIndexOfMinimumRotatedArray(A, 0, size-1);
}


