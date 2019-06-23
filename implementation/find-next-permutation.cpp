/*It is a variation of find-next-greater-number-with-the-same-set-of-digits. */

void solve(int a[], int n) {
    int i, j;
     for (i = n-1; i > 0; i--)
        if (a[i] > a[i-1])
           break;
    
    if(i == 0) { 
        sort(a, a+n); 
        for(int i=0;i<n;++i)
            cout <<a[i]<<" ";
        cout << endl;
        return;
    }
    
    int x = a[i-1], smallest = i;
    for (j = i+1; j < n; j++)
        if (a[j] > x && a[j] < a[smallest])
            smallest = j;
            
    swap(a[smallest], a[i-1]);
    
    sort(a+i, a+n);
    
    for(int i=0;i<n;++i)
        cout <<a[i]<<" ";
    
    cout << endl;
    
    return;
}

int main() {
	int t, n; cin>>t;
	while(t--) {
	    cin>>n;
	    int a[n+1];
	    for(int i=0;i<n;++i) cin>>a[i];
	    solve(a, n);
	}
	return 0;
}