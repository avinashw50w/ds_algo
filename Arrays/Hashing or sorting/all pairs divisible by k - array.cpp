/*Given an array on n elements, print 'yes' if the array elements can be divided into pairs whose sum is divisible by k. */

const int maxn = 1e5 + 5;

int A[maxn], N, K;

bool solve(int N, int K)
{
	int f[K] = {0};

	if (N & 1) return false;

	for (int i = 0; i < N; ++i) {
		cin >> A[i];

		f[A[i] % K]++;
	}

	for (int i = 0; i < N; ++i)
	{
		int rem = A[i] % K;

		if (2 * rem == K) {
			if (f[rem] & 1)
				return false;
		}
		else if (rem == 0) {
			if (f[rem] & 1)
				return false;
		}
		else if (f[rem] != f[K - rem])
			return false;
	}

	return true;
}

int main() {
	cin >> N >> K;

	bool ans = solve(N, K);

	puts(ans ? "YES" : "NO");
}
