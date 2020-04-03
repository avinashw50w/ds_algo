/*There are  currency denominations in Coderland which are given in the form of an array. The offer from the bank is that the account holder which requests the minimum amount greater than the maximum currency denomination available at the bank which cannot be paid to the account holder will be given a gift. Since you are a customer of this bank, you want to win this gift. Print the number which can get you this prize.

Input Format

The first line of input contains the integer  denoting the number of currency denominations.
The second line of input contains  integers separated by spaces denoting the currency denominations available at the bank.

Output Format

Print the number which denotes the value that can help you avail the Gift voucher.

Constraints
N <= 100
Di <= 10^6
    

NOTE: Consider the bank has an infinite supply of each denomination. If no such number exists, output "Fake Offer!" without quotes.

SAMPLE INPUT 
3
2 6 9
SAMPLE OUTPUT 
Fake Offer!*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    
    int A[N];
    int mx = INT_MIN;
    int dp[2*1000000] = {0};
    
    for (int i = 0; i < N; ++i) cin >> A[i], mx = max(mx, A[i]);
    
    dp[0] = 1;
    
    for (int i = 0; i < N; ++i) {
        for (int j = A[i]; j < 2*1000000; ++j) dp[j] |= dp[j-A[i]];
    }
    
    int ans = -1;
    
    for (int i = mx+1; i < 2*1000000; ++i) if (dp[i] == 0) { ans = i; break; }
    
    if (ans != -1) cout << ans;
    else cout << "Fake Offer!";
    cout << endl;
}