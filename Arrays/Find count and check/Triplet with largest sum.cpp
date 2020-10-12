// GIven an array a with n elemets, find any triplet whose sum is maximum
// idea: find the first, second and
void find(vector<int> a) {
	int f = INT_MIN, s = INT_MIN, t = INT_MIN, n = a.size();
	for (int i = 0; i < n; ++i) {
		if (a[i] > f) {
			t = s;
			s = f;
			f = a[i];
		}
		else if (s < a[i] and a[i] < f) {
			t = s;
			s = a[i];
		}
		else if (t < a[i] and a[i] < s) {
			t = a[i];
		}
	}

	cout << f << " " << s << " " << t << "\n";
}