/*Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals. 
Let the intervals be represented as pairs of integers for simplicity. For example, let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8} }. 
The intervals {1,3} and {2,4} overlap with each other, so they should be merged and become {1, 4}. Similarly {5, 7} and {6, 8} should be merged and become {5, 8}*/
/*An efficient approach is to first sort the intervals according to starting time. Once we have the sorted intervals, we can combine all intervals in a linear 
traversal. The idea is, in sorted array of intervals, if interval[i] doesn’t overlap with interval[i-1], then interval[i+1] cannot overlap with interval[i-1] 
because starting time of interval[i+1] must be greater than or equal to interval[i]. Following is the detailed step by step algorithm.

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
#define start first
#define end second
typedef pair<int,int> pii;
pii a[maxn];

bool comp(const pii& a, const pii&b) { return a.start < b.start; }

void fun(pii a[], int n) {
	if(n <= 0) return;

	stack<pii> s;

	sort(a, a+n, comp);

	s.push(a[0]);

	for(int i = 1; i < n; ++i) {
		pii top = s.top();

		if(top.end < a[i].start) s.push(a[i]);

		else if(top.end < a[i].end) {
			top.end = a[i].end;
			s.pop();
			s.push(top);
		}
	}

	while(!s.empty()) {
		cout << s.top() <<" ";
		s.pop();
	}
}