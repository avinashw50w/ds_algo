/*Given an array of lengh N, ranging from 0 to N-1. All elements may not be present in the array.
If the element is not present then there will be -1 present in the arrray. Rearrange the array such that
A[i] = i and if i is not present in the array then display -1 at that place.

eg. Input: {-1,-1,6,1,9,3,2,-1,4,-1};
Output:    {-1,1,2,3,4,-1,6,-1,-1,9} */

void solve(vector<int> &a) {
    int n = a.size();
    vector<int> pos(a.size(), -1);
    
    for (int i=0; i<n; ++i) {
        if(a[i] >=0) 
            pos[a[i]] = i;
    }
    
    for (int i = 0; i < n; ++i) {
        if (a[i] != i and pos[i] != -1) {
            int ai = a[i];
            int aposi = a[pos[i]];
            swap(a[pos[i]], a[i]);
            swap(pos[ai], pos[aposi]);
        }
    }
}