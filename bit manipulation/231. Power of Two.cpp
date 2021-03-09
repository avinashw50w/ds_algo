//Given an integer, write a function to determine if it is a power of two.
//edge case : n = 0 and n > interger range
bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    return ((ll) n & ((ll) n - 1)) == 0;
}