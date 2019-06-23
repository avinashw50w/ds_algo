/*Given a list of numbers. Print all its  subsequences of size K */

/*eg. a[] = 1 2 3 4 5   and K = 3
subsequences of size 3 are

1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5 
*/


#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

void solve(int a[], int idx, int k, int n, vi buff, vii &path) {
	if (buff.size() == k) {
		path.push_back(buff);
		return;
	}
	
	for (int i = idx; i < n; ++i) {
		buff.push_back(a[i]);
		solve(a, i+1, k, n, buff, path);
		buff.pop_back();
	}
}

int main() {
	
	int a[] = {1,2,3,4,5};
	int n = sizeof(a)/sizeof(a[0]);
	
	vector<int> buff;
	vector<vector<int>> res;
	solve(a, 0, 3, n, buff, res);
	
	for (auto i: res) {
		for (int j: i) cout << j << " ";
		cout << endl;
	}
}