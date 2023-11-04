/*Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
 
Example 1:

Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.*/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        vector<int> b;
        for (int e: a) b.push_back(e);
        sort(b.begin(), b.end());
        vector<int> res;
        
        for (int e: a) {
            int pos = lower_bound(b.begin(), b.end(), e) - b.begin();
            res.push_back(pos + 1);
        }
        return res;
    }
};