/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB   */

    
string Solution::convertToTitle(int A) {
    string res = "";
    
    while(A) {
        res = char((A-1)%26 + 'A') + res;
        A = (A-1)/26;
    }
    
    return res;
}
