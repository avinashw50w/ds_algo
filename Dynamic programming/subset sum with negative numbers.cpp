/* Given an array containing both positive and negative numbers, find the subsets whose sum is equal to x. */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void print(int arr[], int sz, int k) 
{
	int idx = 0;

	while(k > 0) {
		if(k & 1) cout << arr[idx] << " ";
		idx++;
		k >>= 1;
	}
	cout << endl;
}

// itetative
// iterate over all the subsets
void solve(int arr[], int sz, int x)
{
	int n = (1ll << sz);

	for (int i = 1; i < n; ++i) {
		int k = i, idx = 0, sum = 0;

		while(k > 0) {
			if(k & 1) sum += arr[idx];
			idx++;
			k >>= 1;
		}

		if(sum == x) print(arr, sz, i);
	}
}

// recursive
void solveRec(int arr[], int sz, int i, int sum, int x, vector<int> buff, vector<vector<int>> &subsets) {

	if(i == sz) {
		if(sum == x and buff.size()) {
			subsets.push_back(buff);
		}
		return;
	}

	if(sum == x) {
		if(buff.size()) subsets.push_back(buff);
	}

	sum += arr[i];
	buff.push_back(arr[i]);

	solveRec(arr, sz, i+1, sum, x, buff, subsets);


	sum -= arr[i];
	buff.pop_back();

	solveRec(arr, sz, i+1, sum, x, buff, subsets);
}

int main()
{
	int arr[] = { 2, 1, -1, 0, 2, -1, -1 };
	int sz = sizeof(arr)/sizeof(arr[0]);

	int x = 0;

	// iterative
	solve(arr, sz, x);

	// recursive
	vector<int> buff;
	vector<vector<int>> ans;

	solveRec(arr, sz, 0, 0, x, buff, ans);

	for(auto v: ans) {
		for(auto i: v) cout << i << " ";
		cout << endl;
	}
}