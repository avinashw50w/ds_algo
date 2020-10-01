/*given an array A of N elements. You are given q queries, each query is of the form: L R,
where L and R are indexes(1 based) of A.
Find for each query, the no of distinct prime factors of all the elements from index L to R.

IDEA: no of distinct prime factors of numbers a and b = no of distinct prime factors of gcd(a,b).*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> A;
int tree[4 * maxn];

void build(int i, int l, int r) {
	if (l == r) {
		tree[i] = a[l];
		return;
	}
	int mid = l + (r - l) / 2;
	int left = i >> 1, right = (i >> 1) | 1;
	build(left, l, mid);
	build((right, mid + 1, r);
	      tree[i] = __gcd(tree[left], tree[right]);
}

void query(int i, int l, int r, int st, int end) {
	if (end < l or r < st) return 0;
	if (st <= l and r <= end) return tree[i];
	int mid = l + (r - l) / 2;
	int left = i >> 1, right = (i >> 1) | 1;
	int q1 = query(left, l, mid, st, end);
	int q2 = query(right, mid + 1, r, st, end);
	return __gcd(q1, q2);
}

int factors(int n) {
	int cnt = 0;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			cnt++;
			while (n % i == 0) n /= i;
		}
	}
	cnt += n > 1;
	return cnt;
}

vector<int> solve() {
	int N; cin >> N;
	for (int &x : A) cin >> x;
	vector<int> ans;

	int Q; cin >> Q;
	while (Q--) {
		int L, R;
		cin >> L >> R;
		L--; R--;
		int cnt = factors(query(1, 0, N - 1, L, R));
		ans.push_back(cnt);
	}
	return ans;
}