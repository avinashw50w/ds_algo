/*Count total set bits in all numbers from 1 to n
Given a positive integer N, the task is to count the sum of the number of set bits in the binary representation of all the numbers from 1 to N.
*/
// naive method
int solve(int N) {
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		while (i) {
			cnt++;
			i &= (i - 1);
		}
	}
	return cnt;
}

// O(logN) method
/*Observe the pattern
		  A    B 	C 	D   E
0 	:     0    0	0	0	0
1 	:     0    0	0	0	1
2 	:     0    0	0	1	0
3 	:     0    0	0	1	1
4 	:     0    0	1	0	0
5 	:     0    0	1	0	1
6 	:     0    0	1	1	0
7 	:     0    0	1	1	1
8 	:     0    1	0	0	0
9 	:     0    1	0	0	1
10 	:     0    1	0	1	0
11 	:     0    1	0	1	1
12 	:     0    1	1	0	0
13 	:     0    1	1	0	1
14 	:     0    1	1	1	0
15 	:     0    1	1	1	1
16 	:     1    0	0	0	0

Notice that,

Every alternate bits in A are set.
Every 2 alternate bits in B are set.
Every 4 alternate bits in C are set.
Every 8 alternate bits in D are set.
…..
This will keep on repeating for every power of 2.
*/

int solve(int N) {
	N++;

	int cnt = N / 2;
	int p2 = 2;

	while (p2 <= N) {
		// total no of groups of 1's and 0's
		int groups = N / p2;

		// out of all the groups, half of them are groups of 1's
		cnt += (groups / 2) * p2;
		// if no of groups are odd, then the remaining bits are 1's
		// coz the first group is of 0's, 2nd one is of 1's
		// so every even numbered group is of 1's
		cnt += groups & 1 ? N % p2 : 0;

		p2 <<= 1;
	}

	return cnt;
}