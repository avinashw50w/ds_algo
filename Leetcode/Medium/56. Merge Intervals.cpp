/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and 
return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool comp(const Interval& a, const Interval& b) { return a.start < b.start; }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 0) return intervals;
        vector<Interval> res;
        
        sort(intervals.begin(), intervals.end(), comp);
        res.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); ++i) {
            Interval top = res.back();
            // if curr interval doesn't overlap with the prev interval then push curr to stack
            if(top.end < intervals[i].start) res.push_back(intervals[i]);
            // else merge the prev interval with the curr and update the prev interval
            else if(top.end < intervals[i].end) {
                top.end = intervals[i].end;
                res.pop_back();
                res.push_back(top);
            }
        }
        return res;
    }
};