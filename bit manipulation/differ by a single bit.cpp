/* given two integers, determine whether or not they differ by a single bit. 

eg. gray(0, 1) : true
	gray(1, 2) : false

a 	= 10110111
b 	= 10010111
a^b = 00100000 : power of 2, if a and b differ by a single bit


*/

int fun(int a, int b) {
	int x = a ^ b;

	return (x & (x-1)) == 0;
}