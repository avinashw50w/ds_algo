#include<iostream>
#include<vector>
#include<cstdio>
#include<climits>
#define FOR(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
void matrix(int P[],int n){
	int m[n][n],j,q;
	int index1,index2;
	vector<char> v(3*n);
	vector<char>::iterator it=v.begin();
	FOR(i,1,n) m[i][i]=0;
	
	FOR(L,2,n-1){
		FOR(i,1,n-L+1){
			j=i+L-1;
			m[i][j]=INT_MAX;
			FOR(k,i,j-1){
				q = m[i][k] + m[k+1][j] + P[i-1]*P[k]*P[j];
				if(q<m[i][j]){
					m[i][j]=q;
					index1=i;
					index2=j;
				}
			}
		}
	//	cout<<index1-1<<" "<<index2-1<<",";
	}
//	FOR(i,0,n-2) cout<<v[i];
	cout<<"\nMIN scalar multiplication : "<<m[1][n-1];
}
int main(){
	int P[]={40,20,30,10,30};
	int n=sizeof(P)/sizeof(P[0]);
	matrix(P,n);
	return 0;
}

