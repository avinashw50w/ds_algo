
void reverse(int a[], int n) {
	int s = 0, e = n-1;

	while (s < e) {
		swap(a[s], a[e]);
		s++; e--;
	}
}