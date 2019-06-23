#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	string s;
	while(t--) {
	    getline(cin, s);
	    int i, j;
	    i = s.find("//");
	   
	    if(i != string::npos) {
	        j = s.find('\n');
	        if(j != string::npos) {
	            s.erase(i, j+1-i+1);
	            cout << s << endl;
	            continue;
	        }
	    }
	        i = s.find("/*");
	        if(i != string::npos) {
	            j = s.find("*/");
	            if(j != string::npos) {
	                s.erase(i, j+1-i+1);
	                cout << s << endl;
	                continue;
	            }
	        }
	    cout << s << endl;
	}
	return 0;
}