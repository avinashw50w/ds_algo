/*Reverse an array without affecting special characters
Given a string, that contains special character together with alphabets (‘a’ to ‘z’ and ‘A’ to ‘Z’), 
reverse the string in a way that special characters are not affected.

Examples:

Input:   str = "a,b$c"
Output:  str = "c,b$a"
Note that $ and , are not moved anywhere.  
Only subsequence "abc" is reversed

Input:   str = "Ab,c,de!$"
Output:  str = "ed,c,bA!$"*/


// Returns true if x is an aplhabatic character, false otherwise
bool isAlphabet(char x)
{
    return ( (x >= 'A' &&  x <= 'Z') ||
             (x >= 'a' &&  x <= 'z') );
}
 
void reverse(char str[])
{
    int r = strlen(str) - 1, l = 0;

    while (l < r)
    {
        if (!isAlphabet(str[l]))
            l++;
        else if(!isAlphabet(str[r]))
            r--;
 
        else 
        {
            swap(str[l], str[r]);
            l++;
            r--;
        }
    }
}