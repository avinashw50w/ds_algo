/*Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

IDEA: if the MSB is different in both l and r, then the ans = 0
eg. 6,7,8 -> 110, 111, 1000, here due to 8 all the bits will be set to 0 before index 3
But if MSB is same in both l and r, it means it contributes to the ans, so add 1<<MSB to ans
and subtract 1<<MSB from both l and r*/
class Solution {
public:
    int msbPos(int n) {
        int pos = -1;
        while (n) {
            pos++;
            n >>= 1;
        }
        return pos;
    }
    
    int rangeBitwiseAnd(int l, int r) {
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
};