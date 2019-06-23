#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void LCS(string &X,string &Y){
	int m=X.size();
	int n=Y.size();
	int T[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
			T[i][j]=0;
			
			else if(X[i-1] == Y[j-1])
				T[i][j] = T[i-1][j-1] + 1;
			
			else
				T[i][j] = max(T[i-1][j] , T[i][j-1]);
		}
	}
	cout<<"The length of the longest common subsequence is : "<<T[m][n]<<"\n";
}

int main(){
	string X ="abcdaf";
	string Y = "acbcf";
	
	LCS(X,Y);
	return 0;
}

/* A top down approach */
void LCS(int i,int j){
	if(dp[i][j] != -1) return dp[i][j];
	if(i == 0 || j == 0) return 0;
			
	if(X[i-1] == Y[j-1])
		return T[i][j] = 1 + LCS(i-1,j-1);
			
	else
		return T[i][j] = max(LCS(i-1,j) , LCS(i,j-1));

}


