#include <bits/stdc++.h>
using namespace std;

vector<int> A , B;

int len;

void update(int idx, int val) {
	B[idx/len] = B[idx/len] - A[idx] + val;
	A[idx] = val;
}

int query(l, r) {
	int sum = 0;
	for(int i=l; i<=r; ) {
		if(i % len == 0 && i+len-1 <= r) {
			sum += B[i/len];
			i += len;
		}
		else {
			sum += A[i];
			i++;
		}
	}
	return sum;
}
/*The disadvantage of this implementation is that it unreasonably long division operations (which are known to run significantly 
slower than other operations).Instead, the block numbers can be counted c_land c_rwhere the boundaries are land rrespectively, 
and then making a loop in the blocks c_l + 1by c_r-1separately treating “tails” in the blocks c_l, and c_r. Furthermore, 
in the case of such an implementation c_l = c_rbecomes special and require separate processing:*/

// a better approach //

int query(int l, int r) {
	int sum = 0;
	int cl = l/len,	cr = r/len;
	// if l and r belong to the same block
	if(cl == cr) {
		for(int i=l; i<=r; ++i) sum += A[i];
	}
	else {
		for(int i=l, end=(cl+1)*len-1; i<=end; ++i) sum += A[i];	// sum from l to the end of cl block

		for(int i=cl+1; i<=cr-1; ++i) sum += B[i];	// sum of each block from cl+1 to cr-1

		for(int i=cr*len; i<=r; ++i) sum += A[i];	// sum from starting of cr block to r
	}

	return sum;
}

int main() {
	A = vector<int> {2,5,3,8,9,3,2,4,6,5,4,1};
	int n = A.size();

	int len = (int) sqrt(n + .0) + 1;
	B.assign(len, 0);

	for(int i=0; i<n; ++i) 
		B[i/len] += A[i];

	int l, r;
	while(cin>>l>>r) cout << query(l, r) << endl;

}
