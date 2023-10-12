/*Given a stream of characters and we have to find first non repeating character each time
a character is inserted to the stream.

Examples:

Input  : a a b c
Output : a -1 b b

Input  : a a c
Output : a -1 c

Input  : a b c a
Output : a a a b

IDEA: utill and unless the first char repeates, it will always be the first non-repeating
character. If it repeates, keep removing chars from the start of the stream which have
repeated till now.
*/

void solve() {
	char c;
	queue<char> q;
	vector<int> f(256, 0);

	while (cin >> c) {
		q.push(c);
		f[c - 'a']++;

		while (!q.empty() and f[q.front() - 'a'] > 1) q.pop();

		cout << (q.empty() ? -1 : q.front()) << " ";
	}
}