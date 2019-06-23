/*Bruce becomes very sad when he realises that Harvey is now killing people based on the outcome of
 a coin toss. He also knows that Harvey kills someone only when he remembers Rachel while tossing the coin.

Harvey tosses the coin finite number of times and lists the outcomes. 
In the list if Tails comes three times in a row, He remebers Rachel and kills the other person.

Bruce is sad but wants to focus on positives. so he thinks about the number of ways 
when the other person is  killed for given number of tosses. As he is unable to 
compute desired number he asks you to do so.


First line of the Input contains an integer T denoting the number of testcases. 
Each testcase contains only one integer N denoting the number of times Harvey tosses the coin.


print a single integer denoting the answer%1000000007.

Constraints :

1<= T <= 10^5

1<= N <= 10^18*/

/* F[n] = F[n-1] + F[n-2] + F[n-3] */

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
typedef long long ll;
const ll mod = 1e7 + 7;

void mul(ll a[3][3], ll b[3][3]) {
	ll res[3][3];

	rep(i, 0, 3)
		rep(j, 0, 3) {
			res[i][j] = 0;
			rep(k, 0, 3)
				res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
		}

	rep(i, 0, 3)
		rep(j, 0, 3)
			a[i][j] = res[i][j];
}

ll power(ll a[3][3], ll n) {
	ll M[3][3] = { {1,1,1}, {1,0,0}, {0,1,0} };

	if (n == 1) 
		return (a[0][0] + a[0][1]) % mod;

	power(a, n >> 1);

	mul(a, a);

	if (n & 1) mul(a, M);

	return (a[0][0] + a[0][1]) % mod;
}

ll solve(ll N) {

	ll a[3][3] = { {1,1,1}, {1,0,0}, {0,1,0} };
	
	return power(a, N);
}

int main() {

	int T; 
	cin >> T;
	ll N;

	while (T--) {
		cin >> N;

		cout << solve(N) << endl;
	}
}