/*You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. 
Your task is to make these two strings equal to each other. You can swap any two characters that 
belong to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.

 

Example 1:

Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: 
Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
Example 2: 

Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: 
Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you can't swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.

IDEA: 
1 swap can resolve 2 pairs in best case
1 swap can resolve 1 pair in worst case
As given in the sample input 1: the unmatched pairs (x,y)(x,y) or (y,x)(y,x) takes 1 swap
but in sample input 2: the unmatched pairs (x,y) and (y,x) takes 2 swaps.
so, simply count the # of unmatched pairs : off_pairs
if off_pairs is odd, then no solution
if off_pairs is even:
    - check whether the unmatched pairs are (x,y)(x,y) or (x,y)(y,x)
    - for this simply count the # of x when there an unmatched pair is found
    - if the x count is even then we need off_pairs/2 swaps cuz (x,y)(x,y) takes 1 swap
    - if the x count is odd then we need off_pairs/2 + 1 swaps cuz (x,y)(y,x) takes 2 swaps
*/
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int off_pairs = 0, x = 0;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                off_pairs++;
                x += s1[i] == 'x';
            }
            
        }
        
        if (off_pairs & 1) return -1;
        if (x % 2 == 0) return off_pairs/2;
        return (off_pairs/2) + 1;
    }
};