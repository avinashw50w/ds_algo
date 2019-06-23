/*Make largest palindrome by changing at most K-digits
Given a string containing all digits, we need to convert this string to a palindrome by 
changing at most K digits. If many solutions are possible then print lexicographically largest one.

Examples:

Input   : str = “43435”    
          k = 3
Output  : "93939" 
Lexicographically largest palindrome 
after 3 changes is "93939" 

Input :  str = “43435”    
         k = 1
Output : “53435”
Lexicographically largest palindrome 
after 3 changes is “53435”

Input  : str = “12345”    
         k = 1
Output : "Not Possible"
It is not possible to make str palindrome
after 1 change.

We can solve this problem using two pointers method. We start from left and right and if both digits 
are not equal then we replace the smaller value with larger value and decrease k by 1. We stop when 
the left and right pointers cross each other, after they stop if value of k is negative, then it is 
not possible to make string palindrome using k changes. If k is positive, then we can further maximize 
the string by looping once again in the same manner from left and right and converting both the digits 
to 9 and decreasing k by 2. If k value remains to 1 and string length is odd then we make the middle 
character as 9 to maximize whole value.*/

// Returns maximum possible palindrome using k changes 
string maximumPalinUsingKChanges(string str, int k) 
{ 
    string palin = str; 
  
    // Iinitialize l and r by leftmost and 
    // rightmost ends 
    int l = 0; 
    int r = str.length() - 1; 
  
    //  first try to make string palindrome 
    while (l < r) 
    { 
        // Replace left and right character by 
        // maximum of both 
        if (str[l] != str[r]) 
        { 
            palin[l] = palin[r] = max(str[l], str[r]); 
            k--; 
        } 
        l++; 
        r--; 
    } 
  
    // If k is negative then we can't make 
    // string palindrome 
    if (k < 0) 
        return "Not possible"; 
  
    l = 0; 
    r = str.length() - 1; 
  
    while (l <= r) 
    { 
        // At mid character, if K>0 then change 
        // it to 9 
        if (l == r) 
        { 
            if (k > 0) 
                palin[l] = '9'; 
        } 
  
        // If character at lth (same as rth) is 
        // less than 9 
        if (palin[l] < '9') 
        { 
            /* If none of them is changed in the 
               previous loop then subtract 2 from K 
               and convert both to 9 */
            if (k >= 2 && palin[l] == str[l] && 
                palin[r] == str[r]) 
            { 
                k -= 2; 
                palin[l] = palin[r] = '9'; 
            } 
  
            /*  If one of them is changed in the previous 
                loop then subtract 1 from K (1 more is 
                subtracted already) and make them 9  */
            else if (k >= 1 && (palin[l] != str[l] || 
                                palin[r] != str[r])) 
            { 
                k--; 
                palin[l] = palin[r] = '9'; 
            } 
        } 
        l++; 
        r--; 
    } 
  
    return palin; 
} 
  
//  Driver code to test above methods 
int main() 
{ 
    string str = "43435"; 
    int k = 3; 
    cout << maximumPalinUsingKChanges(str, k); 
    return 0; 
} 

Output: