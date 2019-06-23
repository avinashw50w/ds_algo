/*Range queries can be answered in O(1) using sparse table, given there are no updates on the original array.
Idea is to break the range in powers of 2. 
For range sum queries, Let dp[i][j] stores the sum of elements from index i to i + 2^j - 1 */

const int MAXN = 1e5;
const int LOGN = 30;

int A[MAXN], dp[MAXN][LOGN];

// For range sum queries
void init(int A[], int N) 
{

	for(int i = 0; i < N; ++i) dp[i][0] = A[i];

	for(int j = 1; (1 << j) <= N; ++j)
		for(int i = 0; i + (1 << j) <= N; ++i)
			dp[i][j] = dp[i][j-1] + dp[i + (1 << (j-1))][j-1];
}

int query(int L, int R)
{
	int sum = 0;

	for(int j = LOGN; j >= 0; --j)
	{
		if((1 << j) <= (R - L + 1)) // means L + 2^j - 1 <= R
		{
			sum += dp[L][j];
			L += 1 << j;
		}
	}

	return sum;
}

///////////////////////////////////////////////////////////////////
// For range min queries

int log[MAXN+1];

//initialize log values
void initLog()
{
	log[1] = 0;
	for(int i = 2; i <= MAXN; ++i) 
		log[i] = log[i/2] + 1;
}

void init(int A[], int N)
{
	for(int i = 0; i < N; ++i) dp[i][0] = A[i];

	for(int j = 1; (1 << j) <= N; ++j)
		for(int i = 0;  i + (1 << j) <= N; ++i)
			dp[i][j] = min(dp[i][j-1], dp[i + (1 << (j-1))][j-1]);
}

// NOTE :: this implementation will return the min element in the range [L, R]
// for returning the index of the min element in the range use the below implementation
int query(int L, int R)
{
	int j = log[R - L + 1];
	return min(dp[L][j], dp[R - (1 << j) + 1][j]);
}


///////////////////////////////////////////////////////

void init(int A[], int N)
{
	for(int i = 0; i < N; ++i) dp[i][0] = i;

	for(int j = 1; (1 << j) <= N; ++j)
		for(int i = 0; i + (1 << j) <= N; ++i) 
		{
			if(A[dp[i][j-1]] < A[dp[i + (1 << (j-1))][j-1]])
				dp[i][j] = dp[i][j-1];
			else
				dp[i][j] = dp[i + (1 << (j-1))][j-1];
		}
}

int query(int L, int R)
{
	int k = log[R-L+1];

	if(A[dp[L][k]] <= A[dp[R - (1<<k) + 1][k]])
		return A[dp[L][k]];
	else
		return A[dp[R - (1<<k) + 1][k]];
}

