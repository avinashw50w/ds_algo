#include <bits/stdc++.h>
using namespace std;

vector<string> parse(string str) {
	
	vector<string> v;

	stringstream ss(str);

	while(ss) {
		string tmp; 
		ss >> tmp;
		v.push_back(tmp);
	}

	return v;
}

int main() {

	string str;
	getline(cin,str);
	
	vector<string> v = parse(str);
	
	cout << v.size()<<endl; 

	for(int i=0;i<v.size();++i) cout << v[i] << endl;
}
