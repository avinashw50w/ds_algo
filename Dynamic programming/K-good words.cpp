   //*+++++++++++++++++++++++++++++++++++++++++*//
  //           ~~~~~ @VIN@SH ~~~~~             //
 //          ~~~~ IIEST SHIBPUR ~~~~          //
//*+++++++++++++++++++++++++++++++++++++++++*//
#include <bits/stdc++.h>
using namespace std;
#define si(o) scanf("%d",&(o))
#define sl(o) scanf("%lld",&(o))
#define ss(o) scanf("%s",(o))
#define mset(a,o) memset((a),(o),sizeof(a))
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define caset int __T,case_n=1;scanf("%d",&(__T));while(__T--)
typedef long long int ll;typedef vector<int> vi;typedef pair<int,int> pii;
#define oo 0x3f3f3f3f
const int mod = 1000000007;
const int MAXN = 100000+9;
/*========================================================================================*/
int f[26];
int main() {
	string s;
	int n,k;
	caset{
		cin>> s;
		si(k);
		n = s.size();
		mset(f,0);
		rep(i,0,n) f[s[i]]++;

		int ans = oo;
		rep(m,1,n+1){
			int count = 0;
			rep(i,0,26){
				if(f[i] < m) 
					count += f[i];
				else if(f[i] > m+k) 
					count += f[i] - (m+k);
			}
			ans = min(ans, count);
		} 
	}
	return 0;
}
