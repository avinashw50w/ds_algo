/*Given a range [l..r], return the bitwise AND of all the numbers in the range inclusive
IDEA: if the MSB is different in both l and r, then the ans = 0
eg. 6,7,8 -> 110, 111, 1000, here due to 8 all the bits will be set to 0 before index 3
But if MSB is same in both l and r, it means it contributes to the ans, so add 1<<MSB to ans
and subtract 1<<MSB from both l and r
*/

int msbPos(int n) {
    // we need the index not count, so initializing with -1
    int pos = -1;
    while (n) {
        pos++;
        n >>= 1;
    }
    return pos;
}

int rangeBitwiseAND(int l, int r) {
    int res = 0;
    while (l and r) {
        int p1 = msbPos(l);
        int p2 = msbPos(r);
        if (p1 != p2) break;
        int val = 1 << p1;
        res += val;

        l -= val;
        r -= val;
    }
    return res;
}


//another easy method
/*Flip the LSB of b.
And check if the new number is in range(a < number < b) or not
if the number greater than 'a' again flip lsb
if it is not then that's the answer*/
int rangeBitwiseAND(int l, int r) {
    while (l < r) {
        r = r & -r;
    }
    return r;
}
