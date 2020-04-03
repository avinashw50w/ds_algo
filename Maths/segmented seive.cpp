/*Problems with Simple Sieve:
The Sieve of Eratosthenes looks good, but consider the situation when n is large, the Simple Sieve faces following issues.

An array of size Θ(n) may not fit in memory
The simple Sieve is not cache friendly even for slightly bigger n. The algorithm traverses the array without locality of reference
Segmented Sieve
The idea of segmented sieve is to divide the range [0..n-1] in different segments and compute primes in all segments one by one. This algorithm first uses Simple Sieve to find primes smaller than or equal to √(n). Below are steps used in Segmented Sieve.

Use Simple Sieve to find all primes upto square root of ‘n’ and store these primes in an array “prime[]”. Store the found primes in an array ‘prime[]’.
We need all primes in range [0..n-1]. We divide this range in different segments such that size of every segment is at-most √n
Do following for every segment [low..high]
Create an array mark[high-low+1]. Here we need only O(x) space where x is number of elements in given range.
Iterate through all primes found in step 1. For every prime, mark its multiples in given range [low..high].
In Simple Sieve, we needed O(n) space which may not be feasible for large n. Here we need O(√n) space and we 
process smaller ranges at a time (locality of reference)

Below is C++ implementation of above idea.*/

// C++ program to print print all primes smaller than
// n using segmented sieve
#include <bits/stdc++.h>
using namespace std;
 
void simpleSieve(int limit, vector<int> &prime) {
    bool mark[limit+1] = {};
    for (int p=2; p*p<limit; p++) {
        if (mark[p] == true) {
            for (int i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }

    for (int p=2; p<limit; p++) {
        if (mark[p] == true) {
            prime.push_back(p);
            cout << p << "  ";
        }
    }
}
 
// Prints all prime numbers smaller than 'n'
void segmentedSieve(int n)
{
    // Compute all primes smaller than or equal
    // to square root of n using simple sieve
    int limit = floor(sqrt(n))+1;
    vector<int> prime;  
    simpleSieve(limit, prime); 
 
    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    int low  = limit;
    int high = 2*limit;
 
    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time
    while (low < n)
    {
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < prime.size(); i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
       
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 
        // Numbers which are not marked as false are prime
        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                cout << i << "  ";
 
        // Update low and high for next segment
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
}
 
// Driver program to test above function
int main()
{
    int n = 100;
    cout << "Primes smaller than " << n << ":\n";
    segmentedSieve(n);
    return 0;
}
/*
Output:

Primes smaller than 100:
2 3 5 7 11 13 17 19 23 29 31 37 41
43 47 53 59 61 67 71 73 79 83 89 97 

*/