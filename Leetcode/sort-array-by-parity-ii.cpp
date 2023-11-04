/*Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int N = A.size();
        int k = 0;
        for (int i = 0; i < N; ++i) if (A[i] & 1) swap(A[k++], A[i]);
        
        int e = k, o = 0;
        while(e < N and o < e) swap(A[e], A[o]), e++, o += 2;
        return A;
    }
};