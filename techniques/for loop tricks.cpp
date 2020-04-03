#include<iostream>
using namespace std;
int main(){
	int a,s,i;
	char str[100];
	for(scanf("%d",&a),s=0 ; a!=0 ; s=s*10+(a%10),a/=10);
	printf("%d\n",s);
	for(i=0,scanf("%s",str) ; str[i] ; i++);
	printf("%d\n",i);
	return 0;
}
