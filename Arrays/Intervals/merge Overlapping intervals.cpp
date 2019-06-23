/*Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

Algorithm :
1. Sort the intervals based on increasing order of 
    starting time.
2. Push the first interval on to a stack.
3. For each interval do the following
   a. If the current interval does not overlap with the stack 
       top, push it.
   b. If the current interval overlaps with stack top and ending
       time of current interval is more than that of stack top, 
       update stack top with the ending  time of current interval.
4. At the end stack contains the merged intervals. */

struct Interval {
 	int start;
 	int end;
 	Interval() : start(0), end(0) {}
 	Interval(int s, int e) : start(s), end(e) {}
};


static bool comp(const Interval &a, const Interval &b) {
     return a.start < b.start;
 }

vector<Interval> Solution::merge(vector<Interval> &A) {
    int n = A.size();
    if(n == 0) return A;
    
    vector<Interval> res;
    
    sort(A.begin(), A.end(), comp);
    
    res.push_back(A[0]);
    for(int i = 1; i < n; ++i) {
        Interval top = res.back();
        
        if(top.end < A[i].start) res.push_back(A[i]);
        
        else if(top.end < A[i].end) {
            top.end = A[i].end;
            res.pop_back();
            res.push_back(top);
        }
    }
    return res;
    
}
