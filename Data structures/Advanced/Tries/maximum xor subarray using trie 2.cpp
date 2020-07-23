#include <iostream>
using namespace std;
#define SIZE 9999999
class trie {
	int n;
	int tree[SIZE][2];
public:
	trie() : n = 1, memset(tree, -1, sizeof(tree)) {}

	void insert(int x) {
		int node = 0;
		for (int i = 31; i >= 0; i--) {
			int next = x & (1 << i);
			if (tree[node][next] == -1)
				tree[node][next] = n++;
			node = tree[node][next];
		}
	}

	int query(int x) {
		int node = 0 , ans = 0;
		for (int i = 31; i >= 0; i--) {
			int next = x & (1 << i);
			bool flag = 1;
			if (tree[node][next ^ 1] == -1) {
				next ^= 1;
				flag = 0;
			}
			if (flag) ans += (1 << i);

			node = tree[node][next ^ 1];
		}
		return ans;
	}
};

int maxSubarrayXOR(int a[], int n) {
	trie t;
	t.insert(0);
	int res = -oo , prefix = 0;
	for (int i = 0; i < n; ++i) {
		prefix ^= a[i];
		t.insert(prefix);
		res = max(res , t.query(prefix));
	}
	return res;
}

int main() {

}

