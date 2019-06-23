/*Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index */

vector<int> Solution::maxset(vector<int> &A) {
    
    long sum = 0, maxsum = INT_MIN, maxlen = 0, idx = 0, start = 0, end;
    
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] >= 0) 
            sum += A[i];
       
        else {
            sum = 0;
            idx = i+1;
        }
        
        if(sum >= maxsum) {
            
            if(sum == maxsum) {
                if(i-idx+1 > maxlen) {
                    maxlen = i-idx+1;
                    start = idx;
                    end = i;
                }
            }
            else {
                maxsum = sum;
                start = idx;
                end = i;
            }
 
        }
    }
    
    vector<int> res;
    for(int i=start; i<=end; ++i) res.push_back(A[i]);
    
    return res;
}
