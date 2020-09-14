int count(int n) {
	return __builtin_popcount(n);
}

/////////////////////////////
// another method
int count(int n) {
	int cnt = 0;
	while (n) {
		cnt ++;
		n &= (n - 1);
	}
	return cnt;
}