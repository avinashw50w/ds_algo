/*Patwari is really good at killing his enemy. His tactics lies in the way he chooses his steps 
while chasing his enemy. And the tactic is that he chooses his steps such that (steps&1 == 1). 
Now he wanted to know in how many ways he can kill his enemy K steps away from him. 
Order in which Patwari makes his steps does matters. Now as Patwari is not good in mathematics, 
he really wants your help to solve this problem! You have to print answer modulo 10^9 + 7

Input Format :

The only line of input contains an integer K (1 <= K <= 10^5)

Output Format :

Output the Number of distinct ways mod 10^9 + 7

SAMPLE INPUT 
5
SAMPLE OUTPUT 
5
Explanation
the 5 ways are :

3 + 1 + 1

1 + 3 + 1

1 + 1 + 3

1 + 1 + 1 + 1 + 1

5*/

/*F(n) = F(n-1) + F(n-2) 
F[0] = F[1] = F[2] = 1
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e5+2;
ll f[maxn];

void init() {
    f[0] = f[1] = f[2] = 1;
    
    for (int i = 3; i < maxn; ++i) f[i] = (f[i-1] + f[i-2]) % mod;
}

int main() {
    init();
    int k; cin >> k;
    
    cout << f[k] << endl;
}