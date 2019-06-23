/*Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them.

Input:  str[] = "ABC"
Output: ABC
        AB C
        A BC
        A B C 
*/

void printPatternUtil(char str[], char buff[], int i, int j, int n)
{
    if (i==n)
    {
        buff[j] = '\0';
        cout << buff << endl;
        return;
    }
 
    // Either put the character
    buff[j] = str[i];
    printPatternUtil(str, buff, i+1, j+1, n);
 
    // Or put a space followed by next character
    buff[j] = ' ';
    buff[j+1] = str[i];
 
    printPatternUtil(str, buff, i+1, j+2, n);
}
 
// This function creates buf[] to store individual output string and uses
// printPatternUtil() to print all permutations.
void printPattern(char *str)
{
    int n = strlen(str);
 
    // Buffer to hold the string containing spaces
    char buf[2*n]; // 2n-1 characters and 1 string terminator
 
    // Copy the first character as it is, since it will be always
    // at first position
    buf[0] = str[0];
 
    printPatternUtil(str, buf, 1, 1, n);
}