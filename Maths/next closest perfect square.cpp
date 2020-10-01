// given a number n, find the next perfect square > n

int nextPerfectSquare(int n) {
	int x = floor(sqrt(n)) + 1;
	return x * x;
}