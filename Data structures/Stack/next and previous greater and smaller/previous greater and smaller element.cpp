/*given an array find for each element it's previous greater element on the left side of it*/

vector<int> previousGreater(vector<int> a) {
	int n = a.size();
	vector<int> res(n, -1);
	stack<int> st;

	for (int i = n - 1; i >= 0; --i) {
		while (!st.empty() and a[st.top()] < a[i]) {
			res[st.top()] = i;
			st.pop();
		}

		st.push(i);
	}

	return res;
}

vector<int> previousSmaller(vector<int> a) {
	int n = a.size();
	vector<int> res(n, -1);
	stack<int> st;

	for (int i = n - 1; i >= 0; --i) {
		while (!st.empty() and a[st.top()] > a[i]) {
			res[st.top()] = i;
			st.pop();
		}

		st.push(i);
	}

	return res;
}