/*1) Create an empty stack.

2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. 
Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ 
is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).

3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.*/

int getMaxArea(int hist[], int n) {
	stack<int> s;
	int area, max_area = 0, top, i = 0;

	while(i < n) {

		if(s.empty() || hist[s.top()] <= hist[i]) 
			s.push(i++);

		else {
			top = s.top();
			s.pop();

			area = hist[top] * (s.empty() ? i : i-1-s.top());

			max_area = max(max_area, area);
		}
	}

	while(!s.empty()) {
		top = s.top();
		s.pop();

		area = hist[top] * (s.empty() ? i : i-1-s.top());

		max_area = max(max_area, max);
	}

	return max_area;
}