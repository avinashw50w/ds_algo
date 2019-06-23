/*Given two strings check which string makes a palindrome first
Given two strings ‘A’ and ‘B’ of equal length. Two players play a game where they both pick a character from their respective strings (First picks from A and second from B) and put into a third string (which is initially empty). The player that can make the third string palindrome, is winner. If first player makes palindrome first then print ‘A’, else ‘B’. If strings get empty and no one is able to make a palindrome, then print ‘B’.
Examples:

Input : A = ab
        B = ab
Output : B
First player puts 'a' (from string A)
Second player puts 'a' (from string B) 
which make palindrome. 
The result would be same even if A picks
'b' as first character.

Input : A = aba
        B = cde
Output : A

Input : A = ab
        B = cd
Output : B
None of the string will be able to
make a palindrome (of length > 1)
in any situation. So B will win.

After taking few examples, we can observe that ‘A’ (or first player) can only win when it has a character that appears more than once and not present in ‘B’.*/

const int MAX_CHAR = 26; 
  
// returns winner of two strings 
char stringPalindrome(string A, string B) 
{ 
    // Count frequencies of characters in 
    // both given strings 
    int countA[MAX_CHAR] = {0}; 
    int countB[MAX_CHAR] = {0}; 
    int l1 = A.length(), l2 = B.length(); 
    for(int i=0; i<l1;i++) 
        countA[A[i]-'a']++; 
    for(int i=0; i<l2;i++) 
        countB[B[i]-'a']++; 
  
    // Check if there is a character that 
    // appears more than once in A and does 
    // not appear in B 
    for (int i=0 ;i <26;i++) 
        if ((countA[i] >1 && countB[i] == 0)) 
           return 'A'; 
  
    return 'B'; 
} 
  