
int Ceil(int a[], int n, int x) {
	if(x <= a[0]) return a[0];
	if(x > a[n-1]) return -1;
	
	int ans, mid, l = 0, r = n-1;
	
	while(l <= r) {
		mid = (l+r)>>1;
		if(x <= a[mid])		// imagine we have to move a[mid] towards x
			ans = mid, r = mid-1;
		else l = mid+1;
	}
	return a[ans];
}

int Floor(int a[], int n, int x) {
	if(x < a[0]) return -1;
	if(x >= a[n-1]) return a[n-1];
	
	int ans, mid, l = 0, r = n-1;
	
	while(l <= r) {
		mid = (l+r)>>1;
		if(a[mid] <= x)		// imagine we have to move a[mid] towards x
			ans = mid, l = mid+1;
		else r = mid-1;
	}
	return a[ans];
}

int main() {
	int a[] = {1,3,5,8,12,14,16};
	int n = sizeof(a)/sizeof(a[0]);

	cout <<Ceil(a, n, 7);
}


//////////////////////////////////////////////////////

int ceilSearch(int a[], int l, int h, int x) {
	
	if(x <= a[l]) return l;
	if(x > a[n-1]) return -1;
	
	int mid = (l+r)>>1;
	
	if(a[mid] == x) return mid;
	
	else if(a[mid] < x) {
		if(mid+1 <= h and a[mid+1] >= x) return mid+1;
		else return ceilSearch(a, mid+1, h, x);
	}
	
	else {
		if(mid-1 >= l and a[mid-1] < x) return mid;
		else return ceilSearch(a, l, mid-1, x);
	}
	
}


