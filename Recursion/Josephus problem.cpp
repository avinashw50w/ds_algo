/*N people are arranged in a circle. Person 1 kills the next kth person and hands over the
knife to the next alive person. The process goes on until only one person is left.
Find the position in the circle so that u are the last man alive if u stand in that position
The problem has following recursive structure.

  josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1
  josephus(1, k) = 1
After the first person (kth from beginning) is killed, n-1 persons are left.
So we call josephus(n – 1, k) to get the position with n-1 persons.
But the position returned by josephus(n – 1, k) will consider the position starting
from k%n + 1. So, we must make adjustments to the position returned by josephus(n – 1, k).
*/

int solve(int n, int k) {
	if (n == 1) return 1;

	return (solve(n - 1, k) + k - 1) % n + 1;
}

// what if k = 1
/* It follows a pattern
 no of people   last person
 	1				1
 	2				1
 	3				3
 	4				1
 	5				3
 	6				5
 	7				7
 	8				1
 	9				3

 Notice that at if no of people are a power of 2, then 1 is the last person, and between the
 powers of 2 the pattern starts with 3 and increases by 2
 if No of people are N, then N = 2^a + l, where 2^a is the highest power of N less than or
 equal to N and l is the remainder
 according to pattern the last person = 2l + 1
 */

int josephus(int n) {
	int p = 1;
	while (2 * p <= n) p *= 2;
	int l = n - p;
	return 2 * l + 1;
}

