/*You are given an array A of N positive integer values. A subarray of this array is called 
Odd-Even subarray if the number of odd integers in this subarray is equal to the number  
of even integers in this subarray.

Find the number of Odd-Even subarrays for the given array.

Input Format:
The input consists of two lines.

First line denotes N - size of array.
Second line contains N space separated positive integers denoting the elements of array A.

Output Format:
Print a single integer, denoting the number of Odd-Even subarrays for the given array.*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int N; cin >> N;

	int a[N] = {0};

	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		a[i] = (a[i] & 1) ? -1 : 1;
	}

	ll ans = 0, x = 0;
	map<ll,ll> mp;
	mp[0]++;

	for (int i = 0; i < N; ++i) {
		x += a[i];
		ans += mp[x];
		mp[x]++;
	}

	cout << ans << endl;
}