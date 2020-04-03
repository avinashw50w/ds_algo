#include<stdio.h>
using namespace std;
const int MAX = 100;
int phi[MAX+1];
void phi_sieve(){
	phi[1]=1;
	for(int i=2;i<=MAX;i++){
		if(!phi[i]){          //  if i is prime
			phi[i] = i-1;     //  phi(p) = p-1  if p is prime
			for(int j=2*i;j<=MAX;j+=i){       // iterating over all multiples of prime i
				if(!phi[j]) phi[j]=j;         //  set phi[N] = N  and then multiply by (1-1/p) ie. (p-1)/p   .....here p is i and N is j
				phi[j] = phi[j]/i*(i-1);     
			}
		}
	}
}
int main(){
	phi_sieve();
	for(int i=1;i<=MAX;i++) printf("phi(%d) = %d\n",i,phi[i]);
	return 0;
}
