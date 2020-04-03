const int MAX = 1e6;
vi g[N];
int a[N];
struct wavelet_tree{
	#define vi vector<int>
	#define pb push_back
	int lo, hi;
	wavelet_tree *l, *r;
	vi b;
 
	//nos are in range [x,y]
	//array indices are [from, to)
	wavelet_tree(int *start, int *end, int x, int y){
		lo = x, hi = y;
		if(lo == hi or start >= end) return;
		int mid = (lo+hi)/2;
		auto f = [mid](int x){
			return x <= mid;
		};
		b.reserve(end-start+1);
		b.pb(0);
		for(auto it = start; it != end; it++)
			b.pb(b.back() + f(*it));
		//see how lambda function is used here	
		auto pivot = stable_partition(start, end, f);
		l = new wavelet_tree(start, pivot, lo, mid);
		r = new wavelet_tree(pivot, end, mid+1, hi);
	}
 
	//kth smallest element in [l, r]
	int kth(int l, int r, int k){
		if(l > r) return 0;
		if(lo == hi) return lo;
		int inLeft = b[r] - b[l-1];
		int lb = b[l-1]; //amt of nos in first (l-1) nos that go in left 
		int rb = b[r]; //amt of nos in first (r) nos that go in left
		if(k <= inLeft) return this->l->kth(lb+1, rb , k);
		return this->r->kth(l-lb, r-rb, k-inLeft);
	}
 
	//count of nos in [l, r] Less than or equal to k
	int LTE(int l, int r, int k) {
		if(l > r or k < lo) return 0;
		if(hi <= k) return r - l + 1;
		int lb = b[l-1], rb = b[r];
		return this->l->LTE(lb+1, rb, k) + this->r->LTE(l-lb, r-rb, k);
	}
 
	//count of nos in [l, r] equal to k
	int count(int l, int r, int k) {
		if(l > r or k < lo or k > hi) return 0;
		if(lo == hi) return r - l + 1;
		int lb = b[l-1], rb = b[r], mid = (lo+hi)/2;
		if(k <= mid) return this->l->count(lb+1, rb, k);
		return this->r->count(l-lb, r-rb, k);
	}
	~wavelet_tree(){
		delete l;
		delete r;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand(time(NULL));
	int i,n,k,j,q,l,r;
	cin >> n;
	fo(i, n) cin >> a[i+1];
	wavelet_tree T(a+1, a+n+1, 1, MAX);
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		cin >> l >> r >> k;
		if(x == 0){
			//kth smallest
			cout << "Kth smallest: ";
			cout << T.kth(l, r, k) << endl;
		}
		if(x == 1){
			//less than or equal to K
			cout << "LTE: ";
			cout << T.LTE(l, r, k) << endl;
		}
		if(x == 2){
			//count occurence of K in [l, r]
			cout << "Occurence of K: ";
			cout << T.count(l, r, k) << endl;
		}
	}
	return 0;
} 