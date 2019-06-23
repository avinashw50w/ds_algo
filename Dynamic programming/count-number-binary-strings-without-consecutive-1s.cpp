/*Count number of binary strings without consecutive 1’s
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Examples:

Input:  N = 2
Output: 3
// The 3 strings are 00, 01, 10

Input: N = 3
Output: 5
// The 5 strings are 000, 001, 010, 100, 101
This problem can be solved using Dynamic Programming. Let a[i] be the number of binary strings of length i which 
do not contain any two consecutive 1’s and which end in 0. Similarly, let b[i] be the number of such strings 
which end in 1. We can append either 0 or 1 to a string ending in 0, but we can only append 0 to a string ending in 1.
This yields the recurrence relation:

a[i] = a[i - 1] + b[i - 1]
b[i] = a[i - 1] 
To get a string of length n:
Case 1: we can append 0 to any n-1 length sequence
Case 2: we can append 01 to any n-2 length sequence 
This leads to the recurrence relation : F(n) = F(n-1) + F(n-2)
This is simply the fibonacci sequence with offset of 1 because here F(1) is 2  */

int countStrings(int n)
{
    int a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n-1] + b[n-1];
}

// Space Optimized

int countStrings2(int n) {
	int a, b;
	a = b = 1;
	for (int i = 1; i < n; ++i) {
		int tmp = a;
		a = a + b;
		b = tmp;
	}

	return a + b;
}
