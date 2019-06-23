   //*+++++++++++++++++++++++++++++++++++++++++*//
  //		   ~~~~~ @VIN@SH ~~~~~             //
 //           ~~~~IIEST SHIBPUR~~~~           //
//*+++++++++++++++++++++++++++++++++++++++++*//
#include <cstdio>
#include <cstlib>
#include <cmath>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;
#define oo  0x3f3f3f3f
#define mod 1000000007
#define ff first
#define ss second
#define mp  make_pair
#define mt  make_tuple
#define pb  emplace_back
#define ll  long long int
#define ull long long unsigned int
#define RS(X)  scanf("%s",(X))
#define RI(X) scanf("%d",&(X))
#define RII(X,Y) scanf("%d%d",&(X),&(Y))
#define RIII(X,Y,Z) scanf("%d%d%d",&(X),&(Y),&(Z))
#define DRI(X) int X; scanf("%d",&(X))
#define DRII(X,Y) int X, Y; scanf("%d%d",&(X),&(Y))
#define DRIII(X,Y,Z) int X, Y, Z; scanf("%d%d%d",&(X),&(Y),&(Z))
#define FILL(X,n) memset((X),n,sizeof(X))
#define ALL(X) (X).begin(),(X).end()
#define UNIQUE(x) (sort(ALL(x)), ((x).erase(unique(ALL(x)), (x).end())))
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define PER(i,b,a) for(int i=(int)(b);i>=(int)(a);i--)
#define CASET  int __T,case_n=1; cin>>__T; while(__T--)
#define runtime printf("\nRunning time:%.2f\n",(double)clock()/CLOCKS_PER_SEC);
#define gc getchar_unlocked 
const ll inf = (1LL<<60);
const double eps = 1e-7;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<int,int> mii;
const int dxy[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
ll lcm(ll a,ll b){ return a*b/__gcd(a,b);}
template<typename T> struct Comp{ bool operator()(const T &a,const T &b){ return a > b; } };  // LAMBDA: [](T a,T b){return a>b;}
inline ll reduce(ll a,ll b,ll m){ if(b==0)return 1;ll x=reduce(a,b/2,m);x=(x*x)%m;if(b&1)x=(x*a)%m;return x; }
inline ll input(){register ll n=0;int s=1;char c=gc();if(c=='-'){s=-1;c=gc();}while(c>='0'&&c<='9'){n=(n<<3)+(n<<1)+(c-48);c=gc();}return n*s;}

int main(){
	
	return 0;
}
