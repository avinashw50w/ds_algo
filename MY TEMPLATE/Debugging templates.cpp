/*================================================== DEBUGGING TEMPLATES =======================================================*/

// print any nested vector
template<class T>
void print(T const& object) {
    std::cout << object << ' ';
}

template<class...Args>
void print(std::vector<Args...> const& container) {
    for(auto const& element : container) {
        print(element);
    }
    std::cout << '\n';
}

////////////////////////////////////////////////////////////////////////
#ifdef DEBUG
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)
#endif
struct debugger {
    template<typename T> debugger& operator , (const T& v) { cerr << v << " "; return *this; }
} dbg;

/*==============================================================================================================================*/
// only for C99 strict
#ifdef DEBUG
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define dprintf(fmt,...)
#endif

/*===================================================================================================================================*/

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

/*=================================================================================================================================*/

#ifdef TRACE
#define trace(x)            cerr<<x<<endl;
#define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
#define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
#define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
#define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;
#else
#define trace(x)
#define trace1(x)
#define trace2(x,y)
#define trace3(x,y,z)
#define trace4(a,b,c,d)
#define trace5(a,b,c,d,e)
#define trace6(a,b,c,d,e,f)
#endif

/*=====================================================================================================================================*/


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif