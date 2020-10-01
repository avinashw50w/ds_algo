/*directi-interview-questions1
of 1 vote
12
Answers
We need to make a string of size n. Each character of the string is either ‘R’, ‘B’ or ‘G’.
In the final string there needs to be at least r number of ‘R’, at least b number of ‘B’ and
at least g number of ‘G’ (such that r + g + b <= n). We need to find number of such strings possible.
For example,
n = 4, r = 1, b = 1, g = 1.
Output:
36
first take r,g and b red, green and blue balls
*/

int Count(int n, int r, int g, int b)
{
    vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        fact[i] = fact[i - 1] * i;
    }

    int remain = n - (r + g + b);
    int sum = 0;

    for (int i = 0 ; i <= remain ; i++) {
        for (int j = 0 ; j <= remain - i ; j++) {
            int k = remain - (i + j);
            sum = sum + fact[n] / (fact[i + r] * fact[j + g] * fact[b + k]);
        }
    }
    return sum;
}