
/* given north and south points north[] and south[]. find the max number of bridges that can be build joining north and south points
such that no bridge crosses over each other.*/

/* sort the points according to the south points. */
/* find the lis of the north points. */
/* that lis is the answer. */

int solve(int north[], int south[], int N) {
	pair<int,int> p[N];
	REP(i, 0, N) {
		p[i].first = south[i];
		p[i].second = north[i];
	}

	sort(p, p+N);

	int ans = LIS(p);

	return ans;
}

int LIS(pair<int, int> p[]) {
	multiset<int> st;
	multiset<int>::iterator it;

	REP(i, 0, N) {
		st.insert(p[i].second);
		it = st.find(p[i].second);
		it++;
		if(it != st.end()) st.erase(it);
	}

	return st.size();
}