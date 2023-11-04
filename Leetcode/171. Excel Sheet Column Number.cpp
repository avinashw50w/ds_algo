/*Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...*/

int titleToNumber(string s) {
    int res = 0;
    for (char c : s) {
        res = res * 26 + (c - 'A' + 1);
    }

    return res;
}