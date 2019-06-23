/*Given an array A of N elements, find the maximum possible sum of a

Contiguous subarray
Non-contiguous (not necessarily contiguous) subarray.
Empty subarrays/subsequences should not be considered.

Input :

First line of the input has an integer T. T cases follow.
Each test case begins with an integer N . In the next line,N integers follow representing the elements of array A.
Output :

Two, space separated, integers denoting the maximum contiguous and non-contiguous subarray. At least one integer should be selected and put into the subarrays
Constraints :

1<=T<=10
1<=N<=10^5
-10^4<=Ai<=10^4
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+2;
int a[maxn];

int main() {
    
    int t, n, x;
    cin >> t;
    
    while (t--) {
        cin >> n;
        
        int mx = -maxn, curr = 0, pos = 0;
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] > 0) pos = 1;
            curr = max(a[i], curr + a[i]);
            mx = max(mx, curr);
        }
        
        if (!pos) {
            x = *max_element(a, a+n);
            cout << x << " " << x;
        }
        else {
            cout << mx << " ";
            x = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] > 0) x += a[i];
            }
            
            cout << x;
        }
        
        cout << endl;
    }
}