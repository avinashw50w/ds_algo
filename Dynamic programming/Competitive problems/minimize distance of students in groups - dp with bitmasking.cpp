
/*Let (x,y) be the coordinate of a student’s house on a 2-D plane.
There are 2N students and we want to pair them into N groups. Let di be the distance
between the houses of 2 students in group i. Form N groups such that sum(di) over all groups i is minimized.
Constraints: N ≤ 8; 0 ≤ x, y ≤ 1000.*/

const int MAXN = 16;

double dist[MAXN][MAXN], dp[1 << 16];

double solve(int mask, int N) {
	if(dp[mask] > -0.5) return dp[mask];

	if(mask == (1<<N) - 1) return dp[mask] = 0;

	double ret = INT_MAX;
	for (int i = 0; i < N; ++i) {
		if(mask & (1<<i) == 0) {
			for (int j = i+1; j < N; ++i) {
				if(mask & (1<<j) == 0)
					ret = min(ret, dist[i][j] + solve(mask | (1<<i) | (1<<j), N));
				break;
			}
		}
	}

	return dp[mask] = ret;
}


int main() {
	int N; cin>> N;

	N *= 2;

	int x[N], y[N];

	for (int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j) 
			cin >> x[i] >> y[i];

	for (int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j) 
			dist[i][j] = sqrt((double)pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));

	memset(dp, -1, sizeof(dp));

	cout << solve(0, N) << endl;
}