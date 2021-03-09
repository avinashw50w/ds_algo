/*Divide two integers without using multiplication, division and mod operator
As every number can be represented in base 2(0 or 1), represent the quotient in binary form by using shift operator as given below :

Determine the most significant bit in the quotient. This can easily be calculated by iterating on the bit position i from 31 to 1.
Find the first bit for which divisor << i is less than dividend and keep updating the ith bit position for which it is true.
Add the result in temp variable for checking the next position such that (temp + (divisor << i) ) is less than dividend.
Return the final answer of quotient after updating with corresponding sign.
*/

int solve(int divident, int divisor) {
	// if any of divident or divisor is -ve then the sign will be -ve
	int sign = (divident < 0) ^ (divisor < 0) ? -1 : 1;

	divident = abs(divident);
	divisor = abs(divisor);

	int quotient = 0, t = 0;

	for (int i = 31; i >= 0; --i) {
		if (t + (divisor << i) <= divident) {
			t += divisor << i;
			quotient |= (1 << i);
		}
	}

	return sign * quotient;
}