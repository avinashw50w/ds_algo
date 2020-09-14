/* Binary Search. Time complexity : O(logn)  */
/* Note : it can be used iff the array is sorted */
/* A recursive approach */

int BinarySeach(int x, int l, int r) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (x == A[mid]) return mid;
    if (x < A[mid]) return BinarySearch(x, l, mid - 1);
    else return BinarySeach(x, mid + 1, r);
}
/*Problem Statement: Given a sorted array of N distinct elements. Find a key in the array using least number of comparisons.
(Do you think binary search is optimal to search a key in sorted array?)

Without much theory, here is typical binary search algorithm.*/

// Returns location of key, or -1 if not found
int BinarySearch(vector<int> A, int key)
{
    int l = 0, r = A.size() - 1, mid;
    while ( l <= r ) {
        mid = l + (r - l) / 2;
        if ( A[m] == key ) return m;

        if ( A[m] < key )
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

//////////////////////////////////
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
    if ( A[l] <= A[r] )
        return l;

    while ( l <= r )
    {
        // Termination condition (l will eventually falls on r, and r always
        // point minimum possible value)
        if ( l == r )
            return l;

        m = l + (r - l) / 2; // 'm' can fall in first pulse,
        // second pulse or exactly in the middle

        if ( A[m] < A[r] )
            // min can't be in the range
            // (m < i <= r), we can exclude A[m+1 ... r]
            r = m;
        else
            // min must be in the range (m < i <= r),
            // we must search in A[m+1 ... r]
            l = m + 1;
    }

    return -1;
}

int BinarySearchIndexOfMinimumRotatedArray(int A[], int size)
{
    return BinarySearchIndexOfMinimumRotatedArray(A, 0, size - 1);
}


