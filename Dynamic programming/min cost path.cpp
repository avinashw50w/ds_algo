#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void minCostPath(int A[3][4] , int m, int n){
	int DP[m][n] ;
	DP[0][0] = A[0][0];
	for(int i=1;i<m;i++)     //  base case for leftmost column
	DP[i][0] = DP[i-1][0] + A[i][0];
	
	for(int j=1;j<n;j++)    // //  base case for topmost row
	DP[0][j] = DP[0][j-1] + A[0][j];
	
	for(int i=1;i<m;i++){                                                   
		for(int j=1;j<n;j++){
			DP[i][j] = A[i][j] + min(DP[i-1][j] , DP[i][j-1]);      //  if one also moves diagonally then use DP[i][j] = A[i][j] + min(DP[i-1][j] , min(DP[i][j-1] , DP[i-1][j-1]) );
		}
	}
	cout<<"The min cost is : "<<DP[m-1][n-1]<<"\n";
	
	vector<int> path;
	path.push_back(A[m-1][n-1]);
	int i=m-1 , j=n-1;
	while(i>=0 && j>=0){
		if(i==0){
			path.push_back(A[i][j-1]);
			j--;
		}
			
			if(j==0){
			path.push_back(A[i-1][j]);
			i--;
		}
		if(i>0 && j>0){
			if(DP[i-1][j]<=DP[i][j-1]){
			path.push_back(A[i-1][j]);
			i--;
			}
		else{
			path.push_back(A[i][j-1]);
			j--;
			}
		}
		
	}
	vector<int>::iterator it;
	cout<<"The min cost path is:";
	for(it=path.end();it!=path.begin();--it)
	cout<<path[*it]<<" ";
}

int main(){
	int m,n;
//	cout<<"Enter the no of rows and columns : ";
//	cin>>m>>n;
	int A[3][4]= { {1,3,5,8},{4,2,1,7},{4,3,2,3} };
	//cout<<"Enter the matrix : \n";
/*	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>A[i][j];
		}
	}*/
	minCostPath(A,3,4);
	return 0;
}
