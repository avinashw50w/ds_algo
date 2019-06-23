#include<bits/stdc++.h>
using namespace std;

//  no of ways to reach from (0,0) to (m,n) given that u can only move right and down
int numWays(int m,int n){
	int DP[m][n];  DP[0][0] = 1;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 or j==0) DP[i][j] = 1;
			else 
				DP[i][j] = DP[i-1][j] + DP[i][j-1];     //  to reach (i,j) one has to come from its top or from sits left
			
		}	
	}
	return DP[m-1][n-1];
}

int main(){
	cout << numWays(3,4);
}
