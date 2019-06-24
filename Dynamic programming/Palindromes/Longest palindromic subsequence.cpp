// Longest palindromic subsequence

int LPS(string S){
	int n = S.size();
	int d[n][n] = {};
	for(int i=0; i<n; ++i) d[i][i] = 1;
	
	for(int len=2; len<=n; ++len){
		for(int i=0; i<=n-len; ++i){
			int j = i+len-1;
			if(S[i] == S[j]) {
        if (len == 2) dp[i][j] = 2;
				else d[i][j] = d[i+1][j-1] + 2;
      }
			else
				d[i][j] = max(d[i+1][j] , d[i][j-1]);
		}
	}
	return d[0][n-1];
}

// print the lps

// Returns the length of the longest palindromic subsequence in seq
string lps(char *str,char *result)
{
    int n = strlen(str);
    int dp[n][n];  // Create a table to store results of subproblems

    int way[n][n];// Store how the palindrome come from.

    for (i = 0; i < n; i++) {
        dp[i][i] = 1;
        way[i][i] = 0;
    }


    // Build the table. Note that the lower diagonal values of table are
    // useless and not filled in the process. The values are filled in a
    // manner similar to Matrix Chain Multiplication DP solution (See
    // http://www.geeksforgeeks.org/archives/15553). cl is length of
    // substring
    for (int len=2; len<=n; len++) {
        for (i=0; i<=n-len; i++) {
            j = i+len-1;
            if (str[i] == str[j]) {
                   if (len == 2) dp[i][j] = 2;
                   else dp[i][j] = dp[i+1][j-1] + 2;
                   way[i][j]=0;     
            }
            else {
                if(dp[i][j-1] > dp[i+1][j]) {
                   dp[i][j] = dp[i][j-1];
                   way[i][j] = 1;                    
                }
                else {
                    dp[i][j] = dp[i+1][j];
                    way[i][j]=2;  
                }

            }

        }
    }

    int index = 0;
    int s = 0, e = n-1;
    string res = "";

    while(s <= e) {
         if(way[s][e]==0)
         {
             result += str[s];
             s++;
             e--;

         }
         else if(Way[s][e]==1) e--;
         else if(Way[s][e]==2) s++;     
    }

    // int endIndex=(L[0][n-1]%2)?index-1:index;

    // for(int k=0;k<endIndex;++k)result[L[0][n-1]-1-k]=result[k];

    // result[index+endIndex]='\0';


    return res;
}

/* Driver program to test above functions */
int main()
{
    char seq[] = "GEEKSFORGEEKS";
    char result[20];
    cout<<"The lnegth of the LPS is "<<lps(seq,result)<<":"<<endl;
    cout<<result<<endl;
    getchar();
    return 0;
}
