/*Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of the only set bit. If there are 0 or more than 1 set bit the answer should be -1. Position of  set bit '1' should be counted starting with 1 from LSB side in binary representation of the number.

Example 1:

Input:
N = 2
Output:
2
Explanation:
2 is represented as "10" in Binary.
As we see there's only one set bit
and it's in Position 2 and thus the
Output 2.

IDEA:
1. only powers of 2 have only one set bit, so check if the no is a power of 2
2. then find the index which is set
Edge case : test for N = 0
*/


int findPosition(int N) {
	if (N == 0) return -1;

	if ((N & (N - 1)) == 0) {
		int index = 0;
		while (N) {
			if (N & 1) return index + 1;
			index++;
			N >>= 1;
		}
	}
	return -1;
}