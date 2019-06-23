/*Offline RMQ (range minimum query) in O(α(n)) on average / Arpa's trick
We are given an array a[] and we have to compute some minima in given segments of the array.

The idea to solve this problem with DSU is the following: We will iterate over the array and 
when we are at the ith element we will answer all queries (L, R) with R == i. 
To do this efficiently we will keep a DSU using the first i elements with the following structure: 
the parent of an element is the next smaller element to the right of it. 
Then using this structure the answer to a query will be the a[find_set(L)], the smallest number to the right of L.

This approach obviously only works offline, i.e. if we know all queries beforehand.

It is easy to see that we can apply path compression. And we can also use Union by rank, 
if we store the actual leader in an separate array.*/

struct Query {
	int idx, L, R;
};

const int MAXN = 1000;
vector<int> ans;
vector<Query> container[MAXN]; // container[i] contains all queries with R == i.
int a[MAXN], parent[MAXN], N;

void init() {
	
	cin >> N;

	for(int i = 0; i < N; ++i) cin >> a[i];

	int L, R, Q;
	cin >> Q;
	
	for(int i = 0; i < Q; ++i) {
		cin >> L >> R;
		container[R].push_back({i, L, R});
	}
}

int findSet(v) {
	if(v == parent[v]) return v;
	return parent[v] = findSet(parent[v]);
}

void solve() {

	init();
	
	stack<int> s;

	for(int i = 0; i < N; ++i) {
		while(!s.empty && a[s.top()] > a[i]) {
			parent[s.top()] = i;
			s.pop();
		}

		s.push(i);

		for(Query q: container) {
			ans[q.idx] = a[findSet(q.L)];
		}
	}
}

