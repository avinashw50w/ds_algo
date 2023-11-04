/*Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.*/

int hammingWeight(uint32_t n) {
    return __builtin_popcount(n);
}


////////////////////////////////////////////////////////////////

int hammingWeight(uint32_t n) {
    int cnt = 0;
    for (int i = 0; i < 32; ++i)
        if (n & (1 << i)) cnt++;
    return cnt;
}