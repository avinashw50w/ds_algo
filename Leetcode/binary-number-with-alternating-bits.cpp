/*Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int curr, prev;
        curr = prev = (n & 1);
        n >>= 1;
        while (n) {
            curr = (n & 1);
            n >>= 1;
            if (curr == prev) return false;
            prev = curr;
        }
        
        return true;
    }
};