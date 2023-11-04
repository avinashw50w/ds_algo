/*Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.*/
class Solution {
public:
    
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i*i <= n; i += 2) if (n % i == 0) return false;
        return true;
    }
    // convert N to string and store the first half into s and the 2nd half into rev
    // now keep incrementing s and check whether (s + reverse(s)) is >= N and is prime,
    // if yes then return true;
    int primePalindrome(int N) {
        if (N == 2 or N == 3 or N == 5 or N == 7) return N;
        if (N == 1) return 2;
        if (N == 4) return 5;
        if (N == 6) return 7;
        if (N <= 11) return 11;
        
        string s = to_string(N);
        int len = s.length();
        
        while (1) {
            s = s.substr(0, (len + 1) / 2 );
            string rev = len & 1 
                ? s.substr(0, s.length() - 1)
                : s.substr(0, s.length());
            
            reverse(rev.begin(), rev.end());
            long long n = stoll(s + rev);

            if (n >= N and isPrime(n)) return n;
            
            if (s[s.length() - 1] < '9') {
                s[s.length() - 1] += 1;
            }
            else {
                long long t = stoll(s) + 1;
                s = to_string(t);
            }
            len = s.length() + rev.length();
        }
        
        return 1;
    }
};