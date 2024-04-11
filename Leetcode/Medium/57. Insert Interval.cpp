/*You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] 
represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and 
intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = newInterval[0], r = newInterval[1], sz = intervals.size(), p = 0;
        vector<vector<int>> ans;
// append the intervals before the new intervals first
        while (p < sz && intervals[p][1] < l) ans.push_back(intervals[p++]);
// check if the current position of the original interval overlaps with the new interval, if true, merge them
        if (p < sz && intervals[p][0] <= r) {
          l = min(l, intervals[p][0]);
          while (p < sz && intervals[p][0] <= r) p++;
          r = max(intervals[p - 1][1], r);
      }
      ans.push_back({l, r});
// append the rest of the intervals
      while (p < sz) ans.push_back(intervals[p++]);
      return ans;
  }
};