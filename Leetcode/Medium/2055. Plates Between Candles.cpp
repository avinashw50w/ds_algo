/*There is a long table with a line of plates and candles arranged on top of it. You are given a 0-indexed string s consisting of characters '*' and '|' only, where a '*' represents a plate and a '|' represents a candle.

You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes the substring s[lefti...righti] (inclusive). For each query, you need to find the number of plates between candles that are in the substring. A plate is considered between candles if there is at least one candle to its left and at least one candle to its right in the substring.

For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates between candles in this substring is 2, as each of the two plates has at least one candle in the substring to its left and right.
Return an integer array answer where answer[i] is the answer to the ith query.

sol: similar to subarray sum query 
the # of * in [i, j] = sum[j] - sum[i-1]
the only caveat is the candle |. We have to ignore all those * from i to the nearest | in its 
right and all * from j to its left nearest |.
store the location of the next nearest pipe for each index i
*/

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> leftCandle(n, -1), rightCandle(n, n);
        vector<int> plates(n+1, 0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '|') leftCandle[i] = i;
            else {
                if (i > 0) leftCandle[i] = leftCandle[i-1];
            }
            
            plates[i+1] = (s[i] == '*') + plates[i];
        }
        for (int i = n-1; i >= 0; --i) {
            if (s[i] == '|') rightCandle[i] = i;
            else {
                if (i < n-1) rightCandle[i] = rightCandle[i+1];
            }
        }
        vector<int> res;
        for (auto q: queries) {
            int l = rightCandle[q[0]], r = leftCandle[q[1]];
            if (l > r) res.push_back(0);
            else
                res.push_back(plates[r+1] - plates[l+1]);
        }

        return res;
    }
};