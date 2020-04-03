#include<iostream>
#include<qsort>
using namespace std;

void subarraySum(int A[],int n,int sum){
	int prefix=0,start=0,flag=0;
	for(int i=0;i<n;i++){
		prefix+=A[i];
		if(prefix==sum) {
			cout<<sum<<endl;
			flag=1;
			break;
		}
		while(prefix>sum)
			prefix-=A[start++];
	}
	if(flag==0) cout<<"No such subarray...";
}
int main(void){
	
}
