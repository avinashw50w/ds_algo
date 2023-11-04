/*Given an array of integers A sorted in non-decreasing order, return an array of the 
squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> v;
        for (int i: A) v.push_back(i*i);
        
        sort(v.begin(), v.end());
        return v;
    }
};

///////////////////////////////////////////////////
// O(N)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int N = A.size();
        vector<int> ans(N);
        
        int i, j = 0, k = 0;
        
        while (j < N and A[j] < 0) j++;
        
        i = j-1;
        
        while (i >= 0 and j < N) {
            if (A[i] * A[i] < A[j] * A[j]) {
                ans[k++] = A[i] * A[i];
                i--;
            }
            else {
                ans[k++] = A[j] * A[j];
                j++;
            }
        }
        
        while (i >= 0) {
            ans[k++] = A[i] * A[i];
            i--;
        }
        while (j < N) {
            ans[k++] = A[j] *A[j];
            j++;
        }
        
        return ans;
    }
};