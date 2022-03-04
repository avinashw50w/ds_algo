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

IDEA: let dp[i] - # of possible decodings upto index i
let say the string is 3 2 4 1 3
3 2 4 1 _ : decode 3 as C and add the previous answer which is dp[i-1]
3 2 4 _ _ : decode  1 3 as M and add the previous answer which is dp[i-2]
so dp[i] += dp[i-1] if ith digit > 0
and dp[i] += dp[i-2] if the i-1th and ith digit lies btw 10 to 26
*/
// decodings by replacing 1 with A, 2 woth B, ... 26 with Z
int countDecoding(char *digits, int n)
{
    // base cases
    if (n == 0 || n == 1)
        return 1;
 
    int count = 0;  // Initialize count
 
    // If the last digit is not 0, then last digit must add to
    // the number of words
    if (digits[n-1] > '0')
        count =  countDecoding(digits, n-1);
 
    // If the last two digits form a number smaller than or equal to 26,
    // then consider last two digits and recur
    if (digits[n-2] < '2' || (digits[n-2] == '2' && digits[n-1] < '7') )
        count +=  countDecoding(digits, n-2);
 
    return count;
}

////////////////////////////////////////////////////////////////////////////////

/*The time complexity of above the code is exponential. If we take a closer look at the above program, 
we can observe that the recursive solution is similar to Fibonacci Numbers. Therefore, we can optimize 
the above solution to work in O(n) time using Dynamic Programming.*/

int countDecodingDP(char *digits, int n)
{
    int count[n+1]; // A table to store results of subproblems
    count[0] = 1;
    count[1] = 1;
 
    for (int i = 2; i <= n; i++)
    {
        count[i] = 0;
 
        // If the last digit is not 0, then last digit must add to
        // the number of words
        if (digits[i-1] > '0')
            count[i] = count[i-1];
 
        // If second last digit is smaller than 2 and last digit is
        // smaller than 7, then last two digits form a valid character
        if (digits[i-2] < '2' || (digits[i-2] == '2' && digits[i-1] < '7') )
            count[i] += count[i-2];
    }
    return count[n];
}

///////////////////////////////////////////////////////////////////////////////////

// space optimized //

int numDecodings(string s) {
    if (s.empty()) return 0;
    
    int a, b, c;
    a = b = c = s[0] != '0';
    
    for (int i = 1; i < s.length(); ++i) {
        // if curr digit is 0, then the prev digit should be either 1 or 2
        if (s[i] == '0') {
            if (s[i-1] != '1' and s[i-1] != '2') return 0;
            c = a;
        }
        else {
            c = b;
            if (s[i-1] == '1' or (s[i-1] == '2' and s[i] < '7')) c += a;
        }
        
        a = b;
        b = c;
    }
    
    return c;
}

int main(){
	char str[100];
	scanf("%s", str);
	printf("%d\n", countDecodings(str)); 
