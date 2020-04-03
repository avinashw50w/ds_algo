#include<bits/stdc++.h>
using namespace std;
template<typename T>
void bubbleSort(T *A,int n){
int flag;
	for(int i=0;i<n;i++){
		flag=0;
		for(int j=0;j<n-i-1;j++){
			if(A[j]>A[j+1]){
				swap(A[j],A[j+1]);
				flag=1;
			}
		}
		if(flag==0) break;
	}
}
int main(){
	int A[]={1,2,3,4,5,6,7,8,9};
	int n=sizeof(A)/sizeof(A[0]);
	bubbleSort(A,n);
	for(int i=0;i<n;i++) cout<<A[i]<<" ";
	return 0;
}

