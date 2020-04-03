/*Converting one string to other using append and delete last operations
Given an integer k and two strings str1 and str2 determine whether or not we can convert str1 to str2 by performing exactly k of the below operations on str1.
a) Append a lowercase English alphabetic letter to the end of the str1.
b) Delete the last character in str1 (Performing this operation on an empty string results in an empty string)

Examples:

Input : k = 7, str1 = aba, str2 = aba
Output : Yes
(4 operations to convert str1 to an 
empty string(to make string empty we 
have to perform one more delete 
operation) and 3 append operations)

Input : k = 5, str1 = pqruvs, str2 = pqrxy 
Output : Yes
(3 delete operations and 2 append operations)
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
First of all we determine the common prefix of both strings and then depending upon the value of common prefix, str1.length, str2.length and k we can conclude result. Below are the cases.
CASE A: Cases where we can change str1 to str2 :

If str1.length + str2.length <= k then we can delete str1 completely and re-construct str2 easily.
If [k-(str1.length-prefix.length + str2.length-prefix.length)] is even then we can easily construct str2 from str1. This is because str1.length-prefix.length is number of letter to be deleted and str2.length-prefix.length is number of letter to be added in str1 after deletion of uncommon letter. After this if the operations left is even then we can add and remove any random letter which cost even number of operations.
CASE B: In rest of all cases we cannot construct str2 from str1.*/

// CPP Program to convert str1 to str2 in 
// exactly k operations 
#include <bits/stdc++.h> 
using namespace std; 
  
// Returns true if it is possible to convert 
// str1 to str2 using k operations. 
bool isConvertible(string str1, string str2,  
                                      int k) 
{ 
    // Case A (i) 
    if ((str1.length() + str2.length()) < k) 
        return true; 
  
    // finding common length of both string 
    int commonLength = 0; 
    for (int i = 0; i < min(str1.length(),  
                           str2.length()); i++) { 
        if (str1[i] == str2[i]) 
            commonLength++; 
        else
            break; 
    } 
  
    // Case A (ii)- 
    if ((k - str1.length() - str2.length() +  
                     2 * commonLength) % 2 == 0) 
        return true; 
  
    // Case B- 
    return false; 
} 
  
// driver program 
int main() 
{ 
    string str1 = "geek", str2 = "geek"; 
    int k = 7; 
    if (isConvertible(str1, str2, k)) 
       cout << "Yes"; 
    else
       cout << "No"; 
  
    str1 = "geeks",  str2 = "geek"; 
    k = 5;     
    cout << endl; 
    if (isConvertible(str1, str2, k)) 
       cout << "Yes"; 
    else
       cout << "No"; 
    return 0; 
} 
