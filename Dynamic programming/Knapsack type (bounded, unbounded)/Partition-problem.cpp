/*Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.

Examples

arr[] = {1, 5, 11, 5}
Output: true
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1, 5, 3}
Output: false
The array cannot be partitioned into equal sum sets.

Following are the two main steps to solve this problem:
1) Calculate sum of the array. If sum is odd, there can not be two subsets with equal sum, so return false.
2) If sum of array elements is even, calculate sum/2 and find a subset of array with sum equal to sum/2.

The first step is simple. The second step is crucial, it can be solved either using recursion or Dynamic Programming.*/

bool isPartitionPossible(int a[], int n) {

    int sum = 0;

    for (int i = 0; i < n; ++i) sum += a[i];

    if (sum & 1) return false;

    bitset < sum + 1 > bit;

    bit.reset();
    bit[0] = 1;

    for (int i = 0; i < n; ++i) bit |= (bit << a[i]);

    return bit[sum / 2];
}

///////////////////////////////////////
// another way
bool check(int A[], int N) {

    int sum = 0;

    REP(i, 0, N) sum += A[i];

    if (sum  & 1) return false;

    int dp[sum + 1] = {};
    dp[0] = 1;

    for (int i = 0; i < N; ++i)
        for (int j = sum; j >= A[i]; --j)
            dp[j] |= dp[j - A[i]];

    return dp[sum >> 1];
}