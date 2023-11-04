class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int n2 = A.size();
        int N = n2 >> 1;
        unordered_map<int,int> m;
        
        for (int i: A) m[i]++;
        
        for (auto i: m) if (i.second == N) return i.first;
        
        return -1;
    }
};

////////////////////////////////////////////////////////
/*If we ever find a repeated element, it must be the answer. Let's call this answer the major element.

Consider all subarrays of length 4. There must be a major element in at least one such subarray.

This is because either:

There is a major element in a length 2 subarray, or;
Every length 2 subarray has exactly 1 major element, which means that a length 4 subarray that begins at a major element will have 2 major elements.
Thus, we only have to compare elements with their neighbors that are distance 1, 2, or 3 away.

*/
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int k = 1; k <= 3; ++k)
            for (int i = 0; i < A.size()-k; ++i)
                if (A[i] == A[i+k])
                    return A[i];
        
        return -1;
    }
    
};