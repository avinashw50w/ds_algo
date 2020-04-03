/*Given a string S of length n, the Z Algorithm produces an array Z where Z[i] is the length of the 
longest substring starting from S[i] which is also a prefix of S, i.e. the maximum k such that S[j] = S[i + j] 
for all 0 ≤ j < k. Note that Z[i] = 0 means that S[0] ≠ S[i]. 
For easier terminology, we will refer to substrings which are also a prefix as prefix-substrings.

Example:
Index            0   1   2   3   4   5   6   7   8   9  10  11 
Text             a   a   b   c   a   a   b   x   a   a   a   z
Z values         X   1   0   0   3   1   0   0   2   2   1   0 

The algorithm relies on a single, crucial invariant. As we iterate over the letters in the string 
(index i from 1 to n - 1), we maintain an interval [L, R] which is the interval with maximum R 
such that 1 ≤ L ≤ i ≤ R and S[L...R] is a prefix-substring (if no such interval exists, just let L = R =  - 1). 
For i = 1, we can simply compute L and R by comparing S[0...] to S[1...]. Moreover, we also get Z[1] during this.

Now suppose we have the correct interval [L, R] for i - 1 and all of the Z values up to i - 1. 
We will compute Z[i] and the new [L, R] by the following steps:
If i > R, then there does not exist a prefix-substring of S that starts before i and ends at or after i. 
If such a substring existed, [L, R] would have been the interval for that substring rather than its current value. 
Thus we "reset" and compute a new [L, R] by comparing S[0...] to S[i...] and get Z[i] at the same time (Z[i] = R - L + 1).
Otherwise, i ≤ R, so the current [L, R] extends at least to i. Let k = i - L. We know that Z[i] ≥ min(Z[k], R - i + 1) 
because S[i...] matches S[k...] for at least R - i + 1 characters (they are in the [L, R] interval which we know 
to be a prefix-substring). Now we have a few more cases to consider.
If Z[k] < R - i + 1, then there is no longer prefix-substring starting at S[i] (or else Z[k] would be larger),
meaning Z[i] = Z[k] and [L, R] stays the same. The latter is true because [L, R] only changes if there is a 
prefix-substring starting at S[i] that extends beyond R, which we know is not the case here.
If Z[k] ≥ R - i + 1, then it is possible for S[i...] to match S[0...] for more than R - i + 1 characters 
(i.e. past position R). Thus we need to update [L, R] by setting L = i and matching from S[R + 1] forward to 
obtain the new R. Again, we get Z[i] during this.The process computes all of the Z values in a 
single pass over the string, so we're done. Correctness is inherent in the algorithm and is pretty intuitively clear.

Analysis
We claim that the algorithm runs in O(n) time, and the argument is straightforward. We never compare characters 
at positions less than R, and every time we match a character R increases by one, 
so there are at most n comparisons there. Lastly, we can only mismatch once for each i 
(it causes R to stop increasing), so that's another at most n comparisons, giving O(n) total.

Code
Simple and short. Note that the optimization L = R = i is used when S[0] ≠ S[i] 
(it doesn't affect the algorithm since at the next iteration i > R regardless).*/

void search(string text, string pattern)
{
    // Create concatenated string "P$T"
    string concat = pattern + "$" + text;
    int l = concat.length();
 
    // Construct Z array
    int Z[l];
    getZarr(concat, Z);
 
    //  now looping through Z array for matching condition
    for (int i = 0; i < l; ++i)
    {
        // if Z[i] (matched region) is equal to pattern
        // length  we got the pattern
        if (Z[i] == pattern.length())
            cout << "Pattern found at index "
                 <<  i - pattern.length() -1 << endl;
    }
}

//  Fills Z array for given string str[]
void getZarr(string str, int Z[])
{
    int n = str.length();
    int L, R, k;
 
    int L = 0, R = 0;
	
	for (int i = 1; i < n; i++) 
	{
  		if (i > R) {
	    	L = R = i;
	    	while (R < n && str[R-L] == str[R]) R++;
	    	Z[i] = R-L; R--;
	  	} 
	  	else 
	  	{
		    int k = i-L;
		    if (Z[k] < R-i+1) Z[i] = Z[k];
		    else 
		    {
		      L = i;
		      while (R < n && str[R-L] == str[R]) R++;
		      Z[i] = R-L; R--;
	    	}
	  	}
	}
}
 
// Driver program
int main()
{
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    search(text, pattern);
    return 0;
}

////////////////////////////////////////////////////////////////////////////
/*Application
One application of the Z Algorithm is for the standard string matching problem of finding matches 
for a pattern T of length m in a string S of length n. We can do this in O(n + m) time by using the 
Z Algorithm on the string T Φ S (that is, concatenating T, Φ, and S) where Φ is a character that matches nothing. 
The indices i with Z[i] = m correspond to matches of T in S.

Lastly, to solve Problem B of Beta Round 93, we simply compute Z for the given string S, then iterate from i to n - 1. 
If Z[i] = n - i then we know the suffix from S[i] is a prefix, and if the largest Z value we've seen so far 
is at least n - i, then we know some string inside also matches that prefix. That gives the result.*/

int maxz = 0, res = 0;
for (int i = 1; i < n; i++) {
  if (z[i] == n-i && maxz >= n-i) { res = n-i; break; }
  maxz = max(maxz, z[i]);
}