/*N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.

Example 1:

Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
IDEA: if the ith and i+1th elements are not a pair then swap the i+1th element with the pair
of the ith element
*/
class Solution {
public:
    int minSwapsCouples(vector<int>& a) {
        int n = a.size(), ans = 0;
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) pos[a[i]] = i;
        int cnt = 0;
        for (int i = 0; i < n; i += 2) {
            int pi = a[i] & 1 ? a[i] - 1 : a[i] + 1;
            if (a[i + 1] != pi) swap(a, pos, i+1, pos[pi]), cnt++;
        }
        
        return cnt;
    }
    
    void swap(vector<int> &a, vector<int> &pos, int x, int y) {
        int t = a[x];
        pos[t] = y;
        pos[a[y]] = x;
        a[x] = a[y];
        a[y] = t;
    }
};