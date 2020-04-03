#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int power(int base, int expo){       
  int result = 1;

  while (expo){
    if (expo&1)
      result *= base;

    expo >>=1 ;
    base *= base;
  }

  return result;
}
/////////////////////////////////////////////////////////////////////////
// recursive
int power(int base,int expo){
	if(expo==0) return 1;           // if exponent is zero then return  1
	
	if(expo&1) return base*power(base,expo-1);     //  if exponent is odd  then return  x*(x^n-1)    ....here '^' stand for power

	int p = power(base,expo/2);                    //  if expo is even then return  (x^n/2)*(x^n/2)
	return p*p;
}
//////////////////////////////////////////////////////
ll power(int a,int b){
	if(b==0) return 1;
	ll x = power(a,b/2);
	x *= x;
	
	if(b&1) x *= a;
	return x;
}

int main(){
	cout<<power(2,10);
}

//////////////////////////////////////////////////

ll power(ll a, ll b) {
	ll r = 1;
	for(; b; b>>=1, a*=a) if(b & 1) r *= a; 
	return r;
}