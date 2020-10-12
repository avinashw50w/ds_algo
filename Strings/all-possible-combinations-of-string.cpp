/*Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them.

Input:  str[] = "ABC"
Output: ABC
        AB C
        A BC
        A B C
*/

void solve(string s, string str, int i) {
    if (i == s.size()) {
        cout << str << " ";
        return;
    }

    str += s[i];
    solve(s, str, i + 1);

    str.pop_back();
    str += ' ';
    str += s[i];
    solve(s, str, i + 1);
}

void printPattern(string s) {
    solve(s, "", 0);
}
