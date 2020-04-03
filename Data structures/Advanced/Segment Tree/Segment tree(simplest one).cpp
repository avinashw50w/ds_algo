#include <bits/stdc++.h>
using namespace std;

// NOTE : does not use it in questions where the value of the parent depends on the 
// order of the values of its children. that is, use only when the operation is 
// commutative eg ( +, - , max, min,.... )

const int MAXN = 1e5;
int n;
int a[2 * MAXN];
//  for range sum queries //
void build() {
	for(int i = n-1; i > 0; --i) a[i] = a[i<<1] + a[(i<<1)|1];
}

void modify(int i, int val) {
	for(a[i += n] = val; i > 1; i >>= 1) a[i>>1] = a[i] + a[i^1];
}

// gives sum of values in the range [a,b)
// to get query int the range [a,b] , change r+=n to r+=(n+1)
int query(int l, int r) {
	int res = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1) res += a[l++];
		if(r&1) res += a[--r];
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", (a + n + i));

	build();

	modify(0, 2);

	printf("%d\n", query(0,5));

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////

/*Some people begin to struggle and invent something too complex when the operations are inverted, for example:
1.add a value to all elements in some interval;
2.compute an element at some position.
But all we need to do in this case is to switch the code in methods modify and query as follows:*/
// note : does not include build function in range modifications problems

void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) tree[l++] += value;
    if (r&1) tree[--r] += value;
  }
}

int query(int i) {
  int res = 0;
  for (i += n; i > 0; i >>= 1) res += tree[i];
  return res;
}

/*If at some point after modifications we need to inspect all the elements in the array, we can push all the modifications to the leaves 
using the following code. After that we can just traverse elements starting with index n. This way we reduce the complexity from O(nlog(n)) to O(n) 
similarly to using build instead of n modifications.*/

void push() {
  for (int i = 1; i < n; ++i) {
    t[i<<1] += t[i];
    t[i<<1|1] += t[i];
    t[i] = 0;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// for range max/min queries //

const int MAXN = 50505;
const int oo = (1<<30);
int n, q;
int t[2*MAXN];


void build() {
	for(int i=n-1; i>0; --i) t[i] = max(t[i<<1], t[(i<<1)|1]);
}

void update(int i, val) {
	for(t[i+=n]=val; i>1; i>>=1) t[i>>1] = max(t[i], t[i^1]);
}

int query(int l ,int r) {
	int mx = -oo;
	for(l+=n,r+=n+1; l<r; l>>=1,r>>=1) {
		if(l&1) mx = max(mx, t[l++]);
		if(r&1) mx = max(mx, t[--r]);
	}

	return mx;
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;++i) {
		scanf("%d",(t+n+i));
	}

	build();
	
	scanf("%d",&q);
	cout << query(0, 3);
}
