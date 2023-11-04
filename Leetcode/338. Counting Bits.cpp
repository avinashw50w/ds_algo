/*Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

/*
        1 - 1
        2 - 1
        3 - 2
        4 - 1
        5 - 2
        6 - 2
        7 - 3
        8 - 1
        9 - 2
        10 - 2
        11 - 3
        12 - 2
        13 - 3
        14 - 3
        15 - 4
        16 - 1
*/
/*every power of 2 has only a single bit on. Other numbers can be written 
as n = 2^m + x. So no of on bits in the binary representation of 
n = 1 + no of bits in x. 8 = 2^3 + 0, 9 = 2^3 + 1, 10 = 2^3 + 2*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1);
        int p = 1, pp = 1;
        
        for (int i = 1; i <= num; ++i) {
            if (i == pp) {
                result[i] = 1;
                pp <<= 1;
                p = 1;
            }
            else {
                result[i] = result[p] + 1;
                ++p;
            }
        }
        
        return result;
    }
};