/*print all the permutations of a string in lexicographical order. */

vector<string> solve(string s) {
	vector<string> res;

	sort(s.begin(), s.end());

	do {
		res.push_back(s);
	} while (next_permuation(s.begin(), s.end()));

	return res;
}
///////////////////////////////////
// output: 123 132 213 321
// NOTE: all the permutations will not be distinct if the input contains duplicate characters
// for getting only distinct permutations, use the next_permutation func
// or implement the function if asked by the interviewer
// OR use this function permuteWithoutDuplicates
void permute(string s, int pos, int N) {
    if (pos == N) {
        cout << s << " ";
        return;
    }
    for (int i = pos; i < N; ++i) {
        swap(s[pos], s[i]);
        permute(s, pos + 1, N);
        swap(s[pos], s[i]);
    }
}

////////////////////////////////////////
// output without duplicates
bool check(string s, int l, int r) {
    for (int i = l; i < r; ++i)
        if (s[i] == s[r]) return 0;
    return 1;
}

void permuteWithoutDuplicates(string s, int l) {
    int n = s.length();
    if (l == n) {
        cout << s << " ";
        return;
    }

    for (int i = l; i < n; ++i) {
        // swap s[l] with s[i] only if there are no duplicate characters
        // in the range [l, i-1]
        if (check(s, l, i)) {
            swap(s[l], s[i]);
            permuteWithoutDuplicates(s, l + 1);
            swap(s[l], s[i]);
        }
    }
}

/* Driver program to test above functions */
int main()
{
    string s = "123";
    int n = s.size();
    permute(s, 0, n - 1);
    return 0;
}
