// Longest palindromic subsequence

int LPS(string S){
	int n = S.size();
	int d[n][n] = {};
	for(int i=0; i<n; ++i) d[i][i] = 1;
	
	for(int len=2; len<=n; ++len){
		for(int i=0; i<=n-len; ++i){
			int j = i+len-1;
			if(S[i] == S[j] && len==2) d[i][j] = 2;
			else if(S[i] == S[j]) 
				d[i][j] = d[i+1][j-1] + 2;
			else
				d[i][j] = max(d[i+1][j] , d[i][j-1]);
		}
	}
	return d[0][n-1];
}

// print the lps

// Returns the length of the longest palindromic subsequence in seq
int lps(char *str,char *result)
{
   int n = strlen(str);
   int i, j, cl;
   int L[n][n];  // Create a table to store results of subproblems

   int Way[n][n];// Store how the palindrome come from.


   // Strings of length 1 are palindrome of lentgh 1
   for (i = 0; i < n; i++)
   {
       L[i][i] = 1;
       Way[i][i]=0;
   }


    // Build the table. Note that the lower diagonal values of table are
    // useless and not filled in the process. The values are filled in a
    // manner similar to Matrix Chain Multiplication DP solution (See
    // http://www.geeksforgeeks.org/archives/15553). cl is length of
    // substring
    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
            {
                   L[i][j] = 2;
                   Way[i][j]=0;     
            }

            else if (str[i] == str[j])
            {
                  L[i][j] = L[i+1][j-1] + 2;
                  Way[i][j]=0;
            }

            else
            {
                if(L[i][j-1]>L[i+1][j])
                {
                   L[i][j]=L[i][j-1];
                   Way[i][j]=1;                    
                }
                else
                {
                    L[i][j]=L[i+1][j];
                    Way[i][j]=2;  
                }

            }

        }
    }

    int index=0;
    int s=0,e=n-1;
    char result[1000];

    while(s<=e)
    {
         if(Way[s][e]==0)
         {
             result[index++]=str[s];
             s+=1;
             e-=1;

         }
         else if(Way[s][e]==1)e-=1;
         else if(Way[s][e]==2)s+=1;     
    }

    int endIndex=(L[0][n-1]%2)?index-1:index;

    for(int k=0;k<endIndex;++k)result[L[0][n-1]-1-k]=result[k];

    result[index+endIndex]='\0';


    return L[0][n-1];
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
