/*High school student Vasya got a string of length n as a birthday present. This string consists of letters 'a' and 'b' only. 
Vasya denotes beauty of the string as the maximum length of a substring (consecutive subsequence) consisting of equal letters.

Vasya can change no more than k characters of the original string. What is the maximum beauty of the string he can achieve?

Input
The first line of the input contains two integers n and k (1 ≤ n ≤ 100 000, 0 ≤ k ≤ n) — the length of the string and 
the maximum number of characters to change.

The second line contains the string, consisting of letters 'a' and 'b' only.

Output
Print the only integer — the maximum beauty of the string Vasya can achieve by changing no more than k characters.

Examples
inputCopy
4 2
abba
outputCopy
4 */

int N, K;
string s;

int check(string s, int k, int len) {

	int f[2] = {};

	for (int i = 0; i < len; ++i) {
		f[s[i]-'a']++;
	}

	if (k >= min(f[0], f[1])) return 1;

	for (int i = len; i < s.size(); ++i) {
		f[s[i-len]]--;
		f[s[i]]++;
		if (k >= min(f[0], f[1])) return 1;
	}

	return 0;
} 

int main() {

	cin >> N >> K;

	cin >> s;

	int l = 1, r = n, mid;
	int ans = 0;

	while(l <= r) {
		mid = (l + r) >> 1;

		if (check(s, K, mid)) {
			ans = mid;
			l = mid +1;
		}
		else r = mid - 1;
	}

	return ans;
}