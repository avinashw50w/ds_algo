/*Minimum number of palindromic subsequences to be removed to empty a binary string
Given a binary string, count minimum number of subsequences to be removed to make it an empty string.

Examples:

Input: str[] = "10001"
Output: 1
Since the whole string is palindrome, 
we need only one removal.

Input: str[] = "10001001"
Output: 2
We can remove the middle 1 as first 
removal, after first removal string
becomes 1000001 which is a palindrome.

The problem is simple and can be solved easily using below two facts.
1) If given string is palindrome, we need only one removal.
2) Else we need two removals. Note that every binary string has all 1’s as a subsequence and all 0’s as another subsequence. 
We can remove any of the two subsequences to get a unary string. A unary string is always palindrome.*/

bool isPalindrome(const char *str)
{
    int l = 0, h = strlen(str) - 1;
    while (h > l)
        if (str[l++] != str[h--])
            return false;
 
    return true;
}

int minRemovals(const char *str)
{
   // If string is empty
   if (str[0] == '\0')
      return 0;
 
   // If string is palindrome
   if (isPalindrome(str))
      return 1;
 
   // If string is not palindrome
   return 2;
}