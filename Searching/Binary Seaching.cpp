// seaching the first occurence of an element >= k //

int first(int a[], int n, int k) {
	int l = 1, r = n;
	while(l <= r) {
		int mid = (l+r)>>1;
		if(a[mid] >= k && (mid == l || a[mid-1] < k)) return mid;
		if(a[mid] < k) l = mid+1;
		else if(a[mid] > k) r = mid-1;
	}
	return -1;
} 


// seaching the last occurence of an element >= k //

int last(int a[], int n, int k) {
	int l = 1, r = n;
	while(l <= r) {
		int mid = (l+r)>>1;
		if(a[mid] >= k && (mid == r || a[mid+1] > k)) return mid;
		if(a[mid] < k) l = mid+1;
		else if(a[mid] > k) r = mid-1;
	}
	return -1;
} 
