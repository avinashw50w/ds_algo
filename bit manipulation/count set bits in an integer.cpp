// method 1
int count(int n) {
	return __builtin_popcount(n);
}

// method 2
int count(int n) {
	int cnt = 0;
	while (n) {
		cnt += n & 1;
		n >> 1;
	}
	return cnt;
}

// method 3
/*Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit.
for example :
10 in binary is 00001010
9 in binary is 00001001
8 in binary is 00001000
7 in binary is 00000111
So doing n & (n-1) removes the rightmost set bit */

int count(int n) {
	int cnt = 0;
	while (n) {
		cnt++;
		n &= (n - 1);
	}
	return cnt;
}