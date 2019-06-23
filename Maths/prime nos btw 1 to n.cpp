//  finding prime nos. btw 1 t0 n  ---- Sieve of Eratosthenes-----
/*
Now suppose we wanted to find all the primes from 1 to 100000, then we would have to call the above method 100000 times. This would be very inefficient 
since we would be repeating the same calculations over and over again. In this situation it is best to use a method known as the Sieve of Eratosthenes. 
The Sieve of Eratosthenes will generate all the primes from 2 to a given number n. It begins by assuming that all numbers are prime. It then takes the 
first prime number and removes all of its multiples. It then applies the same method to the next prime number. This is continued until all numbers have 
been processed. For example, consider finding primes in the range 2 to 20. We begin by writing all the numbers down:

2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
2 is the first prime. We now cross out all of its multiples, ie every second number:

2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
The next non-crossed out number is 3 and thus it is the second prime. We now cross out all the multiples of 3, ie every third number from 3:

2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
All the remaining numbers are prime and we can safely terminate the algorithm. Below is the code for the sieve:
*/

bool* sieve(int n){
	bool* prime = new bool[n];
	for(int i=0;i<n;i++) prime[i] = true;
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i*i<=n;i++){
		if(prime[i]){
			for(int j=i*i;j<=n;j+=i)
			prime[j]=false;
		}
	}
	return prime;
}
