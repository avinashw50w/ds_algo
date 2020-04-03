/* calculate the modulo multiplicative inverse(mmi) of all the numbers less than mod m in linear time */
/* let i and m be the number and mod respectively then its mmi is :
   r[i] = -[m/i].r[m mod i]  */

#include <bits/stdc++.h>
using namespace std;
int main(){
	int m=13;
	int r[m] = {};
	r[1] = 1;
	for (int i=2; i<m; ++i)
		r[i] = (-(m/i) * r[m%i] % m + m) % m;

	for(int i=1;i<m;++i) 
		cout<<r[i]<<endl;
}



/////////////////////////////////////////////////////////////
// other lenghty way to do this is //

ll mpow(int a,int b,int m){
	if(b==0) return 1;
	ll x = mpow(a,b/2,m);
	x = (x*x)%m;
	if(b&1) x = (x*(ll)a)%m;
	return x;
} 

int main(){
	for(int i=1;i<m;++i)
		cout << mpow(i,m-2,m) << endl;
}
