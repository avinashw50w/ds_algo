/*given the entry and exit times of guests in a party. Find the time at which there are maximum no of guests.*/

#include <bits/stdc++.h>
using namespace std;

pair<int,int> solve(int start[], int exit[], int n)
{
	int f[1000] = {0};

	for (int i = 0; i < n; ++i) {
		f[start[i]]++;
		f[end[i+1]]--;
	}

	for (int i = 1; i < n; ++i)
		f[i] += f[i-1];

	int mx = 1;
	for (int i = 1; i < n; ++i) {
		if (f[i] > f[mx]) mx = i;
	}

	return make_pair(f[mx], mx);
}

int main()
{
	int start[] = {1, 2, 10, 5, 5};
	int exit[] = {4, 5, 12, 9, 12};

	int n = sizeof(start)/sizeof(start[0]);

	pair<int, int> ans = solve(start, exit, n);
	cout << "Maximum no of guests = " << ans.first << " at time " << ans.second << endl;
}