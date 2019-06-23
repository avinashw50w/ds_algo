   //*+++++++++++++++++++++++++++++++++++++++++*//
  //		   ~~~~~ @VIN@SH ~~~~~             //
 //          ~~~~ IIEST SHIBPUR ~~~~          //
//*+++++++++++++++++++++++++++++++++++++++++*//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define oo  0x3f3f3f3f
#define ooo 0x3f3f3f3f3f3f3f3fLL
#define mod 1000000007
#define mp  make_pair
#define pb  push_back
#define ll  long long int
#define ull long long unsigned int
#define SZ(o) ((int)(o).size())
#define RC(o) scanf("%c",(o))
#define RS(o) scanf("%s",(o))
#define RI(o) scanf("%d",&(o))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
#define DRI(o) int o; scanf("%d",&(o))
#define DRII(a,b) int a,b; scanf("%d%d",&(a),&(b))
#define DRIII(a,b,c) int a,b,c; scanf("%d%d%d",&(a),&(b),&(c))
#define FILL(o,n) memset(o,n,sizeof(o))
#define ALL(o) (o).begin(),(o).end()
#define UNIQUE(o) (sort(ALL(o)), ((o).erase(unique(ALL(o)), (o).end())))
#define REP(i,a,b) for(int i=a;i<b;++i)
#define PER(i,b,a) for(int i=b;i>=a;i--)
#define FORE(i,o) for(auto &i:(o))
#define CASET  int __T,case_n=1; scanf("%d",&__T); while(__T--)
#define runtime printf("\nRunning time : ",(double)clock()/CLOCKS_PER_SEC)
#ifdef __WIN32__
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
#define debug(args...) {dbg,args; cerr<<endl;}             
struct debugger{
    template<typename T> debugger& operator , (const T& v) { cerr<<v<<" "; return *this; }
} dbg;

const int dxy[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
ll lcm(ll a,ll b){ return a*b/__gcd(a,b);}
template<typename T> struct Comp{ bool operator()(const T &a,const T &b){ return a > b; } };  // LAMBDA: [](T a,T b){return a>b;}
inline ll reduce(ll a,ll b,ll m){ if(b==0)return 1;ll o=reduce(a,b/2,m);o=(o*o)%m;if(b&1)o=(o*a)%m;return o; }
inline ll inp(){register ll n=0;int s=1;char c=getchar_unlocked();if(c=='-'){s=-1;c=getchar_unlocked();}while(c>='0'&&c<='9'){n=(n<<3)+(n<<1)+(c-48);c=getchar_unlocked();}return n*s;}
inline void out(ll n){if(abs(n)!=n)putchar_unlocked('-');char buf[20];int i=0;do{buf[i++]=n%10+48;n/=10;}while(n);i--;while(i>=0)putchar_unlocked(buf[i--]);putchar_unlocked('\n');}

const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<int,int> mii;

int main(){
	
	return 0;
}
