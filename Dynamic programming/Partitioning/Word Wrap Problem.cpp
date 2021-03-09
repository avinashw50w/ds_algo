/*Word Wrap problem
Given a sequence of words, and a limit on the number of characters that can be put in one line
(line width). Put line breaks in the given sequence such that the extra space left on each
line is minimum. Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces includes spaces put at the end of every line EXCEPT the last one
(NO cost is calculated for the last line).
The problem is to minimize the following total cost.
Total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)^2.
For example, consider the following string and line width M = 15
“Geeks for Geeks presents word wrap problem”
Following is the optimized arrangement of words in 3 lines
Geeks for Geeks
presents word
wrap problem
The total extra spaces in line 1 and line 2 are 0 and 2. Space for line 3 is not considered as it is not extra space as described above. So optimal value of total cost is 0 + 2*2 = 4.

IDEA: use dp
dp[i] : the min cost to wrap all the words from index [i...n-1]
last[i] : represents the index of last word of the line where word[i] is the first word
*/
// K is the limit on the no of characters in each line
int solve(vector<string> word, int K) {
	int n = word.size();

	vector<int> dp(n, INF);
	vector<int> last(n, -1);
	// when there is a single word, then it is the last line
	// so no cost is calculated
	dp[n - 1] = 0;
	last[n - 1] = n - 1;
	// i....j...n-1
	//      ^
	// we try to break at every index j from i to n-1 iff total char does not exceed K
	for (int i = n - 2; i >= 0; --i) {
		int len = -1;
		for (int j = i; j < n; ++j) {
			len += word[j].lenght() + 1; // 1 extra for the space between words
			if (len > K) break;

			int cost = 0;
			// break at j
			// if current word is the last word
			// so it is the last line, so no cost
			if (j == n - 1) cost = 0;
			else
				cost = (K - len) * (K - len) + dp[j + 1];
			if (cost < dp[i]) {
				dp[i] = cost;
				last[i] = j;
			}
		}
	}

	cout << "Total cost = " << dp[0] << endl;

	int line = 1, i = 0;
	while (i < n) {
		cout << "Line no: " << line++ << ": "
		     << "First word = " << word[i] << ", Last word = " << word[last[i]];
		i = last[i] + 1;
	}
}