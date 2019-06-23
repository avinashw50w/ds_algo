
void fac(int n){
	if(n == 0) return 1;

	return n * fac(n-1);
}

//////////////////////////////////

int fac[15];
fac[0] = 1;
for(int i=1;i<15;++i)
	fac[i] = i * fac[i-1];