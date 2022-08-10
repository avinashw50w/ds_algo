/*Given an array A your task is to tell at which position the equilibrium first occurs in the array. 
Equilibrium position in an array is a position such that the sum of elements below it is equal to the sum of elements after it.
eg. 1 3 5 2 2  : the equil pt. is 3 (ie. 5)*/

// more efficient one
int solve(int A[], int N) {
	if (N == 1) return 1;
	int rightsum = 0, leftsum = 0;
	
	REP(i, 0, N) rightsum += A[i];
	
	REP(i, 0, N) {
		rightsum -= A[i];
		
		if (leftsum == rightsum) return i;
		
		leftsum += A[i];
	}
	
	return -1;
}

/*Just calculate the prefix sum and check*/

int solve1(int A[], int N) {
    if(N == 1) return 1;
    int P[N];
    P[0] = A[0];
    REP(i, 1, N) P[i] = P[i-1] + A[i];
    
    REP(i, 1, N) 
        if(P[i-1] == P[N-1]-P[i]) 
            return i+1;
    
    return -1;
}

int main() {
	int T, N, A[101];
	cin>>T;
	while(T--) {
	    cin>>N;
	    REP(i, 0, N) cin>>A[i];
	    cout << solve(A, N) << endl;
	}
	return 0;
}
