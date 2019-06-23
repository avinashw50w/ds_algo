/*Longest Even Length Substring such that Sum of First and Second Half is same
Given a string ‘str’ of digits, find length of the longest substring of ‘str’, such that the length of the 
substring is 2k digits and sum of left k digits is equal to the sum of right k digits. 

Examples:

Input: str = "123123"
Output: 6
The complete string is of even length and sum of first and second
half digits is same.
[A O(n2) time and O(1) extra space solution]
The idea is to consider all possible mid points (of even length substrings) and keep expanding 
on both sides to get and update optimal length as the sum of two sides become equal.*/

// A O(n^2) time and O(1) extra space solution

int findLength(string str, int n)
{
    int ans = 0;
 
    // Consider all possible midpoints one by one
    for (int i = 0; i <= n-2; i++)
    {

        int l = i, r = i + 1;
 
        int lsum = 0, rsum = 0;
 
        while (r < n && l >= 0)
        {
            lsum += str[l] - '0';
            rsum += str[r] - '0';
            if (lsum == rsum) // note that r-l+1 will always be even bacause we are moving both l and r by 1 so total 2 steps at a time
                ans = max(ans, r-l+1);
            l--;
            r++;
        }
    }
    return ans;
}
 

/////////////////////////////////////////////////////////////////////////

/*Dynamic Programming [ O(n2) and O(n2) extra space]
The above solution can be optimized to work in O(n2) using Dynamic Programming. The idea is to build a 2D table 
that stores sums of substrings. The following is C based implementation of Dynamic Programming approach.*/

int findLength(char *str)
{
    int n = strlen(str);
    int maxlen = 0; // Initialize result
 
    // A 2D table where sum[i][j] stores sum of digits
    // from str[i] to str[j].  Only filled entries are
    // the entries where j >= i
    int sum[n][n];
 
    // Fill the diagonal values for sunstrings of length 1
    for (int i =0; i<n; i++)
        sum[i][i] = str[i]-'0';
 
    // Fill entries for substrings of length 2 to n
    for (int len=2; len<=n; len++)
    {
        // Pick i and j for current substring
        for (int i=0; i<n-len+1; i++)
        {
            int j = i+len-1;
            int k = len/2;
 
            sum[i][j] = sum[i][j-k] + sum[j-k+1][j];
 
            if (len%2 == 0 && sum[i][j-k] == sum[(j-k+1)][j]
                           && len > maxlen)
                 maxlen = len;
        }
    }
    return maxlen;
}
 
// Driver program to test above function
int main(void)
{
    char str[] = "153803";
    printf("Length of the substring is %d", findLength(str));
    return 0;
}
Time complexity of the above solution is O(n2), but it requires O(n2) extra space.

/////////////////////////////////////////////////////////////////////////////////////////////

/* [A O(n2) and O(n) extra space solution]
The idea is to use a single dimensional array to store cumulative sum. */
 
int findLength(string str, int n)
{
    int sum[n+1]; // To store cumulative sum from first digit to nth digit
    sum[0] = 0;
 
    /* Store cumulative sum of digits from first to last digit */
    for (int i = 1; i <= n; i++)
        sum[i] = (sum[i-1] + str[i-1]  - '0'); /* convert chars to int */
 
    int ans = 0; // initialize result
 
    /* consider all even length substrings one by one */
    for (int len = 2; len <= n; len += 2)
    {
        for (int i = 0; i <= n-len; i++)
        {
            int j = i + len - 1;
 
            /* Sum of first and second half is same than update ans */
            if (sum[i+len/2] - sum[i] == sum[i+len] - sum[i+len/2])
                ans = max(ans, len);
        }
    }
    return ans;
}
 

