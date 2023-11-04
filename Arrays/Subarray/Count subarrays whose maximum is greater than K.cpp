/*Given an array of n elements and an integer k. The task is to find the count of the subarray which has a maximum element greater than K.

Examples : 

Input : arr[] = {1, 2, 3} and k = 2.
Output : 3
All the possible subarrays of arr[] are 
{ 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, 
{ 1, 2, 3 }.
Their maximum elements are 1, 2, 3, 2, 3, 3.
There are only 3 maximum elements > 2.

sol: find the count of subarrays whose maximum is <= K. Let the cnt be x 
ans = total subarray - x, where total subarrays  = n*(n+1)/2 
*/

int solve(vector<int> a, int K) {
    int n = a.size();
    int cnt = 0, len = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= K) {
            len++;
            cnt += len;
        } else {
            len = 0;
        }
    }

    return (n*(n+1)/2) - cnt;
}

// another way 
// if a[i] > K, then the # of subarray where a[i] is maximum is (n-i)*(i+1)
int solve(vector<int> a, int K) {
    long long ans = 0 ; 
    int prev = - 1; //prev for keeping track of index of previous element > k; 
    for(int i = 0 ; i < n ; i++ ) { 
       if ( arr [ i ] > k ) { 
          ans += n - i ; //subarrays starting at index i. 
          ans += i - prev - 1 ; //subarrays ending at index i but starting after prev. 
          ans += ( n - i - 1 ) * 1LL * ( i - prev - 1 ) ; //subarrays having index i element in between. 
          prev = i; // updating prev 
       } 
    } 
    return ans; 
}