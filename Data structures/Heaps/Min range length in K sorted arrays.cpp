/* Given a list of K sorted arrays of size N. 
Find the length of the shortest range which includes atlest one number from each of the list.

eg. [4, 10, 15, 24, 30]
	[0, 9,  12, 20, 43]					     30 32 43		43 30 32 24 22 20 18 15 12 10 9 5 0 4 
	[5, 18, 22, 32, 46]

	ans = 4 and the range is [20, 24]
*/

/*Solution: take one max heap and one min heap.
insert the first number from each of the lists in both the heaps.
Get the top element from both the min and max heap, calculate their difference and update ans with it.
Remove the top element from the min heap and insert the next number which lies next to the removed number in its list.
Keep repeating until all the numbers from atleat one of the list is exhausted.
return ans. 

Solution 2: instead of using heap, use set*/

struct Node {
	int val;
	int r, c;
	Node(val, r, c) {
		this->val = val;
		this->r = r;
		this->c = c;
	}
};

auto cmp = [](Node a, Node b) {
	return a.val > b.val;
}

int findRange(int a[K][N]) {
	priority_queue<int> mx; // max heap
	priority_queue<Node, vector<Node>, cmp> mn; // min heap

	for (int i = 0; i < K; ++i) {
		mx.push(a[i][0]);
		mn.push(Node(a[i][0], i, 1));
	}

	int ans = INT_MAX;

	while(mn.size())
	{
		int maxx = mx.top();
		int minn = mn.top().val;
		int r = mn.top().r;
		int c = mn.top().c;

		int nextNumber = a[r][c];

		ans = min(ans, maxx-minn);

		mn.pop();
		if(c+1 < N)
			mn.push(Node(nextNumber, r, c+1));

		mx.push(nextNumber);
	}

	return ans;
}


/////////////////////////////////////////////////////////////
// using set

struct Node {
	int val, r, c;
	Node(val, r, c) {
		this->val = val;
		this->r = r;
		this->c = c;
	}
};

int findRange(int a[K][N]) {
	set<Node> st;

	for(int i = 0; i < K; ++i)
		st.insert(Node(a[i][0], i, 1));

	int ans = INT_MAX;
	
	while(st.size()) {
		Node top = st.begin();
		Node bottom = st.end();

		int maxx = top->val;
		int minn = bottom->val;
		ans = min(ans, maxx-min);
		int r = top->r;
		int c = top->c;
		int nextNumber = a[r][c];

		st.erase(top);
		if (c+1 < N)
			st.insert(Node(nextNumber, r, c+1));

	}

	return ans;
}
