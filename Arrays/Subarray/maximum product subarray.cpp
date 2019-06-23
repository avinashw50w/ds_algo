// if there are no negative numbers //
int maxProdSubarray(vector<int>A){
	int n=A.size();
	int currmax=1, ans=1;
	for(int i=0;i<n;i++){
		currmax *= A[i];
		ans=max(ans,currmax);
		if(currmax==0) currmax=1;
	}
	return ans;
}

// if there are negative nos //
/*The following solution assumes that the given input array always has a positive output. 
The solution works for all cases mentioned above. It doesn’t work for arrays like {0, 0, -20, 0}, {0, 0, 0}.. etc. 
The solution can be easily modified to handle this case.
It is similar to Largest Sum Contiguous Subarray problem. The only thing to note here is, maximum product 
can also be obtained by multiplication of two -ve numbers. 
For example, in array {12, 2, -3, -5, -6, -2}, when we are at element -2, the maximum product is multiplication of, 
minimum product ending with -6 and -2.*/

int maxProdSubarray(int a[], int n) {
	int curr_max = 1, curr_min = 1;
	int max_prod = 1;

	for(int i = 0; i < n; ++i) {
		
		if(a[i] > 0) {
			curr_max *= a[i];
			curr_min = min(curr_min * a[i], 1);
		}

		else if(a[i] == 0) {
			curr_max = curr_min = 1;
		}

		else {
			int tmp = curr_max;
			curr_max = max(curr_min * a[i], 1);
			curr_min = tmp * a[i];
		}

		max_prod = max(max_prod, curr_max);
	}

	return max_prod;
}
