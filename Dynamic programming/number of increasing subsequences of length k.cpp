/*Given a sequence of N (1 ≤ N ≤ 10,000) integers S1, ..., SN (0 ≤ Si < 100,000), compute the 
number of increasing subsequences of S with length K (1 ≤ K ≤ 50 and K ≤ N); that is, the number 
of K-tuples i1, ..., iK such that 1 ≤ i1 < ... < iK ≤ N and Si1 < ... < SiK.

Input

The first line contains the two integers N and K. The following N lines contain the integers of the sequence in order.

Output

Print a single integer representing the number of increasing subsequences of S of length K, modulo 5,000,000.*/
typedef long long ll;
#define MAXN 100010
#define MOD 5000000

int tree[51][MAXN];
int arr[MAXN];

bool cmp (int a, int b) { return arr[a] < arr[b]; }

int read(int sel, int idx) {
	ll sum = 0;
	while(idx > 0) {
		sum = (sum + tree[sel][idx]) % MOD;
		idx -= (idx & -idx);
	}
	return (int) sum;
}

void update(int sel, int idx, int val) {
	while(idx < MAXN) {
		ll temp = ((ll) tree[sel][idx] + (ll) val) % MOD;
		tree[sel][idx] = (int) temp;
		idx += (idx & -idx);
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	REP(i, n) scanf("%d", &arr[i]);
	
	fill(tree, 0);
	int dp[51];
	
	for(int i=0; i < n; i++) {
		// dp[j] = # of increasing subsequece of length j ending at a[i]
		for(int j=0; j < k-1; j++) 
			dp[j] = read(j, arr[i]);
		// update dp[j] such that it ends with a[i] + 1	
		update(0, arr[i]+1, 1);
		
		for(int j=1; j < k; j++)
			update(j, arr[i]+1, dp[j-1]);
	}
	
	ll cnt = read(k-1, MAXN-1);
	
	printf("%lld\n", cnt);
	return 0;
}