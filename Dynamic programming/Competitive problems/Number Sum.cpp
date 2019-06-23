/*Alice is given an array of N integers. Now, she is playing a game with Bob. In one turn 
Alice picks a sub-array of the given array A. In every turn, she picks a new subarray i.e. 
one with either different starting index or different ending index from the subarrays picked before.

Now, Bob starts shouting the natural numbers from beginning i.e. he first says  then  and so on. Alice stops him at the first integer which does not appear in the subarray that she has picked in this turn. Later on, she asks Bob to write the sum of all the values in which she stops him on a paper. Bob is weak in maths, can you help him?

Note: Please go through the sample carefully.

Input Format

The first line contains a single integer N. The next line contains N space-separated integers, 
where the i-th integer denotes A[i].

Output Format

Print the single integer representing the required result.

Constraints
 1 <= N <= 5000
 1 <= A[i] <= 10^9

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 2;

int main() {
    int n; cin >> n;
    int a[n];
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    int f[maxn];
    ll ans = 0;
    
    for (int i = 0; i < n; ++i) {
        memset(f, 0, sizeof(f));
        int start = 1;
        for (int j = i; j < n; ++j) {
            if (a[j] < maxn) f[a[j]]++;
            
            while (f[start]) start++;
            
            ans += start;
        }
    }
    
    cout << ans << endl;
}