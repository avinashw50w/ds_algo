/**A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.

Sol: need to form the pattern 00..11
at every index i calculate the swaps needed and keep track of the min of the swaps
So, no of swaps at index i such that there are 0's at <= i and 1's at index > i:
no of 1's until index i + (total no of 0's - no of 0's until index i);
**/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int ones = 0, zeroes = 0;
        int swapsSoFar = INT_MAX;
        int onesSoFar = 0, zeroesSoFar = 0;
        
        for (char c: s) 
            if (c == '0') zeroes++;
            else ones++;
        
        for (char c: s) {
            if (c == '0') zeroesSoFar++;
            else onesSoFar++;
            
            swapsSoFar = min(swapsSoFar, onesSoFar + (zeroes - zeroesSoFar));
        }
        
        return min({swapsSoFar, ones, zeroes});
    }
};