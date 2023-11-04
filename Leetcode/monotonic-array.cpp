/*An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

 

Example 1:

Input: [1,2,2,3]
Output: true*/
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        
        if (n < 3) return true;
        
        int inc = 0, dec = 0;
        
        for (int i = 1; i < n; ++i) {
            if (A[i-1] == A[i]) continue;
            if (A[i-1] < A[i]) {
                if (dec) return false;
                inc = 1;
            }
            else if (A[i-1] > A[i]) {
                if (inc) return false;
                dec = 1;
            }
        }
        
        return true;
    }
};