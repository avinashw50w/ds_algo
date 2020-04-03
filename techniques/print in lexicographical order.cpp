#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)

bool comp(string a,string b){ return a > b; }    // use comp for reverse lexicographical order ///

int main(){
	vector<string> v;
	string s;
	rep(i,0,5) {
		cin>>s;
		v.push_back(s);
	}
	sort(v.begin(),v.end());

	rep(i,0,v.size()) cout << v[i] <<" ";
}

//////

