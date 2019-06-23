#include <bits/stdc++.h>
using namespace std;

// program to check whether n is divisible by x or not , where n is a very large number to fit into 64 bit
int main() {  
    int test, x;
    string n;
    cin >> t;
    cin >> x;
    while(test--){
        cin >> n;
        int t=0;
        for(int i=0;n[i];++i){
            t = t*10 + n[i]-48;
            t %= x;
        }
        (t==0)? puts("YES") : puts("NO");
    }
    return 0;
}
