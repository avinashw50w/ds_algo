#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, k;

	cin >> k;

	priority_queue<int, vector<int>, greater<int> > Q;

	while (cin >> x) {

		if (Q.size() < k) {
			Q.push(x);
			if (Q.size() == k) cout << "Kth largest element = " << Q.top() << endl;
			else cout << "Not enough elements\n";
		}

		else {
			if (x > Q.top()) {
				Q.pop();
				Q.push(x);
			}

			cout << "Kth largest element = " << Q.top() << endl;
		}
	}
}