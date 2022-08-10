/*Minimize elements to be added to a given array such that it contains another given array as its subsequence | Set 2
Difficulty Level : Expert
Last Updated : 19 Oct, 2020
Given an array A[] consisting of N distinct integers and another array B[] consisting of M 
integers, the task is to find the minimum number of elements to be added to the array B[] such 
that the array A[] becomes the subsequence of the array B[].

Examples:

Input: N = 5, M = 6, A[] = {1, 2, 3, 4, 5}, B[] = {2, 5, 6, 4, 9, 12}
Output: 3
Explanation:
Below are the element that are needed to be added:
1) Add 1 before element 2 of B[]
2) Add 3 after element 6 of B[]
3) Add 5 in the last position of B[].
Therefore, the resulting array B[] is {1, 2, 5, 6, 3, 4, 9, 12, 5}.
Hence, A[] is the subsequence of B[] after adding 3 elements.

Solution 1: find the Longest common subsequence(LCS) of A and B, the ans = len(A) - LCS
T: O(N*M), 
S: O(N*M) //optimized will be O(M)


Solution 2: for each element of B, check whether B[i] exists in A, if yes, then find its index
in A and update the LIS(longest increasing subsequence) of these indexes.
then ans = len(A) - LIS
T: O(MlogM), S:O(N)
*/

int solve(vector<int> A, vector<int> B) {
    int n = A.size(), m = B.size();

    unordered_map<int,int> mp;
    for (int i = 0; i < n; ++i) mp[A[i]] = i;

    vector<int> lis;

    for (int i = 0; i < m; ++i) {
        if (mp.count(B[i]) == 0) continue;
        int e = mp[B[i]];
        int pos = lower_bound(lis.begin(), lis.end(), e) - lis.begin();
        if (pos < lis.size()) lis[pos] = e;
        else lis.push_back(e);
    }

    return n - lis.size();
}

