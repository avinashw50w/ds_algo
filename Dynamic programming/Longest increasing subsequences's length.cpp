#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
	int arr[] = {3,4,-1,0,6,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	int DP[n];
	for(int i=0;i<n;i++) 
	DP[i] = 1;
	
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i])
			DP[i] = max(DP[i] , DP[j]+1);	// either include the element or don't include it
		}
	}
	
	cout<<"The longest Increasing subsequence length is : "<<*(max_element(DP,DP+n));
	
	return 0;
}
