/*Given a list of N integers. Return a random sublist of size K of that list such that the indexes must be in increasing order
eg. a[] = 1,2,3,4,5 and K = 3
the function should return any one of these and the appearence of each one of these should be equally probable:
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

vector<int> solve(int a[], int n, int k) {
	unordered_map<int,int> m;
	vector<int> res;

	// get k random no from the array
	for (int i = 0; i <k ; ++i) {
		m[a[rand()%n]]++;
	}
	for (int i = 0; i < n; ++i) {
		if(m[a[i]]) res.push_back(a[i]);
	}

	return res;
}

int main() {
	int A[] = {1,2,3,4,5};

	int n = sizeof(A)/sizeof(A[0]);
	int k = 3;
    vector<int> res = solve(A, n,3);

    for (int i: res) cout << i << " ";

    return 0;

}
