/*Frog steps either 1, 2 or 3 steps to go to top. In how many ways it reaches the top?*/

int main() {
	int t, n;
	cin>>t;
	while(t--) {
	    cin>>n;
	    int dp[n+1];
	    dp[0] = 1;
	    dp[1] = 1;
	    dp[2] = 2;
	    dp[3] = 4;
	    for(int i=4; i<=n; ++i) 
	    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	    
	    cout << dp[n] << endl;
	}
	return 0;
}