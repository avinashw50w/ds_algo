/*Copy set bits in a rangeGiven two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. The task is consider set bits of y in range [l, r] and set these bits in x also. Examples :

Input  : x = 10, y = 13, l = 2, r = 3
Output : x = 14
Binary representation of 10 is 1010 and
that of y is 1101. There is one set bit
in y at 3’rd position (in given range).
After we copy this bit to x, x becomes 1110
which is binary representation of 14.

Algo:
1. take a mask of all 1's of length r-l+1
2. shift the mask to the required postion in y
3. take & of mask and y, after this operation the mask will have set bit as that of y
4. take OR of mask and x
*/

void solve(unsigned &x, unsigned y, unsigned l, unsigned r) {
	if (l < 0 or r > 32) return;
	// get mask of length r-l+1
	unsigned mask = (1 << (r - l + 1)) - 1;
	// shift the mask to correct position and & with y
	mask = (mask << (l - 1)) & y;
	x |= mask;
}