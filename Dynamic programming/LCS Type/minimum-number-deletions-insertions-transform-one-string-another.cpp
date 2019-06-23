/*Minimum number of deletions and insertions to transform one string into another
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert 
minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the 
same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Examples:

Input : str1 = "heap", str2 = "pea" 
Output : Minimum Deletion = 2 and
         Minimum Insertion = 1
p and h deleted from heap
Then, p is inserted at the beginning
One thing to note, though p was required yet
it was removed/deleted first from its position and
then it is inserted to some other position.
Thus, p contributes one to the deletion_count
and one to the insertion_count.*/

int LCS(string a, string b) {
	int n = a.size(), m = b.size();

	int dp[n+1][m+1];
	memset(dp, 0,sizeof(dp));

	for(int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i-1] == a[j-1]) 
				dp[i][j] = dp[i-1][j-1] + 1;
			else 
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[n][m];
}

pair<int,int> solution(string a, string b) {

	int n = a.size(), m = b.size();

	int lcs = LCS(a, b);

	int deletions = n - lcs;
	int insertions = m  - lcs;

	return make_pair(insertions, deletions);
}