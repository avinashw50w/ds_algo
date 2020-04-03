/* For Point updates and range queries */

const int MAXN = 1e5+5;
int N, BIT[MAXN], A[MAXN];

void update(int i, int val) {
	for( ; i <= N; i += i&-i )
		BIT[i] += val;
}

int prefixSum(int i) {
	int sum = 0;
	for( ; i > 0; i -= i&-i)
		sum += BIT[i];

	return sum;
}

int range_query(int a, int b) {
	return prefixSum(b) - prefixSum(a-1);
}

int main() {
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		cin >> A[i];
		update(i, A[i]);
	}

	int Query; cin >> Query;
	while(Query--) {
		int a, b;
		cin >> a >> b;
		cout << range_query(a, b);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////
/* For Range updates and point queries*/

void update(int i, int val){
	for(; i<=N; i+=i&-i) BIT[i] += val;
}

void Range_update(int l, int r, int val){
	update(l, val);
	update(r+1, -val);
}

int query(int i) {
	int ret = 0;
	for(; i>0; i-=i&-i) ret += BIT[i];
	return ret;
}

/*Explanation: update(p, v) will affect all p’ >= p. To limit the effect to a given range [a…b], 
we subtract -v from all p’ > b by performing the operation update(b+1, -v).*/

/////////////////////////////////////////////////////////////////////////////////////////
/*Range update and range query */
/*Given an array A of N numbers, we need to support adding a value v to each element A[a…b] 
and querying the sum of numbers A[a…b], both operations in O(log N). This can be done by using two BITs B1[N+1], B2[N+1].*/

void update(int *BIT, int i, int val){
	for(; i<=N; i+=i&-i) BIT[i] += val;
}

int query(int *BIT, int i) {
	int ret = 0;
	for(; i>0; i-=i&-i) ret += BIT[i];
	return ret;
}

void range_update(int l, int r, int val) {
	update(B1, l, val);
	update(B1, r+1, -val);
	update(B2, l, val*(l-1));
	update(B2, r+1, -val*r);
}

int query_util(int i){
	return query(B1, i) * i - query(B2, i);
}

int range_query(int l, int r) {
	return query_util(r) - query_util(l-1);
}

/*Explanation:
BIT B1 is used like in the earlier case with range updates/point queries such that query(B1, p) gives A[p].

Consider a range update query: Add v to [a…b]. Let all elements initially be 0. Now, Sum(1…p) for different p is as follows:

1 <= p < a : 0
a <= p <= b : v * (p – (a – 1))
b < p <= N : v * (b – (a – 1))
Thus, for a given index p, we can find Sum(1…p) by subtracting a value X from p * Sum(p,p) (Sum(p,p) is the actual value stored at index p) such that

1 <= p < a : Sum(1..p) = 0, X = 0
a <= p <= b : Sum(1…p) = (v * p) – (v * (a-1)), X = v * (a-1)
b < p <= N: Sum(1…p) = (v * b) – (v * (a-1)), X = -(v * b) + (v * (a-1))
To maintain this extra factor X, we use another BIT B2 such that

Add v to [a…b] -> Update(B2, a, v * (a-1)) and Update(B2, b+1, -v * b)
Query(B2, p) gives the value X that must be subtracted from A[p] * p
See problem HORRIBLE which uses this idea.*/
