// P[i][j] indicates whether the substring s[i...j] is a palindrome or not

void solve(string s) {
    int n = s.length();

    bool P[n][n];
    
    int i, j, k, L; // different looping variables
    
    // Every substring of length 1 is a palindrome
    for (i=0; i<n; i++)
    {
        P[i][i] = true;
    }
    
    for (L=2; L<=n; L++) {
        for (i=0; i<=n-L; i++) {
            j = i+L-1; // Set ending index
    
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
        }
    }

}