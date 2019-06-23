/*Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of testcases.
Each case begins with a single positive integer N denoting the size of array.
The second line contains the N space separated positive integers denoting the elements of array A.

Output:
For each testcase, print "Yes" or  "No" whtether it is Pythagorean Triplet or not.

Constraints:
1<=T<=50
 1<=N<=100
 1<=A[i]<=100

Example:
Input:
1
5
3 2 4 6 5
Output:
Yes*/

int main() {
	int t, n;
	cin>>t;
    
	while(t--) {
	    cin>>n;
	    int a[n+1];
	    for(int i=0;i<n;++i) {
	        cin>>a[i];
	        a[i] = a[i]*a[i];
	    }
	    string ans = "No";
	    sort(a,a+n);
	    for(int i=n-1;i>=2;--i){
	        int l = 0;
	        int r = i-1;
	        while(l < r) {
	            if(a[l]+a[r] == a[i]) {
	                ans = "Yes";
	                break;
	            }
	            if(a[l]+a[r] < a[i]) l++;
	            else r--;
	        }
	        if(ans == "Yes") break;
	    }
	    cout <<ans<<endl;
	}
	return 0;
}