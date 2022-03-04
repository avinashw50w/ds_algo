// using bitmasking
// output for ABC: A B AB C AC BC ABC
void solve(string s) {
    int n = s.size();
    int mask = 1 << n;

    for (int i = 0; i < mask; ++i) {
        string res = "";
        for (int j = 0; j < n; ++j) {
            if (i>>j&1) res += s[j];
        }
        cout << res << endl;
    }
}
//////////////////////////////////
// using backtracking
// output for ABC: A AB ABC AC B BC C
void btrk(string s, string str, int pos) {
    cout << str << " ";
    for (int i = pos; i < s.size(); ++i) {
        str += s[i];
        btrk(s, str, i + 1);
        str.pop_back();
    }
}

void solve(string s) {
    btrk(s, "", 0);
}

int main() {
    string s = "ABC";
    solve(s);
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