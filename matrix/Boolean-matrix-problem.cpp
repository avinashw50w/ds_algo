/*Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) 
then make all the cells of ith row and jth column as 1.*/

int main() {
	int t, r, c;
	cin>>t;
	while(t--) {
	    cin>>r>>c;
	    int a[r][c], row[r] = {}, col[c] = {};
	    
	    for(int i=0; i<r; ++i) 
	        for(int j=0; j<c; ++j) cin>>a[i][j];
	   
	   for(int i=0; i<r; ++i)  
	        for(int j=0; j<c; ++j) 
	            if(a[i][j]){
	                row[i] = 1;
	                col[j] = 1;
	            }
	        
	    for(int i=0; i<r; ++i) 
	        for(int j=0; j<c; ++j) 
	            if(row[i] or col[j]) 
	                a[i][j] = 1;
	    
	    for(int i=0; i<r; ++i) {
	        for(int j=0; j<c; ++j) 
	            cout<<a[i][j]<<" ";
	     
	    }
	    cout << endl;
	}
	return 0;
}