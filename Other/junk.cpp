#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main() {
	int a[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 6};
	int n = sizeof(a)/ sizeof(a[0]);
	int l[10];

	for(int i = 0; i < n; ++i) {
		while(!s.empty() and a[s.top()] >= a[i]) s.pop();
		if(!s.empty()) l[i] = a[s.top()];
		s.push(i);
	}

	for(int i = 0; i < 10; ++i) cout << l[i];
}