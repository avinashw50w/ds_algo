

#include <bits/stdc++.h>
using namespace std;

int main() {
	string p, q;

	int t; cin >> t;

	while(t--) {
		cin >> p >> q;

		if(p == q) {
			cout << "YES\n";
			continue;
		}

		int len = p.length();
		int a[1000] = {0}, i = 1, j = 0;

		while(j < len and i <= 26) {
			if(a[j] == 0) {
				a[j] = i;

				for(int k = j+1; k < len; ++k) {
					if(p[k] == p[j]) {
						a[k] = i;
					}
				}

				i++;
			}

			j++;
		}

		len = q.length(), i = 1, j = 0;
		int b[1000] = {0};

		while(j < len and i <= 26) {
			if(a[j] == 0) {
				a[j] = i;

				for(int k = j+1; k < len; ++k) {
					if(q[k] == q[j]) {
						b[k] = i;
					}
				}
				i++;
			}
			j++;
		}

		i = 0;
		while(i < len and a[i] == b[i]) i++;

		if(i == len) cout << "YES\n";
		else cout << "NO\n"; 
	}
}