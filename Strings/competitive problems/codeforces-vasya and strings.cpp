/*High school student Vasya got a string of length n as a birthday present. This string consists of letters 'a' and 'b' only. Vasya denotes beauty of the string as the maximum length of a substring (consecutive subsequence) consisting of equal letters.

Vasya can change no more than k characters of the original string. What is the maximum beauty of the string he can achieve?

Input
The first line of the input contains two integers n and k (1 ≤ n ≤ 100 000, 0 ≤ k ≤ n) — the length of the string and the maximum number of characters to change.

The second line contains the string, consisting of letters 'a' and 'b' only.

Output
Print the only integer — the maximum beauty of the string Vasya can achieve by changing no more than k characters.

Examples
inputCopy
4 2
abba
outputCopy
4

two pointer approach, keep increasing the window length until both the count of a's and b's is > k, otherwise keep updating the length
*/

int main() {
    int n, k; string s;
    cin >> n >> k >> s;
    int a = 0, b = 0, t = 0, ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        s[i] == 'a' ? ++a : ++b;
        if (min(a, b) > k) {
            s[t] == 'a' ? --a : --b;
            t++;
        }
        else ans = max(ans, a + b);
    }

    return ans;
}