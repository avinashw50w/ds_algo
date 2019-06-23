#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int

ll modpow(ll a,ll b,ll m){
    if(b==0) return 1;
    if(b&1) return ((a%m)*modpow(a,b-1,m))%m;
    else{
        ll p=modpow(a,b/2,m);
        return (p*p)%m;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;cin>>t;
    while(t--){
        ll A,M;
        cin>>A>>M;
        if(A==0){cout<<"YES\n";continue;}
        if(modpow(A,(M-1)/2,M)==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

