/*Program for nth Catalan Number, where Catalan number Cn = (2n)!/(n+1)!*n!
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

1) Count the number of expressions containing n pairs of parentheses which are correctly matched.
For n = 3, possible expressions are
((())), ()(()), ()()(), (())(), (()()).

2) Count the number of possible Binary Search Trees with n keys (See this)

3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.

4) The no of handshakes in a round table such that there are no overlapping handshakes
See this for more applications.

The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

Recursive Solution: C(n) = sum(i = 0 to i = n-1) C(i) * C(n-i-1) */

unsigned long int catalan(unsigned int n)
{
    // Base case
    if (n <= 1) return 1;

    // catalan(n) is sum of catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i=0; i<n; i++)
        res += catalan(i)*catalan(n-i-1);

    return res;
}

/* dp solution */

unsigned long int catalanDP(unsigned int n)
{
    // Table to store results of subproblems
    unsigned long int catalan[n+1];
    memset(catalan, 0, sizeof(catalan));

    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;

    // Fill entries in catalan[] using recursive formula
    for (int i=2; i<=n; i++)
    {
        for (int j=0; j<i; j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }

    // Return last entry
    return catalan[n];
}
///////////////////////////////////////////////////////////////////////////////
/*Using Binomial Coefficient Cn = (2n)!/(n+1)!*n!  (2nCn / (n+1))
We can also use the below formula to find nth catalan number in O(n) time.*/

ll nCr(int n, int r) {
	r = min(r, n-r);
	ll res = 1;
	for(int i = 0; i < r; ++i) {
		res *= (n-i);
		res /= (i+1);
	}
	return res;
}

ll catalan(int N) {

	ll C = nCr(2*N, N);

	return C/(N+1);
}
