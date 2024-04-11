/*Find the median of all subarrays of size k*/

/*Find the median of all subarrays of size k*/

vector<double> getMedian(vector<int> a, int k) {
	vector<int> res;
	multiset<int> window(a.begin(), a.begin() + k);
	//take the iterator to mid position
	auto it = next(window.begin(), (k-1)/2);

	for (int i = k; ; ++i) {
		int median = k & 1 ? *it : min(*it, *next(it));
		res.push_back(median);

		if(i == n) break;

		window.insert(a[i]);
		// If the inserted number is smaller than mid, obviously the iterator must have moved one 
		// position ahead..... which means we should take it one step backwards
		if (a[i] < *it) 
			--it;
		// If the number inserted k steps before is smaller than or equal to the mid, the iterator must 
		// have moved one position backwards, because of which we should move it forward by one.
		if (a[i-k] <= *it)
			++it;

		window.erase(window.lower_bound(a[i-k]));
	}

	return res;
}

////////////////////////////////////////////////////////////////////////
class Solution {

	array<int, 2> med = {-1};
	set<array<int, 2>> big, small;

public:
	void fix() {
		int sz = 1 + small.size() + big.size();
		if (small.size() < (sz - 1) / 2) {
			small.insert(med);
			med = *big.begin();
			big.erase(med);
		} else if (small.size() > (sz - 1) / 2) {
			big.insert(med);
			med = *--small.end();
			small.erase(med);
		}
	}

	void add(array<int, 2> x) {
		if (med[0] == -1) {
			med = x;
			return;
		}
		if (x < med) 
			small.insert(x);
		else
			big.insert(x);

		fix();
	}

	void rem(array<int, 2> x) {
		if (x == med) {
			med = *big.begin();
			big.erase(med);
		}
		else if (x < med)
			small.erase(x);
		else
			big.erase(x);

		fix();
	}

	vector<int> windowMedian(vector<int> a, int k) {
	    // for window of size 1, we just need to print the array
		if (k == 1) {
			for (int i = 0; i < n; ++i) {
				cout << a[i] << " ";
			}
			return 0;
		}

		for (int i = 0; i < k-1; ++i) {
			add({a[i], i});
		}

		vector<int> res;

		for (int i = k-1; i < n; ++i) {
			add({a[i], i});
			res.push_back(med[0]);
			rem({a[i-k+1], i-k+1});
		}
		return res;
	}
}

////////////////////////////////////////////////////////////////
// if a[i] is small then we can use the below algorithm

const int maxe = 202;
int f[maxe];
// median is the position such that the # of elements before it equals the # elements after it
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

// Approach 2

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