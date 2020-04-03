/*Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....*/

int main() {
	int n = 100;

	int i = 5, cnt = 0;

	while(n >= 1) {
		cnt += n/i;
		n /= i;
	}
	cout << cnt << endl; 	
	

}