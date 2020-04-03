#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int

ll phi(ll n){
    ll res=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) res-=res/i;
        while(n%i==0) n/=i;
    }
    if(n>1) res-=res/n;
    return res;
}
ll modpow(ll a,ll b,ll m){
   ll res=1;
    while(b){
        if(b&1) res=(res*a)%m;
        b>>=1;
        a=(a*a)%m;
    }
    return res;
}
ll mmi(ll a,ll m){
    return modpow(a,phi(m)-1,m);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t
    while(t--){
        ll a,b,x,ans=0;
        cin>>a>>b>>x;
        if(b>=0) ans=modpow(a,b,x);
        else{
            ll p=modpow(mmi(a,x),abs(b),x);
            if(p>=0)
                ans=p;
            else ans=p;
        }
        cout<<ans<<endl;
    }
    return 0;
}

