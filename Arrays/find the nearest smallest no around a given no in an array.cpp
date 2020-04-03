/*find the nearest smallest no around a given no in an array*/
/*Given an array A of n elements, find for each i, the largest j < i such that a[j] < a[i]  */

#include <bits/stdc++.h>
using namespace std;



int main() {
	int a[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 6};
	int n = sizeof(a)/ sizeof(a[0]);
	int l[n+1];
	memset(l, -1, sizeof(l));

	stack<int> s;
	
	for(int i = 0; i < n; ++i) {
		while(!s.empty() and a[s.top()] >= a[i]) s.pop();
		if(!s.empty()) l[i] = s.top();
		s.push(i);
	}
	
	for(int i = 0; i <= n; ++i) cout << l[i] << ", "; // output: -1, 0, 1, 2, 3, 2, 1, 0, 0, 8
}

/*Similary, given an array A of n elements, find for each i, the smallest j > i such that a[j] < a[i]*/

void right(int a[], int n) {
	stack<int> s;
	int r[n+1];
	fill(r, r+n, -1);

	for(int i = n-1; i >= 0; --i) {
		while(!s.empty() and a[s.top()] >= a[i]) s.pop();
		if(!s.empty()) r[i] = s.top();
		s.push(i);
	}

	for(int i = 0; i < n; ++i) cout << r[i] << ", "; // output: -1, 8, 7, 6, 5, 6, 7, 8, -1, -1
}