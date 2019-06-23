/*Pairs of complete strings in two sets of strings
Two strings are said to be complete if on concatenation, they contain all the 26 English alphabets. For example, “abcdefghi” 
and “jklmnopqrstuvwxyz” are complete as they together have all characters from ‘a’ to ‘z’.
We are given two sets of sizes n and m respectively and we need to find the number of pairs that are complete on concatenating 
each string from set 1 to each string from set 2.

Input : set1[] = {"abcdefgh", "geeksforgeeks",
                 "lmnopqrst", "abc"}
        set2[] = {"ijklmnopqrstuvwxyz", 
                 "abcdefghijklmnopqrstuvwxyz", 
                 "defghijklmnopqrstuvwxyz"} 
Output : 7
The total complete pairs that are forming are:
"abcdefghijklmnopqrstuvwxyz"
"abcdefghabcdefghijklmnopqrstuvwxyz"
"abcdefghdefghijklmnopqrstuvwxyz"
"geeksforgeeksabcdefghijklmnopqrstuvwxyz"
"lmnopqrstabcdefghijklmnopqrstuvwxyz"
"abcabcdefghijklmnopqrstuvwxyz"
"abcdefghijklmnopqrstuvwxyz"

Method 2 (Optimized method using Bit Manipulation)

In this method, we compress frequency array into an integer. We assign each bit of that integer with a character and 
we set it to 1 when the character is found. We perform this for all the strings in both the sets. Finally we just 
compare the two integers in the sets and if on combining all the bits are set, they form a complete string pair.*/

// Returns count of complete pairs from set[0..n-1]
// and set2[0..m-1]
int countCompletePairs(string set1[], string set2[],
                       int n, int m)
{
    int result = 0;
 
    // con_s1[i] is going to store an integer whose
    // set bits represent presence/absence of characters
    // in string set1[i].
    // Similarly con_s2[i] is going to store an integer
    // whose set bits represent presence/absence of
    // characters in string set2[i]
    int con_s1[n], con_s2[m];
 
    // Process all strings in set1[]
    for (int i=0; i<n; i++)
    {
        // initializing all bits to 0
        con_s1[i] = 0;
        for (int j=0; j<set1[i].length(); j++)
        {
            // Setting the ascii code of char s[i][j]
            // to 1 in the compressed integer.
            con_s1[i] = con_s1[i] | (1<<(set1[i][j]-'a'));
        }
    }
 
    // Process all strings in set2[]
    for (int i=0; i<m; i++)
    {
        // initializing all bits to 0
        con_s2[i] = 0;
        for (int j=0; j<set2[i].length(); j++)
        {
            // setting the ascii code of char s[i][j]
            // to 1 in the compressed integer.
            con_s2[i] = con_s2[i]|(1<<(set2[i][j]-'a'));
        }
    }
 
    // assigning a variable whose all 26 (0..25)
    // bits are set to 1
    long long complete = (1<<26) - 1;
 
    // Now consider every pair of integer in con_s1[]
    // and con_s2[] and check if the pair is complete.
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            // if all bits are set, the strings are
            // complete!
            if ((con_s1[i] | con_s2[j]) == complete)
                result++;
        }
    }
 
    return result;
}