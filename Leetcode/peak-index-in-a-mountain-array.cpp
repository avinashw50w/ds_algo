/*Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1*/

class Solution {
public:
    
    int find(vector<int> A) {
        int l = 0, r = A.size()-1, mid;        
        while (l <= r) {
            if (l == r) return l;
            if (r-l == 1) {
                if (A[l] > A[r]) return l;
                else return r;
            }
            mid = (l+r) >> 1;
            
            if (A[mid-1] < A[mid] and A[mid] > A[mid+1]) return mid;
            
            if (A[mid-1] > A[mid] and A[mid] > A[mid+1]) r = mid-1;
            else l = mid+1;
        }
        
        return -1;
    }
    int peakIndexInMountainArray(vector<int>& A) {
        int idx = find(A);
        return idx;
    }
};