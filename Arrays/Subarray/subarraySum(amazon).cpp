/*Given an array (length n), we need to find the subarray (length k) such that the sum of the first j elements of the subarray 
equals the sum of the remaining (k-j) elements of the subarray. 
For e.g. 
Array: 2,2,13,4,7,3,8,12,9,1,5 
Output: 4,7,3,8,12,9,1 [4+7+3+8=12+9+1] 
Could this be done with a complexity better than O(n^3) */

/* keep an index i fixed and expand on both sides calculating the left and right sum respectively and check whether the left 
and right sum are the same, if same then update the maxlen*/

void solve(int a[], int n) {

    int left = 0, right = 0, maxLen, st, end;

    for (int i = 0; i < n-1; ++i) {
        int l = i, r = i+1;
        left = 0, right = 0;

        while(l >= 0 and r < n) {
            left += a[l];
            right += a[r];

            if (left == right and maxLen > r-l+1) 
                maxLen = r-l+1,
                st = l, end = r; 

            l--; r++;
        }
    }

    for (int i = st; i <= end; ++i) cout << a[i] << " ";
}
