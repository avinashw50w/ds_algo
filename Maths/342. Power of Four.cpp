// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

class Solution {
    typedef long long ll;
public:
    bool isPowerOfFour(int n) {
        /** 1     4       16      64      256
         2^0      2^2     2^4     2^6     2^8
         1        100     10000   1000000 100000000
         0xAAAAAAAA = 10101010101010101010101010101010
         0x55555555 = 01010101010101010101010101010101
         so the number should be a power of 2 and the only set bits
         should be at positions 0,2,4,6,8
        */
        return n != 0 && (((ll) n & ((ll) n - 1)) == 0) && !(n & 0xAAAAAAAA);
        // return n != 0 && (((ll) n & ((ll) n - 1)) == 0) && !(n & 0x55555555);
    }
};