/* sum two numbers without using any arithmatic operator. 

eg. 9 + 3 = 12. In binary it is 1001 + 0011.
adding of two single bits is equivalent of xoring them.
(0, 0) => 0
(0, 1) => 1
(1, 0) => 1
(1, 1) => 0

similarly, the carry over after adding two single bits is equivalent to & operation.
since, the carry goes to the left, so we do a left shift of the & of two bits ie (a&b) << 1

so, we have to do this recursively for all the bits of the numbers.
*/

int sum(int a, int b)
{
	if(b == 0) return a;
	int partialSum = a ^ b;
	int carry = (a & b) << 1;

	return sum(partialSum, carry);
}