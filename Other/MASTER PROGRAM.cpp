   //*+++++++++++++++++++++++++++++++++++++++++*//
  //		   ~~~~~ @VIN@SH ~~~~~             //
 //          ~~~~ IIEST SHIBPUR ~~~~          //
//*+++++++++++++++++++++++++++++++++++++++++*//
#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:36777216")
#define endl '\n'
#define oo  0x3f3f3f3f
#define mod 1000000007
#define mp  make_pair
#define mt  make_tuple
#define pb  emplace_back
#define ll  long long int
#define ull long long unsigned int
#define SZ(X) ((int)(X).size())
#define RS(X) scanf("%s",(X))
#define RI(X) cin>>(X)
#define RII(X,Y) cin>>(X)>>(Y)
#define RIII(X,Y,Z) cin>>(X)>>(Y)>>(Z)
#define DRI(X) int X; cin>>(X)
#define DRII(X,Y) int X, Y; cin>>(X)>>(Y)
#define DRIII(X,Y,Z) int X, Y, Z; cin>>(X)>>(Y)>>(Z)
#define FILL(X,n) memset(X,n,sizeof X)
#define ALL(X) (X).begin(),(X).end()
#define UNIQUE(x) (sort(ALL(x)), ((x).erase(unique(ALL(x)), (x).end())))
#define REP(i,a,b) for(int i=a;i<b;++i)
#define PER(i,b,a) for(int i=b;i>=a;i--)
#define FORE(i,X) for(auto &i:(X))
#define CASET  int __T,case_n=1; cin>>__T; while(__T--)
#define miii unordered_map< int, unordered_map<int,int> > 
#define runtime cout<<"\nRunning time:"<<setprecision(3)<<(double)clock()/CLOCKS_PER_SEC<<"\n"
#define BOOST  ios_base::sync_with_stdio(0)  // cin.tie(nullptr)
#define ff first
#define ss second 
#if defined(_WIN64)
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif
#define DEBUG freopen("in.txt","r",stdin)
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
const ll inf = (1LL<<60);
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<int,int> mii;
const int dxy[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
template<typename T> struct Comp{ bool operator()(const T &a,const T &b){ return a > b; } };  // LAMBDA: [](T a,T b){return a>b;}
ll lcm(ll a,ll b){ return a*b/__gcd(a,b);}
inline ll kill(ll a,ll b,ll m){ll r=1;while(b){if(b&1) r=(r*a)%m; b>>=1;a=(a*a)%m;}return r;}
inline ll Inv(ll a,ll m){return kill(a,m,m-2);} // Phi(m)-1
inline ll Phi(ll n){ ll r=n;for(ll i=2;i*i<=n;i++){if(n%i==0)r-=r/i;while(n%i==0)n/=i;} if(n!=1)r-=r/n; return r;}
void extEuclid(int a,int b,int x,int y,int d){if(b==0){x=1;y=0;d=a;return;} extEuclid(b,a%b,x,y,d); int x1=y,y1=x-(a/b)*y; x=x1; y=y1;}
inline ll input(){register ll n=0;int s=1;char c=gc();if(c=='-')s=-1,c=gc();while(c>='0'&&c<='9')n=(n<<3)+(n<<1)+(c-48),c = gc();return n*s;}
inline void output(ll n){if(abs(n)!=n)pc('-');char buf[20];int i=0;do{buf[i++]=n%10+48;n/=10;}while(n);i--;while(i>=0)pc(buf[i--]);pc('\n');}

int main(){
	
	return 0;
}
