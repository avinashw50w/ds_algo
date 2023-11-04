/*Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Example 1:

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)*/

class Solution {
    static const int maxn = 100000+3;
    bool p[maxn];
    
    void sieve() {
        p[0] = p[1] = true;
        for (int i = 2; i * i < maxn; ++i) {
            if (!p[i]) {
                for (int j = i*i; j < maxn; j += i) p[j] = true;
            }
        }
    }
public:
    int countPrimeSetBits(int L, int R) {
        int cnt = 0;
        sieve();
        
        for (int i = L; i <= R; ++i) {
            int set = __builtin_popcount(i);
            
            if (!p[set]) cnt++;
        }
        
        return cnt;
    }
};

//////////////////////////////////////////////////
// we dont need to calculate the primes till 10^5, because the no of digits in the number upto 2^20 can be at max 20

class Solution {
   bool isPrime(int x) {
        return (x == 2 || x == 3 || x == 5 || x == 7 ||
                x == 11 || x == 13 || x == 17 || x == 19);
   }
public:
    int countPrimeSetBits(int L, int R) {
        int cnt = 0;

        for (int i = L; i <= R; ++i) 
            if (isPrime(i)) cnt++;
        
        return cnt;
    }
};

/////////////////////////////////////////
// different methods to count set bits
/**
 * 1. __builtin_popcount(n)
 *
 * 2. while(n) {
 *         count += n & 1;
 *         n >> 1;
 *     }
 *
 * 3. while(n) {
 *         n &= (n-1);
 *         count++;
 *     }
 */