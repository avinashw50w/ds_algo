//distinct-binary-strings-of-length-n-with-no-consecutive-1s
/*eg, for n = 2: 00, 01, 10
	  for n = 3: 000, 001, 010, 100, 101 

Let C0[i] : number of strings of length i ending with 0
Let C1[i] : number of strings of length i ending with 1

Now,
C1[i+1] = C0[i]		        , because we can put 1 at the end of only 0 ending strings
C0[i+1] = C0[i] + C1[i] 	, we can put 0 at the end of all strings
*/

int solve(int N) {

	if(N < 1) return 0;
	// when N = 1
	int C0 = 1
	int C1 = 1;

	REP(i, 0, N-1) {
		int tmp = C1;

		C1 = C0;

		C0 = C0 + tmp;
	}

	return C0 + C1;
}