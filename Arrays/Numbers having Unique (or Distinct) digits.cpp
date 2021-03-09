/*Given a range, print all numbers having unique digits.

Examples :

Input : 10 20
Output : 10 12 13 14 15 16 17 18 19 20  (Except 11)

Input : 1 10
Output : 1 2 3 4 5 6 7 8 9 10*/

vector<int> unique(int l, int r) {
	vector<int> res;


	for (int i = l; i <= r; ++i) {
		vector<int> vis(10);
		int n = i;
		while (n) {
			if (vis[n % 10]) break;
			vis[n % 10]++;
			n /= 10;
		}
		if (n == 0) res.push_back(i);
	}

	return res;
}