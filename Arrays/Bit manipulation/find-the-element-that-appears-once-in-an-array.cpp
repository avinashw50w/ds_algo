/*Find the element that occurs only once in a given set of integers while all the other numbers occur K times.
Example -
Input : 3 3 3 4
Output: 4

Input : 5 5 4 8 4 5 8 9 4 8
Output: 9 */

/*The idea is to count the set bits in all the given numbers. As we know, all the elements(except one)
occur 3 times so their respective set bits will also occur 3 times. Thus when we take modulus 3 of the
sum of all set bits we will be left with only the bits of that number which occurs once.

The steps of the algorithm are as following:
1: Create countSetBits[] array of size 32(for representing 32 bit integer) where,
   countSetBits[i] represents count of ith set bit of all elements in the input array.
   Initially all elements of countSetBits[] array are 0.
2. Traverse all the elements of the input array to populate countSetBits, by doing step #3 for each of them.
3. Take the element and check for its set bits. If the ith bit is found to be set, then in the countSetBits[]
array increment the count of the element at the index 'i'.*/

int find(int A[], int N, int K) {
	int cnt[32] = {0};

	REP(i, 0, N) {
		REP(j, 0, 32) {
			if (A[i] & (1 << j)) cnt[j]++;
		}
	}


	int ans = 0;
	REP(i, 0, 32) {
		cnt[i] %= K;

		if (cnt[i] == 1) num |= (1 << i);
	}

	return ans;
}