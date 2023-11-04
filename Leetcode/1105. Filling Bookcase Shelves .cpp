/*We have a sequence of books: the i-th book has thickness books[i][0] and height books[i][1].

We want to place these books in order onto bookcase shelves that have total width shelf_width.

We choose some of the books to place on this shelf (such that the sum of their thickness is <= shelf_width), then build another level of shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down.  We repeat this process until there are no more books to place.

Note again that at each step of the above process, the order of the books we place is the same order as the given sequence of books.  For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.

Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.

Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves are 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.

|1|
|    ||    |
|  2 || 3  |
|    ||    |
         | |
|4||5||6||7|*/
/*IDEA: let dp[i] = minimum height after taking i books from start
let the partition be [0..i-1][i..]
if we partition at any point j from [i..n] then dp[j] = min(dp[j], dp[i-1] + h)
where h is the minimum height of books from i to j
*/
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int w = 0, h = 0;
            for (int j = i; j < n; ++j) {
                w += books[j][0];
                if (w > shelf_width) break;
                h = max(h, books[j][1]);
                dp[j+1] = min(dp[j+1], dp[i] + h);
            }
        }
        return dp[n];
    }
};

//////////////////////////////////////////////////////////////////

class Solution {
    const int INF = 1e9;
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        // dp[i] = min height after using i books
        vector<int> dp(n+1, 0);
        
        dp[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            int sum = 0, h = 0;
            dp[i+1] = dp[i] + books[i][1];
            
            for (int j = i; j >= 0; --j) {
                sum += books[j][0];
                
                if (sum > shelf_width) {
                    break;
                }
                
                h = max(h, books[j][1]);
                dp[i+1] = min(dp[i+1], dp[j] + h);
            }
        }
        
        return dp[n];
    }
};