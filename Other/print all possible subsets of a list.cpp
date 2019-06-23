#include<stdio.h>
#include<string.h>
int main(){
	int arr[]={1,2,3,4};
	int i,j,n;
	n=sizeof(arr)/sizeof(arr[0]);
	for(i=1;i<(1<<n);i++){
		for(j=0;j<n;j++){
			if(i & (1<<j))
			printf("%d ",arr[j]);
		}
		printf("\n");
	}
	return 0;
}
