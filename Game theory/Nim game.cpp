/**/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t; cin>>t;
    while(t--){
        int n ,x=0, s; cin>>n;
        for(int i=0;i<n;++i){
            cin>>s;
            x ^= s;
        }
        (x == 0)? puts("Second"): puts("First");
    }
    return 0;
}
