/*Run-length encoding(RLE) is a very simple and easy form of data compression in which consecutive occurrences of the same
characters are replaced by a single character followed by its frequency. As an example, the string S aabbbbdaa would be
encoded to a2b4d1a2.

Thus encoded string is described as an ordered sequence of pairs (a, i),
each consisting of an alphabet symbol a and an integer i.
 Each pair corresponds to a run in S consisting of i consecutive occurrences of a.

In this problem, we are interested in finding the minimum number of mutation(s) needed to transform first string given in
encoded form into second string i.e. edit distance when only two operation are allowed

Add any character at any position(insertion)
Remove any character from any position(deletion)
The cost of inserting a character is 1 and cost of deleting a character is 2.

Input
The input file contains several test cases. The first line of the input denotes the number of test cases, T (1≤T≤100) to follow.
Each test case begins on a new line and consists of an integer L1, a blankspace and a run length encoded string S1
and then on a new line, an integer L2, a blankspace and a run length encoded string S2.

L1 and L2 denote the number of runs in strings S1 and S2 respectively. 1<=L1,L2<=100.
S1 and S2 consists of alphabets [a-z] followed by number of consecutive occurrences of that character.

You can safely assume that the total length of any of the strings will not exceed 3000 characters.

Output
For each test case, output the edit distance from S1 to S2 in a new line.

Example
Input:
2
2 a3b2
1 b3
3 a1b1a1
1 a2
Output:
7
2*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 111;
int len1, len2;
string buff, P, Q;
int cP[maxn], cQ[maxn], dp[maxn][maxn];

int solve(int i1, int i2) {
	if (i1 == len1 and i2 == len2) return 0;

	if (dp[i1][i2] != -1) return dp[i1][i2];

	int ret = INT_MAX;
	//delete all the chars from P
	if (i1 < len1) ret = min(ret, solve(i1 + 1, i2) + 2 * cP[i1]);
	//insert all the chars of Q into P
	if (i2 < len2) ret = min(ret, solve(i1, i2 + 1) + 1 * cQ[i2]);

	if (i1 < len1 and i2 < len2) {
		if (P[i1] == Q[i2]) {
			int a = 0;
			int waste1 = 0;
			for (int i = i1; i < len1; ++i) {
				if (P[i] == Q[i2]) a += cP[i];
				else waste1 += 2 * cP[i];

				int b = 0, waste2 = waste1;
				for (int j = i2; j < len2; ++j) {
					if (Q[j] == Q[i2]) b += cQ[j];
					else waste2 += cQ[j];

					int temp;
					if (a < b) temp = solve(i + 1, j + 1) + waste2 + (b - a);
					else temp = solve(i + 1, j + 1) + waste2 + 2 * (a - b);

					ret = min(ret, temp);
				}
			}
		}
	}

	return dp[i1][i2] = ret;
}

void process(string &s, int *a)
{
	s = "";
	int n = buff.size();

	for (int i = 0; i < n; ++i)
	{
		s += buff[i];
		int val = 0; i++;
		while (i < n and isdigit(buff[i])) {
			val = val * 10 + (buff[i] - '0');
			i++;
		}
		*a = val;
		a++;
		i--;
	}
}

int main() {
	int t; cin >> t;

	while (t--) {
		cin >> len1 >> buff;

		process(P, cP);

		cin >> len2 >> buff;

		process(Q, cQ);

		memset(dp, -1, sizeof(dp));

		cout << solve(0, 0) << endl;
	}
}
