/*Given a array A with N elements and array B with M elements. You have to insert (N-M) 
zeroes in between array B such that the dot product of array A and array B is maximum. 

Definition of Dot Product : A.B = A[0]*B[0] + A[1]*B[1]+....A[N]*B[N].*/

#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<b;++i)
#define ll uint64_t
const ll INF = (ll)1e21;
int N, M;
ll A[1010], B[1010], dp[1005][1005];

ll solve(int i, int j)
{
    if(i==N && j==M) return 0;
    else if(i==N || j==M) return -INF;
    if(dp[i][j] != -1) return dp[i][j];
    ll ans = A[i]*B[j];
    return dp[i][j] = max(ans+solve(i+1,j+1), solve(i+1,j));
}

int main() {
	int T;
	
	cin>>T;
	while(T--) {
	    cin>>N>>M;
	    REP(i, 0, N) cin>>A[i];
	    REP(i, 0, M) cin>>B[i];

	 	memset(dp, -1, sizeof dp);
	    cout << solve(0, 0) << endl;
	}
	return 0;
}