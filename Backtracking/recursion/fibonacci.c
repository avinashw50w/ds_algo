
void fib(int n) {
	if(n < 2) return 1;

	return fib(n-1) + fib(n-2);
}

//////////////////////////////////////

int fib[2000];
fib[0] = fib[1] = 1;
for(int i=2;i<2000;++i)
	fib[i] = fib[i-1] + fib[i-2];