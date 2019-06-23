#include <bits/stdc++.h>
using namespace std;
#define LL long long
int tree[200009], n;
// sum query //
void update(int i,int val){
	for(;i<=n;i+=i&-i) a[i] += val;
}

int sum(int i) {
	int ans = -1;
	for(;i>0;i-=i&-i) ans += tree[i];
	return ans; 
}

int query(int a, int b) {
	return sum(b) - sum(a-1);
}

int main() {
	int b[] = {4,5,9,1,2,34,87,12,76};
	n = sizeof(b)/sizeof(b[0]);
	for(int i=0;i<n;++i)
		update(i+1, b[i]);

	cout << query(2, 6);
}

/////////////////////////////////////////////////////////////
////  max query in range (0,i) ////
void update(int i,int val){
	for(;i<=n;i+=i&-i) tree[i] = max(tree[i],val);
}

int query(int i) {
	int ans = INT_MIN;
	for(;i>0;i-=i&-i) ans = max(ans, tree[i]);
	return ans; 
}

///////////////////////////////////////////////////
// min query  in range (0,i) ///

vector<int> tree(100000, INT_MAX);

void update(int i,int val){
	for(;i<=n;i+=i&-i) tree[i] = min(tree[i],val);
}

int query(int i) {
	int ans = INT_MAX;
	for(;i>0;i-=i&-i) ans = min(ans, tree[i]);
	return ans; 
}

