// check whether a number is a perfect square
/**
 * All natural numbers have either even or odd no of divisors
 * All prime numbers have exactly 2 divisors(1 and the number itsef), which is even
 * All composite numbers have even no of divisors >= 2
 * All perfect squares have odd no of divisors, eg: 4 - 1, 2, 4 | 9 - 1, 3, 9 | 16 - 1, 2, 4, 8, 16
 */

bool check(int n) {
	if (n < 4) return false;
	// find the no of divisors
	int cnt = 0;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			cnt++;
			if (i != n / i) cnt++;
		}
	}
	// no of divisors should be odd
	return cnt & 1;
}