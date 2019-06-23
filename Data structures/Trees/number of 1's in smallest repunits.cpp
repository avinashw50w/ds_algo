/*Every number whose unit’s digit is 3 has a repunit as its multiple. A repunit is a number which has only ones. 
It is of the form (10n – 1)/9. Example: 3 divides 111, 13 divides 111111.

A positive integer N will be given whose unit’s digit is 3. The task is to find the number of 1s in 
the smallest repunit which is divisible by the given number N 

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107

Example:
Input
2
3
23
Output
3
22  */

int main() {
	long long T, N;
	cin>>T;
	while(T--) {
	    cin>>N;
	    long long t = 0;
	    for(int i = 1; i < 1000000; ++i) {
	        
	        t = t*10 + 1;
	        t %= N;
	        
	        if(t == 0) {
	            cout << i << endl;
	            break;
	        }
	    }
	}
	return 0;
}