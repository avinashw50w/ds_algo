
#ifdef __WIN32__
#define getchar_unlocked getchar
#endif
inline int inp(){
	register int n, c;
	c = getchar_unlocked();
	while(c==' ' || c=='\n') c = getchar_unlocked();
	while(c>='0' && c<='9'){
		n = (n<<3) + (n<<1) + c-48;
		c = getchar_unlocked();
	}
	return n;
}


//////////////////////////////////////////////////////////////////////

#define Input(_x)					\
  {							\
    long long _tmp = 0;					\
    register int _ch = getchar_unlocked();		\
    while (_ch < 48 || _ch > 57)			\
      _ch = getchar_unlocked();				\
    while (48 <= _ch && _ch <= 57)			\
      {							\
	_tmp = (_tmp << 3) + (_tmp << 1) + _ch - 48;	\
	_ch = getchar_unlocked();			\
      }							\
    (_x) = _tmp;					\
  }							\
 
char _str[20];
#define Output(_x)				\
  {						\
    register int _i = 0;			\
    long long _tmp = (_x);				\
    do						\
      {						\
	*(_str + _i++) = _tmp % 10 + 48;	\
	_tmp /= 10;				\
      } while (_tmp != 0);			\
    for (_i--; _i >= 0; _i--)			\
      putchar_unlocked(*(_str + _i));		\
  }	
