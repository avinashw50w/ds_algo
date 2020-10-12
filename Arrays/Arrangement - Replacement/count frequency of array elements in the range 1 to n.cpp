/*Given an array of lenght n having integers 1 to n with some elements being repeated. Find the frequency of all the
numbers from 1 to n INPLACE */

void solve(vector<int> a) {
	int N = a.size();
	/*subtract 1 from each element so that they are in the range 0 to N-1 */
	for (int &x : a) x--;

	/*for each number a[i] add N to the number at index a[i] % N
	 *after this operation the number at index i will be incremented by N*K
	 *where K is the frequency of the number i in the array. */
	for (int i = 0; i < N; ++i) a[a[i] % N] += N;

	/*print the frequency of element i as a[i] / N. */
	/*restore the previous number by doing a[i] = a[i] % N  and finally increment it by 1*/
	for (int i = 0; i < N; ++i) {
		cout << (i + 1) << " : " << a[i] << endl;
		a[i] %= N;
		a[i] += 1;
	}
}
