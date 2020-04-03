#ifdef __WIN32__
#define getchar_unlocked getchar
#endif
inline ll inp(){
	ll n = 0;
	register int c = getchar_unlocked();
	while(c==' ' or c=='\n') c = getchar_unlocked();
	while(c>='0' and c<='9'){
		n = (n<<3) + (n<<1) + c-48;
		c = getchar_unlocked();
	}
	return n;
}
