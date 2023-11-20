/*Given a sorted array of size n containing numbers from [1,n+1], find the missing number.
Return -1 if no missing number was found.*/
// find the index where a[i]-1 != i, then ans = i+1
int find (vector<int> a){ 
	int n = a.size(), l = 0, r = n-1;
	if (a[n-1]-1 == n-1) return -1;
	while (l<r) {
		int mid = (l+r)>>1;
		if (a[mid]-1 != mid) r = mid;
		else l = mid+1;
	}
	return l+1;
}


// recursive
bool correct(int i, int n) { return i == (n-1); }


int find(int A[], int L, int R)
{
	if(L > R) return -1;

	if(correct(R, A[R])) {
		cout << "No missing number\n";
		return 0;
	}

	if(L == R) return A[R]-1;

	int mid = (L+R)>>1;

	if(!correct(mid, A[mid])) R = mid;

	else L = mid+1; 

	return find(A, L, R);
}

