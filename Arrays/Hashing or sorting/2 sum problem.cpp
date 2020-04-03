// given an array of integers, find any two numbers whose sum is equal to K

bool _2Sum(int a[], int N, int K) {

	sort(a, a+N);

	int l = 0, r = N-1;

	while(l < r) {

		if(a[l]+a[r] == K) {
			cout << l << " " << r << endl;
			return true;
		}

		else if(a[l]+a[r] < K) l++;
	
		else r--;
	}
	return false;
}
///////////////////////////////////////////////////////////////////////////////////////////
// if asked to implement in O(n) then use hashing

void _2Sum(int a[], int N, int K) {
	int hash[maxn] = {};
	REP(i, 0, N) {
		int tmp = K - a[i];
		if(tmp >= 0 and hash[tmp] == 1)  {
			printf("%d %d\n", a[i], tmp);
			return;
		}
		hash[a[i]] = 1;
	}
}

// Variation 1 : given an array of integers, find any two numbers whose sum is closest to 0

bool fun(int a[], int N) {

	sort(a, a+N);

	int l = 0, r = N-1;

	int sum, x, y, mini = INT_MAX;

	while(l < r) {
		sum = a[l] + a[r];

		if(abs(sum) < abs(mini)) {
			mini = sum;
			x = l;
			y = r;
		}

		if(sum < 0) l++;
		else r--;
	}

	cout << mini <<" "<< l <<" "<< r << endl;
}


