/*Iron Man and Captain America start for a mission from Isengard to Middle-Earth. 
There are two different tracks from Isengard to Middle-Earth. Each track has N toll taxes 
where they have to pay and in between they can change track from any toll but for that they 
have to pay extra. By changing track from ith toll of first track one can reach (i+1)th toll 
of second track and vice versa. All you have to calculate is minimum cost required to reach 
from Isengard to Middle-Earth.

Input
The first line of input contains an integer T, the number of Test Cases.
The second line of input contains an integer N, denoting the number of tolls.
The third line of input contains N space separated integers, denoting the amount to pay at ith toll in first track.
The Fourth line of input contains N space separated integers, denoting the amount to pay at ith toll in second track.
The Next line of input contains N-1 space separated integers, denoting the amount to pay on changing track from ith toll of first track to (i+1)th toll in second track.
The Next line of input contains N-1 space separated integers, denoting the amount to pay on changing track from ith toll of second track to (i+1)th toll of first track.

Output
Output of each testcase will consist of a single integer denoting minimum cost required for bike trip from Leh to Ladakh.

Constraints
1 <= T <= 100
1 <= N <= 100000
1 <= Amount to pay at any point <= 100000*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+2;
int dp1[maxn], dp2[maxn], a[maxn], b[maxn], c[maxn], d[maxn];

int main() {
	int t, n;
	cin >> t;

	while (t--) {

		cin >>n;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			dp1[i] = dp2[i] = 0;
		}

		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}

		for (int i = 0; i < n-1; ++i) {
			cin >> c[i];
		}

		for (int i = 0; i < n-1; ++i) {
			cin >> d[i];
		}

		dp1[0] = a[0];
		dp2[0] = b[0];

		for (int i = 1; i < n; ++i) {
			int op1 = a[i] + dp1[i-1];
			int op2 = a[i] + dp2[i-1] + d[i-1];

			dp1[i] = min(op1, op2);

			op1 = b[i] + dp2[i-1];
			op2 = b[i] + dp1[i-1] + c[i-1];

			dp2[i] = min(op1, op2);
		}

		cout << min(dp1[n-1], dp2[n-1]) << endl;
	}
}