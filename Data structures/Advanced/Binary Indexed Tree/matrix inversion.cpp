#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int bit[1010][1010];
int N;

vector< pair<int, pii> >  v;

void update(int l, int r, int val) {
	for(int i=l; i<=1010; i+=i&-i) {
		for(int j=r; j<=1010; j+=j&-j) 
			bit[i][j] += val;
	}
}

ll query(int l, int r) {
	ll ret = 0;
	for(int i=l; i>0; i-=i&-i){
		for(int j=r; j>0; j-=j&-j)
			ret += bit[i][j];
	}

	return ret;
}

int main() {

	cin>>N;

	for(int i=1;i<=N;++i) 
		for(int j=1;j<=N;++j){
			int x; cin>>x;
			v.push_back({-x, {i, j}});
		}

	sort(v.begin(), v.end());

	int curr, i = 0;

	ll ans = 0;

	while(i < v.size()){
		curr = i;

		vector<pair<int,int>> vec;

		while(curr < v.size() && (v[curr].first == v[i].first)){
			vec.push_back({v[curr].second.first, v[curr].second.second});

			ans += query(v[curr].second.first, v[curr].second.second);

			curr++;
		}

		for(auto k: vec)
			update(k.first, k.second, 1);
			
		i = curr;
	}

	cout << ans << endl;

}