#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
using namespace std;

int eulerPhi(int n){
	int res = n;
	for(int i = 2; i*i <= n; i++){         // get all divisors of n upto sqrt(n)
		if(n%i == 0)	res -= res/i;      // phi(n) = n*(1-1/p) = n-n/p
		
		while(n%i == 0) n /= i;         // if n is a multiple of powers of prime i  , then remove all the powers of prime i from n
	}
	if(n > 1) res -= res/n;
	
	return res;
}


int main(){
	string  s;
	int n;
	do{
		cout<<"Enter the number:";
		cin>>s;
		stringstream(s)>>n;
		printf("phi(%d) = %d\n",n,eulerPhi(n));
	}while(s!="exit");
	return 0;
}
