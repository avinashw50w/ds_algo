/*Mike is the president of country What-The-Fatherland. There are n bears living in this country besides Mike. 
All of them are standing in a line and they are numbered from 1 to n from left to right. i-th bear is exactly ai feet high.


A group of bears is a non-empty contiguous segment of the line. The size of a group is the number of bears in that group. 
The strength of a group is the minimum height of the bear in that group.

Mike is a curious to know for each x such that 1 ≤ x ≤ n the maximum strength among all groups of size x.

Input
The first line of input contains integer n (1 ≤ n ≤ 2 × 105), the number of bears.

The second line contains n integers separated by space, a1, a2, ..., an (1 ≤ ai ≤ 109), heights of bears.

Output
Print n integers in one line. For each x from 1 to n, print the maximum strength among all groups of size x.

input
10
1 2 3 4 5 4 3 2 1 6
output
6 4 4 3 3 2 2 1 1 1 */

/*For each i, find the largest j that aj < ai and show it by li (if there is no such j, then li = 0).

Also, find the smallest j that aj < ai and show it by ri (if there is no such j, then ri = n + 1).

This can be done in O(n) with a stack. Pseudo code of the first part (second part is also like that) :

stack s // initially empty
for i = 1 to n
     while s is not empty and a[s.top()] >= a[i]
          do s.pop()
     if s is empty
          then l[i] = 0
     otherwise
          l[i] = s.top()
     s.push(i)
 

Consider that you are asked to print n integers, ans1, ans2, ..., ansn. Obviously, ans1 ≥ ans2 ≥ ... ≥ ansn.

For each i, we know that ai can be minimum element in groups of size 1, 2, ..., ri - li - 1.

Se we need a data structure for us to do this:

We have array ans1, ans2, ..., ansn and all its elements are initially equal to 0. 
Also, n queries. Each query gives x, val and want us to perform ans1 = max(ans1, val), 
ans2 = max(ans2, val), ..., ansx = max(ansx, val). We want the final array.

This can be done in O(n) with a maximum partial sum (keeping maximum instead of sum), 
read here for more information about partial sum.

Time complexity: */

const int maxn = 1e6 + 100;
int a[maxn], n, l[maxn], r[maxn], ans[maxn];
stack<int> s;
int main(){
	scanf("%d", &n);
	For(i,0,n)
		scanf("%d", a + i);
	fill(l, l + maxn, -1);
	fill(r, r + maxn, n);
	for(int i = 0; i < n; ++i){
		while(!s.empty() && a[s.top()] >= a[i])
			s.pop();
		if(!s.empty())
			l[i] = s.top();
		s.push(i);
	}
	while(!s.empty())
		s.pop();
	for(int i = n-1; i >= 0; --i) {
		while(!s.empty() && a[s.top()] >= a[i])
			s.pop();
		if(!s.empty())
			r[i] = s.top();
		s.push(i);
	}
	for(int i = 0; i < n; ++i) {
		int len = r[i] - l[i] - 1;
		ans[len] = max(ans[len], a[i]);
	}
	for(int i = n; i >= 0; --i)
		ans[i] = max(ans[i], ans[i+1]);
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	cout << endl;
	return 0;
}

//////////////////////////////////////////////////////////////////
// other shorter implementations

#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int N; scanf("%d", &N);
	pair<int, int> a[200100];
	for(int n=0; n<N; n++){
		scanf("%d", &a[n].first);
		a[n].second = n;
	}
	sort(a, a+N);
	int c=0;
	int m[200100][2];
	for(int x=0; x<=N+1; x++){
		m[x][0]=m[x][1]=0;
	}
	for(int x=N-1; x>=0&&c<N; x--){
		int v = a[x].second;
		int b = v-m[v-1][0];
		int e = v+m[v+1][1];
		int l = e-b+1;
		m[b][1] = l;
		m[e][0] = l;
		for(;c<l; c++){
			if(c)
				printf(" ");
			printf("%d", a[x].first);
		}
	}
	printf("\n");
	return 0;
}

/////////////////////////////////////////////////////

const int MAXN=1000111;
typedef pair<int,int> PII;
set<int> S;

priority_queue<PII> PQ;
int odp[MAXN];
main(){
	int n;scanf("%d",&n);
	for(int i=0;i<=n+1;i++) S.insert(i);
	for(int i=1;i<=n;i++){
		int a;scanf("%d",&a);
		PQ.emplace(a,i);
	}
	int ob=1;
	while(!PQ.empty()){
		int val,pos;tie(val,pos)=PQ.top();PQ.pop();
		S.erase(pos);
		auto it2=S.lower_bound(pos),it1=it2;it1--;
		int rozn=(*it2)-(*it1)-1;
		while(rozn>=ob) odp[ob]=val,ob++;
	}
	for(int i=1;i<=n;i++) printf("%d ",odp[i]);
	puts("");
}

////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 1000005;
pair<int, int> p[MAX];
int par[MAX], size[MAX], ans[MAX];
bool mark[MAX];
int find(int v)
{
	return (par[v] == v ? v : par[v] = find(par[v]));
}
void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	par[u] = v;
	size[v] += size[u];
}
int main()
{
	ios::sync_with_stdio(false);
	for (int i = 0; i < MAX; i++)
	{
		par[i] = i;
		size[i] = 1;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first;
		p[i].second = i;
	}
	sort(p, p + n, greater<pair<int, int> >());
	int cur = 1;
	for (int i = 0; i < n; i++)
	{
		int pos = p[i].second;
		int val = p[i].first;
		mark[pos] = true;
		if (pos && mark[pos - 1])
			merge(pos, pos - 1);
		if (pos < n - 1 && mark[pos + 1])
			merge(pos, pos + 1);
		int sz = size[find(pos)];
		while (cur <= sz)
			ans[cur++] = val;
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}