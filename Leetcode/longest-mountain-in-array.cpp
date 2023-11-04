/*Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain. 

Return 0 if there is no mountain.

Example 1:

Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: [2,2,2]
Output: 0
Explanation: There is no mountain.*/

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int N = A.size();
        if (!N) return 0;
        if (N == 1) return 0;
        int l[N+2], r[N+2];
        
        l[0] = 0;
        for (int i = 1; i < N; ++i) 
            l[i] = A[i-1] < A[i] ? l[i-1]+1: 0;
        
        r[N-1] = 0;
        for (int i = N-2; i >= 0; --i)
            r[i] = A[i] > A[i+1] ? r[i+1]+1: 0;
        
        int ans = 0;
        for (int i = 0; i < N; ++i) 
            if (l[i] and r[i]) 
                ans = max(ans, l[i]+r[i]+1);
        
        return ans == 1 ? 0 : ans;
    }
};