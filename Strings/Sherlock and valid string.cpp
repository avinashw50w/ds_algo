/*Sherlock considers a string to be valid if all characters of the string appear the same
number of times. It is also valid if he can remove just 1 character at any index in the string,
and the remaining characters will occur the same number of times. Given a string , determine if
it is valid. If so, return YES, otherwise return NO.

IDEA:
1. calculate freq of every char
2. return true if freq of all chars are same
3. Only 1 char should have freq 1 greater than all other chars, or freq of all char are same
    except one char whose freq is 1.
4. So just consider each char and decrease its freq by 1 and then check if freq are equal or not
   if yes: return true, otherwise increase back its freq by 1
5. At last return false.*/

string isValid(string s) {

    vector<int> f(26);
    for (char c : s) f[c - 'a']++;

    set<int> st;
    for (int e : f) if (e) st.insert(e);
    if (st.size() == 1) return "YES";

    for (int i = 0; i < 26; ++i) {
        if (f[i] == 0) continue;

        f[i]--;

        st.clear();
        for (int j = 0; j < 26; ++j) {
            if (f[j]) st.insert(f[j]);
        }

        if (st.size() == 1) return "YES";

        f[i]++;
    }

    return "NO";
}
