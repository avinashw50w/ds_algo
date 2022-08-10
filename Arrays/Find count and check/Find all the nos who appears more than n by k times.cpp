/*Given an array of size n and a number k, find all elements that appear more than n/k times
Given an array of size n, find all elements in array that appear more than n/k times. For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be [2, 3]. Note that size of array is 8 (or n = 8), so we need to find all elements that appear more than 2 (or 8/4) times.*/

// Approach 1: sorting
void solve(vector<int> a, int k) {
	sort(a.begin(), a.end());
	int n = a.size();
	int i = 0;
	while (i < n) {
		int len = 1;
		while (i + len < n and a[i] == a[i + len]) len++;
		if (len > n / k) cout << a[i] << endl;
		i += len;
	}
}

// Approach 2: Hashing
void solve(vector<int> a, int k) {
	map<int, int> mp;
	int n = a.size();
	for (int e : a) mp[e]++;
	for (auto [e, cnt] : mp)
		if (cnt > n / k)
			cout << e << endl;
}

// Approach 3: use moore's voting algo
// maintain an array of size k which contains element and their count so far
// when the array is full decrement the count of every element by 1
void insert(int x, int k, map<int, int> mp) {
	if (mp.size() < k) {
		mp[x] = 0;
	} else {
		// find an element with count 0 and replace that element with x
		for (auto &p : mp) {
			if (p.second == 0) {
				p.first = x;
				p.second = 1;
				return;
			}
		}
		// if no 0 count element is found then decrement count of every element by 1
		for (auto &p : mp) {
			p.second--;
		}
	}
}

void solve(vector<int> a, int k) {
	int n = a.size();
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		if (mp.count(a[i])) {
			mp[a[i]]++;
		}
		else {
			insert(a[i], k, mp);
		}
	}

	for (auto [e, c] : mp) {
		int cnt = 0;
		for (int x : a)
			cnt += x == e;
		if (cnt > n / k)
			cout << e << endl;
	}
}