/*Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]
 

Example 1:

Input: "IDID"
Output: [0,4,1,3,2]

If we see say S[0] == 'I', we can always put 0 as the first element; 
similarly, if we see S[0] == 'D', we can always put N as the first element.

Say we have a match for the rest of the string S[1], S[2], ... using N distinct elements. 
Notice it doesn't matter what the elements are, only that they are distinct and totally ordered. 
Then, putting 0 or N at the first character will match, and the rest of the elements 
(1, 2, ..., N or 0, 1, ..., N-1) can use the matching we have.

Algorithm

Keep track of the smallest and largest element we haven't placed. If we see an 'I', 
place the small element; otherwise place the large element.*/

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.size();
        int lo = 0, hi = N;
        
        vector<int> ans;
        
        for (char c: S) 
            if (c == 'I') ans.push_back(lo++);
            else ans.push_back(hi--);
        
        // now lo == hi
        ans.push_back(lo);
        return ans;
    }
};