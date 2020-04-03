/*Given two 32-bit integers, N and M and two bit positions i and j. Set all bits between i and j in N equal to M

eg: N = 1000111100, M = 10101, i = 2, j = 6

output: N = 10001010100 

*/


int convert(int N, int M, int i, int j) {

	// set of all 1's
	int mx = ~0;

	// 1's till j and 0's after j
	int left = mx - ((1 << j) - 1);

	// 1's after position i
	int right = ((1 << i) - 1);

	// all 1's except from position from j to i which are 0's
	int mask = left | right;

	// unset all bits in N from j to i and mask it with M
	return (N & mask) | (m << i);
}