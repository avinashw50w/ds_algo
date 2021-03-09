/*Given a string str containing alphanumeric characters, calculate sum of all numbers present in the string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a string containing alphanumeric characters.

Output:
Print the sum of all numbers present in the string.

Constraints:
1<=T<=105
1<=length of the string<=105

Example:
Input:
4
1abc23
geeks4geeks
1abc2x30yz67
123abc

Output:
24
4
100
123*/
#include <iostream>
using namespace std;

int solve(string s) {
    int n = s.size();
    int i = 0;
    int ans = 0;
    while (i < n) {
        if (isdigit(s[i])) {
            int j = 0;
            int t = 0;
            while (i + j < n and isdigit(s[i + j])) t = t * 10 + s[i + j] - '0', j++;
            ans += t;
            i += j;
        }
        else i++;
    }

    return ans;
}

int main() {
    //code
    int t;  cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}