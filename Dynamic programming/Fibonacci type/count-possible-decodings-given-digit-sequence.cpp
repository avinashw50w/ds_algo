/*Let 1 represent ‘A’, 2 represents ‘B’, etc. Given a digit sequence, count the number of possible decodings of the given digit sequence.

Examples:

Input:  digits[] = "121"
Output: 3
// The possible decodings are "ABA", "AU", "LA"

Input: digits[] = "1234"
Output: 3
// The possible decodings are "ABCD", "LCD", "AWD"
An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid
digits from 0 to 9 and there are no leading 0’s, no extra trailing 0’s and no two or more consecutive 0’s.

We strongly recommend to minimize the browser and try this yourself first.

This problem is recursive and can be broken in sub-problems. We start from end of the given digit sequence.
We initialize the total count of decodings as 0. We recur for two subproblems.
1) If the last digit is non-zero, recur for remaining (n-1) digits and add the result to total count.
2) If the last two digits form a valid character (or smaller than 27), recur for remaining (n-2) digits and add the result to total count.*/

// Given a digit sequence of length n, returns count of possible
// decodings by replacing 1 with A, 2 woth B, ... 26 with Z
int countDecoding(char *digits, int n)
{
    // base cases
    if (n == 0 || n == 1)
        return 1;

    int count = 0;  // Initialize count

    // If the last digit is not 0, then last digit must add to
    // the number of words
    if (digits[n - 1] > '0')
        count =  countDecoding(digits, n - 1);

    // If the last two digits form a number smaller than or equal to 26,
    // then consider last two digits and recur
    if (digits[n - 2] < '2' || (digits[n - 2] == '2' && digits[n - 1] < '7') )
        count +=  countDecoding(digits, n - 2);

    return count;
}

////////////////////////////////////////////////////////////////////////////////

/*The time complexity of above the code is exponential. If we take a closer look at the above program,
we can observe that the recursive solution is similar to Fibonacci Numbers. Therefore, we can optimize
the above solution to work in O(n) time using Dynamic Programming.*/

int countDecodingDP(char *digits, int n)
{
    int count[n + 1]; // A table to store results of subproblems
    count[0] = 1;
    count[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        count[i] = 0;

        // If the last digit is not 0, then last digit must add to
        // the number of words
        if (digits[i - 1] > '0')
            count[i] = count[i - 1];

        // If second last digit is smaller than 2 and last digit is
        // smaller than 7, then last two digits form a valid character
        if (digits[i - 2] < '2' || (digits[i - 2] == '2' && digits[i - 1] < '7') )
            count[i] += count[i - 2];
    }
    return count[n];
}

///////////////////////////////////////////////////////////////////////////////////

// space optimized //

int countDecodings(char* str) {
    int n = strlen(str);
    if (n <= 1) return 1;

    // a = dp[i-2], b = dp[i-1], c = dp[i]
    int a = 1, b = 1, c = 0;
    for (int i = 1; i < n; i++) {
        if (str[i] == '0') {
            c = a;
        } else {
            c = b;
            if (str[i - 1] == '1' || (str[i - 1] == '2' && str[i] < '7')) {
                c += a;
            }
        }

        a = b;
        b = c;
    }
    return c;
}

int main() {
    char str[100];
    scanf("%s", str);
    printf("%d\n", countDecodings(str));
