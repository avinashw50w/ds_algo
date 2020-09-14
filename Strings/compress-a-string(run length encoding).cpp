/*compress a string such that if the consecutive characters are equal then, replace then with a
single character followed by the no of times it appeared.
eg. aabbbcdddd => a2b3c1d4
*/

string runLengthEncode(string s)
{
    int n = s.size();
    int k = 0;
    for (int i = 0; i < n; ++i) {
        int len = 1;
        while (i + len < n and s[i] == s[i + len]) len++;
        string len_str = to_string(len);
        s[k++] = s[i];
        for (char c : len_str) s[k++] = c;
    }

    return s.substr(0, k);
}

int main() {

    char c[] = "aaabbcccc";

    cout << encode(c);
}
