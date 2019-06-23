#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;

	cin >> k;

	priority_queue<int, vector<int>, greater<int> > Q;

	while(cin >> n) {

		if(Q.size() < k) {
			Q.push(n);
			if(Q.size() == k) cout << "Kth largest element = " << Q.top() << endl;
			else cout << "Not enough elements\n";
		}

		else {
			if(n > Q.top()) {
				Q.pop();
				Q.push(n);
			}

			cout << "Kth largest element = " << Q.top() << endl;
		}
	}
}