/*Harry Potter has n mixtures in front of him, arranged in a row.Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.

When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.

Input

There will be a number of test cases in the input.

The first line of each test case will contain n, the number of mixtures, 1 <= n <= 100.

The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

Output

For each test case, output the minimum amount of smoke.

Example

Input:
2
18 19
3
40 60 20

Output:
342
2400  */

/* can be solved using dp. Let the mix is (a,b,c,d). Now, total smoke produced after mixing them = smoke produced after mixing (a,b) + 
	smoke produced after mixing (c,d) + smoke produced after mixing (ab, cd). Note that smoke produced after mixing (ab, cd) = (a+b) * (c+d).
	So, total smoke produced = smoke(a,b) + smoke(c,d) + ((a+b) * (c+d)) */

#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)

#define oo 0x3f3f3f3f

int smoke[101][101], color[101][101], a[101];
int n;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(cin>>n){
		rep(i,0,n) cin >> a[i];

		rep(i,0,n) rep(j,0,n) smoke[i][j] = oo;
		
		int sum = 0;
		rep(i,0,n){
			sum = color[i][i] = a[i];
			smoke[i][i] = 0;
			rep(j,i+1,n){
				sum += a[j];
				color[i][j] = sum % 100;
			}
		}

		rep(len, 2, n+1) {
			rep(i, 0, n-len+1) {
				int j = i+len-1;
				rep(k, i, j) {
					int tmp = smoke[i][k] + smoke[k+1][j] + color[i][k] * color[k+1][j];
					if(tmp < smoke[i][j]) 
						smoke[i][j] = tmp;
				}
			}
		}
		cout << smoke[0][n-1] << endl;
	}
}


//////////////////////////////////////////////////////////////////////////////////
// another way //

struct node{
	int val, smoke;
};
node a[101][101];
int n;

int main() {
	#if 0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	BOOST;
	while(cin>>n) {
		rep(i,0,101) rep(j,0,101) a[i][j].smoke = oo;
		rep(i,0,n) {
			cin>>a[i][i].val;
			a[i][i].smoke = 0;
		}

		rep(i, 1, n){
			rep(j, 0, n-i){
				int x = j;
				int y = i+j;
				rep(k, x, y) {
					int tmp = a[x][k].val * a[k+1][y].val + (a[x][k].smoke + a[k+1][y].smoke);
					if(tmp < a[x][y].smoke) {
						a[x][y].val = (a[x][k].val + a[k+1][y].val) % 100;
						a[x][y].smoke = tmp;
					}
				}
			}
		}

		cout << a[0][n-1].smoke << "\n";
	}

	return 0;
}