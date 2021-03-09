/*Find the median of all subarrays of size k*/
// if a[i] is small then we can use the below algorithm

const int maxe = 202;
int f[maxe];

double median(int k) {
	int cnt = 0;
	for (int i = 0; i < maxe; ++i) {
		cnt += f[i];
		if (cnt * 2 > k) return i;
		else if (cnt * 2 == k) {
			for (int j = i + 1; ; ++j)
				if (f[j]) return (i + j) / 2.0;
		}
	}
	return -1;
}

vector<double> solve(vector<int> a, int k) {
	int n = a.size();
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		if (i >= k) {
			ans.push_back(median(k));
			f[a[i - k]]--;
		}
		f[a[i]]++;
	}

	return ans;
}
//////////////////////////////////////////////////////////////////
set<int> big, small;

void rebalance() {
	if (small.size() > big.size()) {
		big.insert(*small.rbegin());
		small.erase(--small.end());
	}
	else if (big.size() > small.size()) {
		small.insert(*big.begin());
		big.erase(big.begin());
	}
}

void add(int x) {
	small.insert(x);
	rebalance();
}

void rem(int x) {
	if (small.count(x)) small.erase(small.find(x));
	else big.erase(big.find(x));
	rebalance();
}

double getMedian() {
	if (small.size() == big.size())
		return (*small.rbegin() + *big.begin()) / 2.0;
	else if (small.size() > big.size())
		return (double) * small.rbegin();
	else
		return (double) * big.begin();
}

vector<double> median(vector<int> a, int k) {
	int n = a.size();
	vector<double> res;
	for (int i = 0; i < k - 1; ++i) add(a[i]);
	for (int i = k - 1; i < n; ++i) {
		add(a[i]);
		res.push_back(getMedian());
		rem(a[i - k]);
	}

	return res;
}

///////////////////////////////////////////////
// Approach 1: using big and small set, where big store all the bigger k/2 elements
// and small stores all the lesser k/2 elements, and |size(big) - size(small)| <= 1

double getMedian(set<int> big, set<int> small, int k) {
	if (k & 1)
		return (double) (*small.rbegin() + *big.begin()) / 2;
	else
		return small.size() > big.size() ? (double) * small.rbegin() : (double) * big.begin();
}

vector<double> median(vector<int> a, int k) {
	int n = a.size();
	set<int> big, small;
	vector<double> res;
	for (int i = 0; i < k / 2; ++i) big.insert(a[i]);
	for (int i = k / 2; i < k; ++i) {
		if (a[i] < *big.begin()) {
			small.insert(a[i]);
		}
		else {
			small.insert(*big.begin());
			big.erase(big.begin());
			big.insert(a[i]);
		}
	}

	res.push_back(getMedian(big, small, k));

	for (int i = k; i < n; ++i) {
		// small: [1,2,3,4] big: [7,8,9]
		// if a[i-k] lies in the small set then remove it
		if (a[i - k] <= *small.rbegin()) {
			small.erase(small.find(a[i - k]));

			if (a[i] < *big.begin()) {
				small.insert(a[i]);
			}
			else {
				small.insert(*big.begin());
				big.erase(big.begin());
				big.insert(a[i]);
			}
		}
		else {
			big.erase(big.find(a[i - k]));

			if (a[i] > *small.rbegin()) {
				big.insert(a[i]);
			}
			else {
				big.insert(*small.rbegin());
				small.erase(small.rbegin());
				small.insert(a[i]);
			}
		}

		res.push_back(getMedian(big, small, k));
	}

	return res;
}

// Approach 2
/*Find the median of all subarrays of size k*/

double median(auto &it, bool isOdd) {
	if (isOdd) return (double) * it;
	int a = *it;
	--it;
	int b = *it;
	++it;
	return (a + b) / 2.0;
}

vector<double> getMedian(vector<int> a, int k) {
	int n = a.size();
	vector<double> res;
	multiset<int> st;
	for (int i = 0; i < k; ++i)
		st.insert(a[i]);

	auto it = st.begin();
	for (int i = 0; i < k / 2; ++i)
		++it;

	bool isOdd = k & 1;

	res.push_back(median(it, isOdd););

	for (int i = k; i < n; ++i) {
		// remove a[i-k]
		// eg. 1 2 3 4 5, med = 3, it at index 2,
		//  after 1 is removed med = (3+4)/2, it at index 3
		if (a[i - k] < *it)
			++it;
		st.erase(st.find(a[i - k]));
		// insert a[i]
		st.insert(a[i]);

		if (a[i] < *it)
			--it;

		res.push_back(median(it, isOdd));
	}

	return res;
}
////////////////////////////////////////
// inefficient one
multiset<int> st;

double getMedian() {
	int n = st.size();
	double a = *next(st.begin(), n / 2 - 1);
	double b = *next(st.begin(), n / 2);
	if (n & 1) return (double)b;
	return (a + b) / 2.0;
}

vector<double> solve(vector<int> a, int k) {
	vector<double> ans;
	for (int i = 0; i < k; ++i) st.insert(a[i]);
	for (int i = k; i < n; ++i) {
		ans.push_back(getMedian());
		st.erase(st.find(a[i - k]));
		st.insert(a[i]);
	}
	return ans;
}