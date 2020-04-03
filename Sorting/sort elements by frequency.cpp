/*Sort elements by frequency | Set 2
3.7
Given an array of integers, sort the array according to frequency of elements. 
For example, if the input array is {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12}, 
then modify the array to {3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5}.*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

//bool cmp(const pii& a, const pii& b) { return a.first > b.first; }
auto cmp = [](pii& a, pii& b) { return a.first > b.first; };

void solve(int A[], int N) {
	map<int,int> M;

	for(int i = 0; i < N; ++i) M[A[i]]++;

	vector<pair<int,int>> V;

	for(auto i: M) 
		V.push_back(make_pair(i.second, i.first));

	sort(V.begin(), V.end(), cmp);

	for(auto p: V)
		for(int i = 0; i < p.first; ++i) cout << p.second << " ";
}

int main() {
	int arr[] = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
    int n = sizeof(arr)/sizeof(arr[0]);

    solve(arr, n);
}