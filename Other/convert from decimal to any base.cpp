#include<stdio.h>
#include<math.h>
int main(){
	int n,i,b;                                     
	printf("Enter the number :");
	scanf("%d",&n);
	for(i=(int)(log2(n));i>=0;i--){             // no of digits needed to represent a no n in binary form = [log(n)] + 1
		if(n&(1<<i)) printf("1");
		else printf("0");
	}
	return 0;
}

//  easiest one // convert to any base //

string toBaseb(int n,int b){
	string s="0123456789ABCDEFGHIJ";
	string res="";
	
	while(n){
		res+=s[n%b];
		n/=b;
	}
	return res;	
}
