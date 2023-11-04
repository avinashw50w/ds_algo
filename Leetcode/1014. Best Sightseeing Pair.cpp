/*You are given an integer array values where values[i] represents the value of the ith 
sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        // v[i] + v[j] + i - j = (v[i] + i) + (v[j] - j)
        int mxb = values[n-1] - (n-1);
        int ans = INT_MIN;
        for (int i = n-2; i >= 0; --i) {
            ans = max(ans, values[i] + i + mxb);
            mxb = max(mxb, values[i] - i);
        }
        
        return ans;
    }
};