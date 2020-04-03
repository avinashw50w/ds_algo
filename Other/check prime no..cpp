// checking if a no is prime

bool isPrime(int n){
	if(n<=1)
	return false;
	if(n==2)
	return true;
	if(n%2==0)
	return false;
	for(int i=3;i<=sqrt(n);i+=2){
		if(n%i==0)
		return false;
	}
	return true;
}
