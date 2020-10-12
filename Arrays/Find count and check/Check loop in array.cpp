/*Check loop in array according to given constraints
Given an array arr[0..n-1] of positive and negative numbers we need to find if there is a cycle in
array with given rules of movements. If a number at an i index is positive, then move arr[i]%n forward steps,
i.e., next index to visit is (i + arr[i])%n. Conversely, if it’s negative, move backward arr[i]%n steps
i.e., next index to visit is (i – arr[i])%n. Here n is size of array. If value of arr[i]%n is zero,
then it means no move from index i.

Examples:

Input: arr[] = {2, -1, 1, 2, 2}
Output: Yes
Explanation: There is a loop in this array
because 0 moves to 2, 2 moves to 3, and 3
moves to 0.

Input  : arr[] = {1, 1, 1, 1, 1, 1}
Output : Yes
Whole array forms a loop.

Input  : arr[] = {1, 2}
Output : No
We move from 0 to index 1. From index
1, there is no move as 2%n is 0. Note that
n is 2.*/

/*The idea is to form a directed graph of array elements using given set of rules.
While forming the graph we don’t make self loops as value arr[i]%n equals to 0 means no moves.
Finally our task reduces to detecting cycle in a directed graph. For detecting cycle,
we use DFS and in DFS if reach a node which is visited and recursion call stack, we say there is a cycle.*/

const int maxn = 1e5;
vector<int> G[maxn];
int vis[maxn];

bool isCyclic(int u) {
	vis[u] = 1;
	for (int v : G[u]) {
		if ((vis[v] == 0 and isCyclic(v)) or vis[v] == 1) return true;
	}
	vis[v] = 2;
	return false;
}

bool solve(int a[], int n) {

	for (int i = 0; i < n; ++i) {
		if (a[i] > 0 and i != (i + a[i]) % n)
			G[i].push_back((i + a[i]) % n);
		else if (a[i] < 0 and i != (i + a[i] + n) % n)
			G[i].push_back((i + a[i] + n) % n);
	}

	for (int i = 0; i < n; ++i) {
		if (vis[i] == 0 and isCyclic(i)) return true;
	}

	return false;
}
