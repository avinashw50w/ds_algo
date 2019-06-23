
int search(int a[], int l, int r) {

	while (l <= r) {
		int mid = (l+r)>>1;
		if (a[mid] == mid) return mid;

		if(a[mid] < mid) return search(a, mid+1, r);
		else return search(a, l, mid-1);
	}
}