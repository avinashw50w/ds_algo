/* calculate the square of a number without using *, / or pow functions*/

int solve(int n) {
	if (n < 0) n = -n;

	int res = 0;
	for (int i = 0; i < n; ++i) res += n;

	return res;
}