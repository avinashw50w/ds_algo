/*Given an integer, write a function to determine if it is a power of three.
1162261467 (3^19) is the largest power of 3 in the integer range (-2^31 2^31)
since 3 is a prime no, so no other number divides 3^19 other than power of 3
so all the powers of 3 : 3^0, 3^1, 3^2, ... 3^318, 3^19 are all divisible by 3^19
*/

bool isPowerOfThree(int n) {
    return n > 0 and 1162261467 % n == 0;
}

