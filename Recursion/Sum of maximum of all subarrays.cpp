/*Find the sum of maximum of all subarrays
idea: an element at index i appears in (i-1) * (n-i) subarrays
so if the element at index i is maximum, then its total contribution will be a[i] * (i-1) * (n-i)

so sum(l, r) = a[i] * (i-1) * (n-i) + sum(l, i - 1) + sum(i + 1, r), where i is the index of the maximum element
we can use either segment tree or bit for finding the maximum in the range (l, r) in logN

Time Complexity: O(NlogN)

NOTE:: there is another optimized way with time complexity O(N) using stack
*/

const int maxn = 1e5;
const int INF = 1e9;
int tree[maxn];
int n;

void buildtree(int node, int l, int r) {
	if (l == r) {
		tree[node] = { a[l], l };
		return;
	}

	int m = l + (r - l) / 2;
	buildtree(node * 2 + 1, l, m);
	buildtree(node * 2 + 2, m + 1, r);
}

pair<int, int> findMax(int l, int r, int node = 0, int st = 0, int end = n - 1) {
	if (end < l or r < st) return { INF, -1 };
	if (l <= st and end <= r) return tree[node];

	int m = l + (r - l) / 2;
	int a = findMax(l, r, node * 2 + 1, st, m);
	int b = findMax(l, r, node * 2 + 2, m + 1, end);
	return max(a, b);
}

int solve(int l, int r) {
	if (l > r) return 0;

	pair<int, int> p = findMax(l, r);

	int val = p.first, i = p.second;
	return val * (i - l + 1) * (r - i + 1)
	       + solve(l, i - 1) + solve(i + 1, r);
}

int main() {
	a = vector<int> {1, 2, 3, 4, 5, 6};
	int n = a.size();
	buildtree(0, 0, n - 1);

	cout << solve(0, n - 1);
}