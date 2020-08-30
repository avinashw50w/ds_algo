#include <iostream>
#include <cstring>
using namespace std;

void solve(string s) {
    int n = s.size();
    int mask = (1 << n) - 1;

    for (int i = 0; i <= mask; ++i) {
        string res = "";
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) res += s[j];
        }
        cout << res << endl;
    }
}
int main() {
    string s = "abc";
    solve(s);
}

////////////////////////////////////

void solve(string s, string res, int idx) {
    if (idx == s.size()) return;

    res += s[idx];
    cout << res << endl;
    solve(s, res, idx + 1);
    res.pop_back();
    solve(s, res, idx + 1);
}

int main() {
    string s = "abc";
    solve(s, "", 0);
}

///////////////////////////////////////

void DoCombine(char in[], char out[], int length, int recursLev, int start)
{
    for (int i = start; i < length; i++) {
        out[recursLev] = in[i];     //Select the current letter
        out[recursLev + 1] = '\0';  //tack on NULL for printf
        printf("%s\n", out);

        if (i < (length - 1))
            DoCombine(in, out, length, recursLev + 1, i + 1);
    }
}

int combine(char inString[])
{
    int length;
    length = strlen(inString);
    char out[length];

    DoCombine(inString, out, length, 0, 0);

    return 1;
}

int main()
{
    combine("abcd");
    return 0;
}