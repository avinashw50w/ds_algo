#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e5 + 5;

int tree[MAXN], A[MAXN], lazy[MAXN];

void build(int i, int l, int r){
	if(l == r) {
		tree[i] = A[l];
		return;
	}
	int mid = (l+r)>>1;
	build(2*i,   l,     mid);
	build(2*i+1, mid+1, r);

	tree[i] = max(tree[2*i], tree[2*i+1]);
}



void update_range(int i, int l, int r, int a, int b, int val) {
	if(lazy[i] != 0) {
		tree[i] += lazy[i];
		if(l != r) {
			lazy[2*i]   += lazy[i];
			lazy[2*i+1] += lazy[i];
		}
		lazy[i] = 0;
	}

	if(l > r || b < l || r < a) return; // (a,b) is out of range of (l, r)

	if(a <= l && r <= b) {
		tree[i] += val;
		if(l != r) {
			lazy[2*i]   += val;
			lazy[2*i+1] += val;
		}
		return;
	}
	int mid = (l+r)>>1;

	update_range(2*i,   l,     mid, a, b, val);
	update_range(2*i+1, mid+1, r,   a, b, val);

	tree[i] = max(tree[2*i], tree[2*i+1]);
}



int query_range(int i, int l, int r, int a, int b) {
	if(lazy[i] != 0) {
		tree[i] += lazy[i];
		if(l != r) {
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}
		lazy[i] = 0;
	}

	if(l > r || b < l || r < a) return INT_MIN;

	if(a <= l && r <= b) return tree[i];

	int mid = (l+r)>>1;
	int p = query_range(2*i,   l,     mid, a, b);
	int q = query_range(2*i+1, mid+1, r,   a, b);

	return max(p, q);
}



int main() {
	int N;
	cin>>N;

	for(int i=0;i<N;++i) cin>>A[i];

	build(1, 0, N-1);

	int t, a, b;
	while(cin>>t>>a>>b) {
		if(t==0) update_range(1, 0, N-1, a, b, 1);

		if(t==1) cout<< query_range(1, 0, N-1, a, b) << endl;
	}
}

/*INPUT :
8
33 4 8 9 2 1 5 6
1 0 1
1 1 2
1 2 3
1 3 4
1 0 4


OUTPUT:
33
8
9
9
33

*/