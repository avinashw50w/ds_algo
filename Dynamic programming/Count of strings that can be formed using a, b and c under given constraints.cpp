/*Count of strings that can be formed using a, b and c under given constraints
Given a length n, count the number of strings of length n that can be made using ‘a’, ‘b’ and ‘c’ with at-most one ‘b’ and two ‘c’s allowed.

Examples :

Input : n = 3
Output : 19
Below strings follow given constraints:
aaa aab aac aba abc aca acb acc baa
bac bca bcc caa cab cac cba cbc cca ccb

Input  : n = 4
Output : 39*/

int countStr(int n, int bCount = 1, int cCount = 2)
{
	if (bCount < 0 || cCount < 0) return 0;
	if (n == 0) return 1;
	if (bCount == 0 && cCount == 0) return 1;

	int res = countStr(n - 1, bCount, cCount);
	res += countStr(n - 1, bCount - 1, cCount);
	res += countStr(n - 1, bCount, cCount - 1);

	return res;
}

// dp approach

int dp[100][2][3];

int solve(int n, int bCount = 1, int cCount = 2)
{
	if (bCount < 0 || cCount < 0) return 0;
	if (n == 0) return 1;
	if (bCount == 0 && cCount == 0) return 1;

	int &ret = dp[n][bCount][cCount];
	if (ret != -1)
		return ret;

	int res = solve(n - 1, bCount, cCount);
	res += solve(n - 1, bCount - 1, cCount);
	res += solve(n - 1, bCount, cCount - 1);

	return (ret = res);
}

/// O(1) solution
// if we have a (x times), b(y times) and c(z times)...
// then the # of possible combinations are: (x + y + z)! / x! * y! * z!
int solve(int n) {
	return (n * (n - 1) * (n - 2) / 2) // a=n-b-c, b=1 c=2 => n!/(n-3)! * 1! * 2!
	       + (n * (n - 1) / 2) // a=n-b-c, b=0 c=2 => n!/(n-2)! * 2!
	       + (n * (n - 1)) // a=n-b-c, b=1 c=1 => n!/(n-2)! * 1! * 1!, (n-2)! for a and 1! for both b and c
	       + n //a=n-b-c, b=0 c=1 => n!/(n-1)!
	       + n //a=n-b-c, b=1 c=0 => n!/(n-1)!
	       + 1; //a=n-b-c, b=0 c=0
}