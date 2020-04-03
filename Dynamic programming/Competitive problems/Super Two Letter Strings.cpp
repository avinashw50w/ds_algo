/*Two letter strings are the strings consisting of only two letters "X" and "Y". A string is "super two letter string" if

a) It does not have leading "X" letters.
b) It does not contain P consecutive "X" letters.
Your task is to find total number of Super two letter strings of length N.

Input :

The first line contains the number of test cases T . Each test case consists of two space separated integers - N and P .

Output :

For each test case output total number of Super two letter strings of length N modulo 1000000007(10^9+7).

Constraints :

1 <= T <= 100

1 <= N <= 10^4

1 <= P <= 10

For those who are looking for some simple explanation and simple code here is my approach:
As specified in the question you can't have more or equal to P number of continuous X's. So what can you have at the end of the string is Y i.e. 0 X or 1 to p-1 no of X's. As we can start the string only with Y you know string of length one can end only with Y , so that forms the base case dp[1][0] = 1. And after that every string of length n-1 can end with 0 to p-1 no of X's given that n-1 > p-1. Now to form a string of length n using previous strings of length n-1 you can add X or Y to the end of each string having p-2 or less X's and you can add only Y to the strings ending with p-1 X's as we can't add one more X. So total no of strings formed is sum of the strings ending with 0 X(i.e. ending with Y) or 1 X or so on till p-1 no of X's. And that's the answer. 
I tried my best to explain everything, if still you want some more than you can figure out with below code.Sorry if I was not able to make my points clear.*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4+2;
const ll mod = 1e9+7;

ll dp[maxn];

int main() {
    int t; cin >> t;
    int n, p;
    
    while(t--) {
        cin >> n >> p;
        
        memset(dp, 0, sizeof(dp));
        
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= p and j <= i; ++j) {
                dp[i] += dp[i-j];
                dp[i] %= mod;
            }
        }
        
        cout << dp[n] << endl;
    }
}