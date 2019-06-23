/*The idea of MO’s algorithm is to pre-process all queries so that result of one query can be used in next query. Below are steps.

Let a[0…n-1] be input array and q[0..m-1] be array of queries.

Sort all queries in a way that queries with L values from 0 to √n – 1 are put together, then all queries from √n to 2*√n – 1, and so on. All queries within a block are sorted in increasing order of R values.
Process all queries one by one in a way that every query uses sum computed in previous query.
Let ‘sum’ be sum of previous query.
Remove extra elements of previous query. For example if previous query is [0, 8] and current query is [3, 9], then we subtract a[0] and a[1] from sum
Add new elements of current query. In the same example as above, we add a[9] to sum.
The great thing about this algorithm is, in step 2, index variable for R change at most O(n * √n) times throughout the run and same for L changes its value at most O(m * √n) times (See below, after the code, for details). All these bounds are possible only because sorted queries first in blocks of √n size.

The preprocessing part takes O(m Log m) time.

Processing all queries takes O(n * √n) + O(m * √n) = O((m+n) * √n) time.

Below is C++ implementation of above idea.*/

// Program to compute sum of ranges for different range
// queries
#include <bits/stdc++.h>
using namespace std;
 
// Variable to represent block size. This is made global
// so compare() of sort can use it.
int block;
 
// Structure to represent a query range
struct Query
{
    int L, R;
};
 
// Function used to sort all queries so that all queries 
// of same block are arranged together and within a block,
// queries are sorted in increasing order of R values.
bool compare(Query x, Query y)
{
    // Different blocks, sort by block.
    if (x.L/block != y.L/block)
        return x.L/block < y.L/block;
 
    // Same block, sort by R value
    return x.R < y.R;
}
 
// Prints sum of all query ranges. m is number of queries
// n is size of array a[].
void queryResults(int a[], int n, Query q[], int m)
{
    // Find block size
    block = (int)sqrt(n);
 
    // Sort all queries so that queries of same blocks
    // are arranged together.
    sort(q, q + m, compare);
 
    // Initialize current L, current R and current sum
    int currL = 0, currR = 0;
    int currSum = 0;
 
    // Traverse through all queries
    for (int i=0; i<m; i++)
    {
        // L and R values of current range
        int L = q[i].L, R = q[i].R;
 
        // Remove extra elements of previous range. For
        // example if previous range is [0, 3] and current
        // range is [2, 5], then a[0] and a[1] are subtracted
        while (currL < L)
        {
            currSum -= a[currL];
            currL++;
        }
 
        // Add Elements of current Range
        while (currL > L)
        {
            currSum += a[currL-1];
            currL--;
        }
        while (currR <= R)
        {
            currSum += a[currR];
            currR++;
        }
 
        // Remove elements of previous range.  For example
        // when previous range is [0, 10] and current range
        // is [3, 8], then a[9] and a[10] are subtracted
        while (currR > R+1)
        {
            currSum -= a[currR-1];
            currR--;
        }
 
        // Print sum of current range
        cout << "Sum of [" << L << ", " << R
             << "] is "  << currSum << endl;
    }
}
 
// Driver program
int main()
{
    int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    int n = sizeof(a)/sizeof(a[0]);
    Query q[] = {{0, 4}, {1, 3}, {2, 4}};
    int m = sizeof(q)/sizeof(q[0]);
    queryResults(a, n, q, m);
    return 0;
}
/*
Output:

Sum of [1, 3] is 4
Sum of [0, 4] is 8
Sum of [2, 4] is 6
The output of above program doesn’t print results of queries in same order as input, because queries are sorted. The program can be easily extended to keep the same order.

Important Observations:

All queries are known beforehead so that they can be preprocessed
It cannot work for problems where we have update operations also mixed with sum queries.
MO’s algorithm can only be useful for query problems where a query can be computed from results of previous query. One more such example is maximum or minimum.*/