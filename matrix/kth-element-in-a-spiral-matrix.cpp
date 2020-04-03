/*Given a 2D Matrix of order n X m , print K’th element in spiral form of matrix. See the following examples.

Examples:

Input: mat[][] = 
          {{1, 2, 3, 4}
           {5, 6, 7, 8}
           {9, 10, 11, 12}
           {13, 14, 15, 16}}
       k = 6
Output: 12

Simple Solution:
One simple solution is to start traversing matrix in spiral form Print Spiral Matrix and start a counter i.e; count = 0. 
Whenever count gets equal to K, print that element. Time complexity for this approach will be O(n^2).

Efficient Solution:
We will consider only edge of the matrix at a time and then do recursion for the sub matrix made by removing edges of main matrix.

If k <= m : element is in first row.
Else If k <= (m+n-1) : element is in last column.
Else If k <= (m+n-1+m-1) : element is in last row.
Else If k <= (m+n-1+m-1+n-2) : element is in first column.
Else Element lies somewhere in middle matrix.*/

/* function for Kth element */
int findK(int A[MAX][MAX], int n, int m, int k)
{
    if (n < 1 || m < 1)
        return -1;
 
    /*..........If element is in outermost ring .......*/
    /* Element is in first row */
    if (k <= m)
        return A[0][k-1];
 
    /* Element is in last column */
    if (k <= (m+n-1))
        return A[(k-m)][m-1];
 
    /* Element is in last row */
    if (k <= (m+n-1+m-1))
        return A[n-1][m-1-(k-(m+n-1))];
 
    /* Element is in first column */
    if (k <= (m+n-1+m-1+n-2))
        return A[n-1-(k-(m+n-1+m-1))][0];
 
    /*..........If element is NOT in outermost ring .......*/
    /* Recursion for sub-matrix. &A[1][1] is
       address to next inside sub matrix.*/
    return findK( (int (*)[MAX])(&(A[1][1])), n-2, m-2, k-(2*n+2*m-4) );
}
 
/* Driver program to test above functions */
int main()
{
    int a[MAX][MAX] = {{1, 2, 3, 4, 5, 6},
                       {7, 8, 9, 10, 11, 12},
                       {13, 14, 15, 16, 17, 18}};
    int k = 17;
    cout << findK(a, 3,6,k) << endl;
    return 0;
}
/*
Output:

 10
Time Complexity : O(c) where c is number of outer circular rings with respect to k’th element.
Space complexity: O(1) */