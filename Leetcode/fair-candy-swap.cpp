/*Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

 

Example 1:

Input: A = [1,1], B = [2,2]
Output: [1,2]
Example 2:

Input: A = [1,2,5], B = [2,4]
Output: [5,4]*/

/*Intuition

If Alice swaps candy x, she expects some specific quantity of candy y back.

Algorithm
Say Alice and Bob have total candy Sa and Sb respectively.
If Alice gives candy x, and receives candy y, then Bob receives candy xx and gives candy yy. Then, we must have

Sa - x + y = Sb - y + x 
y = x + (Sb - Sa)/2

Our strategy is simple. For every candy xx that Alice has, if Bob has candy y = x + (Sb-Sa)/2
, we return [x, y]. We use a Set structure to check whether Bob has the desired candy y in constant time.*/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int a = 0, b = 0;
        unordered_set<int> stB;
        
        for (int i: A) a += i;
        for (int i: B) b += i, stB.insert(i);
        
        int delta = (b - a) >> 1;
        
        for (int x: A) 
            if (stB.count(x + delta))
                return vector<int>{x, x+delta};
        
        return vector<int>();
    }
};