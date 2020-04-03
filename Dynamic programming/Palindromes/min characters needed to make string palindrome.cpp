/* Problem: given a string x = x1...n, find the minimum number
of characters that need to be inserted to make it a palindrome
◮ Example:
– x: Ab3bd
– Can get “dAb3bAd” or “Adb3bdA” by inserting 2 characters
(one ‘d’, one ‘A’)  */

int findMinInsertions(char str[], int l, int h)
{
    // Base Cases
    if (l > h) return INT_MAX;
    if (l == h) return 0;
    if (l == h - 1) return (str[l] == str[h])? 0 : 1;
 
    // Check if the first and last characters are same. On the basis of the
    // comparison result, decide which subrpoblem(s) to call
    return (str[l] == str[h])? findMinInsertions(str, l + 1, h - 1):
                               (min(findMinInsertions(str, l, h - 1),
                                   findMinInsertions(str, l + 1, h)) + 1);
}
/////////////////////////////////////////////////////////////////////////////////////

// A DP function to find minimum number of insersions
int findMinInsertionsDP(char str[], int n)
{
    // Create a table of size n*n. table[i][j] will store
    // minumum number of insertions needed to convert str[i..j]
    // to a palindrome.
    int table[n][n], l, h, gap;
 
    // Initialize all table entries as 0
    memset(table, 0, sizeof(table));
 
    // Fill the table
    for (gap = 1; gap < n; ++gap)
        for (l = 0, h = gap; h < n; ++l, ++h)
            table[l][h] = (str[l] == str[h])? table[l+1][h-1] :
                          (min(table[l][h-1], table[l+1][h]) + 1);
 
    // Return minimum number of insertions for str[0..n-1]
    return table[0][n-1];
}
 
// Driver program to test above function.
int main()
{
    char str[] = "geeks";
    printf("%d", findMinInsertionsDP(str, strlen(str)));
    return 0;
}


/* Define subproblems
– Let Dij be the minimum number of characters that need to be
inserted to make xi...j into a palindrome
◮ Find the recurrence
– Consider a shortest palindrome y1...k containing xi...j
– Either y1 = xi or yk = xj (why?)
– y2...k−1 is then an optimal solution for xi+1...j or xi...j−1 or
xi+1...j−1
◮ Last case possible only if y1 = yk = xi = xj 

Find the recurrence
Dij =
(
1 + min{Di+1,j ,Di,j−1} xi 6= xj
Di+1,j−1 xi = xj
◮ Find and solve the base cases: Dii = Di,i−1 = 0 for all i
◮ The entries of D must be filled in increasing order of j − i  */

/* Reverse x to get xR
◮ The answer is n − L, where L is the length of the LCS of x
and xR   */

int makePalindrome(string x){
	int n = x.size();
	string y = s.reverse();
	int L = LCS(x , y);

	return n - L ;
}
