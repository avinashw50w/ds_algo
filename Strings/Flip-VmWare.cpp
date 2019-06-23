/*You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. 
In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. 
By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform 
the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. 
If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes: 
- Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.

For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
Another example,

If S = 111

No operation can give us more than three 1s in final string. So, we return empty array [].*/
/* Just find the subarray where the value (no of zeroes - no of ones) is maximum. For that replace 0s with 1 and 1s with -1.
and find the maximum sum subarray.*/

vector<int> Solution::flip(string A) {

    int sum = 0;
    int n = A.length();
    int a[n];
    for(int i = 0; i < n; ++i) {
        sum += A[i]-'0';
        a[i] = (A[i]=='0')? 1: -1; 
    }
    
    int idx = 0, prefix = 0, l = 0, r = 0, maxSum = 0;
    for(int i = 0; i < n; ++i) {
        prefix += a[i];      
        if(prefix < 0) {
            prefix = 0;
            idx = i+1;
        }       
        if(prefix > maxSum){
            maxSum = prefix;
            l = idx;
            r = i;
        }
    }
    vector<int> res;
    if(maxSum != 0) res.push_back(l+1), res.push_back(r+1);
    
    return res;
}
