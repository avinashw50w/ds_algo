/*A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, 
including the bounds if possible.

Example 1:
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]*/

class Solution {
public:
    bool isDriving(int n) {
        int p = n;
        while (p) {
            int t = p % 10;
            if (t == 0 or (n % t)) return false;
            p /= 10;
        }
        
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> ans;
        
        for (int i = left; i <= right; ++i) {
            if (isDriving(i)) ans.push_back(i);
        }
        
        return ans;
    }
};