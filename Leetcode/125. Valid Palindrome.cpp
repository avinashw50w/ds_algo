/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true*/

bool valid(char c) {
    return (('a' <= c and c <= 'z') or ('A' <= c and c <= 'Z')
            or ('0' <= c and c <= '9'));
}

bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (!valid(s[l])) l++;
        else if (!valid(s[r])) r--;
        else if (valid(s[l]) and valid(s[r])) {
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++; r--;
        }
    }

    return true;
}