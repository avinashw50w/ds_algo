/*Sort elements by frequency | Set 2
3.7
Given an array of integers, sort the array according to frequency of elements.
For example, if the input array is {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12},
then modify the array to {3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5}.*/

void sortByFrequency(vector<int> &A) {
	map<int, int> f;

	for (int e : A) f[e]++;

	int k = 0;
	for (auto [e, cnt] : f) {
		for (int i = 0; i < cnt; ++i) A[k++] = e;
	}

	return A;
}

int main() {
	vector<int> a = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
	sortByFrequency(a);
	for (int e : a) cout << e << " ";
}