#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

double dp[10][10][20];
int N;

double findProb(int x, int y, int steps) {
	if(x<0 or x>=N or y<0 or y>=N) return 0;
	
	if(steps == 0) return dp[x][y][steps] = 1;

	if(dp[x][y][steps] != -1) return dp[x][y][steps];

	double ans = 0.0;

	for(int i = 0; i < 8; ++i) 
		ans += findProb(x+dx[i], y+dy[i], steps-1)/8.0;

	return dp[x][y][steps] = ans;
}
//////////////////////////////////////////////////////////////////////////
// bottom up //
// this is working, but not the above top down approach
double findProbBottomUp(int sx, int sy, int steps) {
	
	for(int x=0; x<N; ++x) 
			for(int y=0; y<N; ++y) dp[x][y][0] = 1;

	for(int i=1; i<=steps; ++i) 
		for(int x=0; x<N; ++x) 
			for(int y=0; y<N; ++y) {
				double prob = 0.0;
				for(int d=0; d<8; ++d) {
					int nx = x+dx[d], ny = y+dy[d];
					if(nx>=0 and nx<N and ny>=0 and ny<N)
						prob += dp[nx][ny][i-1]/8.0;
				}
				dp[x][y][i] = prob;
			}
	return dp[sx][sy][steps];
}

int main() {
	N = 8;

	memset(dp, -1, sizeof(dp));
	cout << findProbBottomUp(0,0,2);
}
