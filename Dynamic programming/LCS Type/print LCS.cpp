#include<iostream>
#include<string>
using namespace std;

void LCSlen(string &X,string &Y){
	int m=X.size();
	int n=Y.size();
	int T[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
			T[i][j] = 0;
			
			else if(X[i-1]==Y[j-1])
			T[i][j] = T[i-1][j-1] + 1;
			
			else
			T[i][j] = max(T[i-1][j] , T[i][j-1]);
		}
	}
	cout<<"The length of the LCS is :"<<T[m][n]<<"\n";
	
	int index = T[m][n];
	char LCS[index+1];
	LCS[index] = '\0';
	
	int i=m,j=n;
	while(i>0 && j>0){
		if(X[i-1]==Y[j-1]){
			LCS[--index] = X[i-1];
			i--;j--;
		}
		else if(T[i-1][j]>=T[i][j-1])
		i--;
		
		else j--;
	}
	printf("%s",LCS);
}

int main(){
	string X ="abcdaf";
	string Y = "acbcf";
	
	LCSlen(X,Y);
	return 0;
}
