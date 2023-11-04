/*You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0, n = nums.size();
        while (i < n) {
            int len = 1;
            int l, r;
            l = r = nums[i];
            while (i+len < n and nums[i] + len == nums[i + len]) len++;
            if (i + len - 1 < n) r = nums[i + len - 1];
            string s = to_string(l);
            if (l != r) {
                s += "->" + to_string(r);
            }
            res.push_back(s);
            i += len;
        }
        
        return res;
    }
};