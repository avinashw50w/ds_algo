// Determine if any 3 integers in an array sum to k(where k can be any number). An element of the array can be used only one time

bool _3Sum(int a[], int N, int K) {

	REP(i, 0, N-2) {

		int l = i+1, r = N-1;

		while(l < r) {
			int sum = a[i]+a[l]+a[r];
			if(sum == K) {
				printf("%d %d %d\n", i, l, r);
				return true;
			}

			else if(sum < k) l++;

			else r--;
		}
	}

	return false;
}

// another variation : Find 3 integers in an array whose sum is closest to 0.

void find(int a[], int N) {

	sort(a, a+N);

	int l, r, x, y, z, sum, mini = INT_MAX;

	REP(i, 0, N-2) {
		
		l = i+1, r = N-1;

		while(l < r) {
			sum = a[i] + a[l] + a[r];

			if(abs(sum) < abs(mini)) {
				mini = sum;
				x = i; y = l; z = r;
			}

			if(sum < 0) l++

			else r--;
		}
	}

	printf("%d %d %d %d\n", mini, i, l, r);
}

// Variation 3:  Find 3 integers in an array whose sum is closest to K.

int Solution::threeSumClosest(vector<int> &A, int K) {

	sort(A.begin(), A.end());

    int l, r, N = A.size();
    int ans = 0, diff = INT_MAX;

    for(int i = 0; i < N-2; ++i){
        l = i+1, r = N-1;
        
        while(l < r) {
            
            int x = A[i] + A[l] + A[r];
            
            if(abs(K-x) < abs(diff)){
                diff = K-x;
                ans = x;
            }
            if(x > K) r--;
            else l++;
        }
    }
    return ans;
}


// variation 4: Determine if any 3 integers in an array sum to 0. Each number can be used multiple times.

bool find(int a[], int N) {

	sort(a, a+N);

	int i, l, r, sum;

	REP(i, 0, N-3) {
		l = i, r = N-1;

		while(l < r) {
			sum = a[i] + a[l] + a[r];

			if(sum == 0) {
				printf("%d %d %d\n", i, l, r);
				return true;
			}

			else if(sum < 0) l++;

			else r--; 
		}
	}
	return false;
}

