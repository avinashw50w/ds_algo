#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

int C[5005][5005];

// bottom up //
void prec(){
    for(int n=1; n<5001; ++n){
        C[n][0] = C[n][n] = 1;
        int k = n>>1;
        for(int r=1; r<=k; ++r)
            C[n][r] = C[n][n-r] = (C[n-1][r-1] + C[n-1][r]) % mod;
    }
}

// top down //
void nCr(int n, int r) {
    if(r<0 or r>n) return 0;
    if(r==0 or r==n) return 1;
    if(C[n][r] != -1) return C[n][r];
    return C[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
}
 
int main(){
    
    prec();

    int n, r;

    while(cin>>n>>r){
        
        cout << C[n][r] << endl;
    }
}

//////////////////////////////////////////////////////////////////////////////
// space optimized way //

long nCr(int n, int r){
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=i and j<=r; ++j){
            if(j == 0 or j == i) 
                C[i&1][j] = 1;
            else
                C[i&1][j] = (C[(i-1)&1][j] + C[(i-1)&1][j-1]) % mod;
        }
    }
    return C[n&1][r];
}
//////////////////////////////////////////////////////////////////////

int binomialCoeff(int n, int k)
{
    int C[k+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1;  // nC0 is 1
 
    for (int i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using
        // the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] += C[j-1];
    }
    return C[k];
}

