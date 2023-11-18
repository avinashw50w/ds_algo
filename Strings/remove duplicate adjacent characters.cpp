/*Given a string s, remove the duplicate characters adjacent to each other.
eg. ebaabcccde
output: ede
ebaabcccde -> ebbde -> ede
*/

void solve(string &s) {
    int done = 0;
    while (!done) {
        done = 1;
        string t = s;
        int n = t.size();
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                int len = 1;
                while (i + len < n and s[i] == s[i+len]) len++;
                t = s.substr(0, i) + s.substr(i + len);
                done = 0;
                break;
            }
        }
        s = t;
    }
}

// recursive
void solve(string &s) {
    int n = s.size();
    for (int i = 0; i<n-1; ++i) {
        if (s[i] == s[i+1]) {
            int len = 1;
            while (i + len < n and s[i] == s[i+len]) len++;
            s = s.substr(0, i) + s.substr(i+len);
            solve(s);
        }
    }
}