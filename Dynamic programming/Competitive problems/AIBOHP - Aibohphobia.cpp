/* Given a string S, find the min no of charachters that need to be inserted into S to make it a palindrome. */

/*Let the given input string be S[1.....L]. Then for any substring S[i....j] of the input string, 
we can find the minimum insertions as:
- min_insertions(S[i+1 ...... j-1])                                    [if S[i] is equal to S[j]]
- min(min_insertions(S[i+1......j]), min_insertions(S[i....j-1])) + 1   [o.w.]*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int solve(string S) {
	int N = S.length();

	int dp[N][N];
	memset(dp, 0, sizeof(dp));

	for (int l = 1; l < N; ++l)
		for (int i = 0, j = l; j < N; ++i, ++j) {
			dp[i][j] = (S[i] == S[j]) ? dp[i+1][j-1] : 1 + min(dp[i+1][j], dp[i][j-1]);
		}

	return dp[0][N-1];
}

int main() {
	int T;
	string S;

	cin >> T;
	while(T--) {
		cin >> S;

		cout << solve(S) << endl;
	}
}

////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
int dp[6101][6101];
char s[6109];
int rec( int i , int j){
    if(i > j)
        return INT_MAX;
    if(i == j)
        return 0;
    if(i == j -1 )
        return s[i] == s[j] ? 0 : 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i] == s[j]){
        return dp[i][j] = rec(i+1 , j-1);
    }
    else {
        return dp[i][j] = min(rec(i+1 , j) , rec(i , j-1)) + 1;
    }
}
int main(){
 
    int t;
    scanf("%d", &t);
    while(t--){
        memset(dp , -1 , sizeof dp);
        scanf("%s",s);
        int len = strlen(s);
        printf("%d\n",rec(0 , len-1));
    }
    return 0;
} 