/*Given two lists of intervals, where interval[i] = [start, end]. Each of the list is sorted by start time
and all intervals are pairwise disjoint, ie, there is no overlap between any interval in a list.

Merge the two intervals such that the final interval doesn't have any overlaps
*/

vector<array<int,2>> merge(vector<array<int,2>> intervals1, vector<array<int,2>> intervals2) {
    int n = intervals1.size(), m = intervals2.size();
    vector<array<int,2>> res;
    int i = 0, j = 0;
    while (i < n and j < m) {
        int a = intervals1[i][0], b = intervals1[i][1];
        int c = intervals2[j][0], d = intervals2[j][1];
        /*           overlap          |           no overlap
                a...b    |    a...b   |   a...b         |          a...b
                  c...d  |  c...d     |          c...d  |   c...d
         */
        // overlap
        if ((a<=c and c<=b) or (a<=d and d<=b)) {
            int newStart = min(a,c), newEnd = max(c,d);
            res.push_back({newStart,newEnd});
            i++; j++;
        } else {
            if (b < c) {
                res.push_back(intervals1[i]);
                i++;
            }
            else {
                res.push_back(intervals2[j]);
                j++;
            }
        }
    }

    // find it's implementation in the file named merge overlapping intervals.cpp
    return mergeOverlappingIntervals(res);
}