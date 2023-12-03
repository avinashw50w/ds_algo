/*You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] 
represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
You are also given an interval newInterval = [start, end] that represents the start and end of another 
interval.

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
        vector<vector<int>> st;
        // keep pushing intervals into the stack unitl there is no overlap with newInterval,
        // store the index where there is a overlap and break the loop
        int k = -1;
        for (int i = 0; i < intervals.size(); ++i) {
            // if interval[i] doesn't overlap with newInterval
            if (intervals[i][1] < newInterval[0]) {
                st.push_back(intervals[i]);
            } else {
                k = i;
                break;
            }
        }

        if (k == -1) {
            st.push_back(newInterval);
            return st;
        }
        /*
            [....] curr
          [....]   new or
              [.....] new
        */
        
        for (int i = k; i < intervals.size(); ++i) {
            /* the new interval can span across multiple intervals
                    [...] [...] curr
                      [.........] new
             */
            if (intervals[i][0] <= newInterval[1]) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            } else {
                st.push_back(newInterval);
                newInterval = intervals[i];
            }
        }

        st.push_back(newInterval);

        return st;

        return st;
    }
};