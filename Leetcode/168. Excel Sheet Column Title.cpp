/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
    ...
*/
string convertToTitle(int n) {
    string ans = "";
    while (n) {
        char t = (n - 1) % 26 + 'A';
        ans = t + ans;
        n = (n - 1) / 26;
    }

    return ans;
}