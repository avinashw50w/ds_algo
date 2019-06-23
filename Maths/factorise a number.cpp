#include <iostream>
#include <vector>
using namespace std;

vector<int> factorize(int n) {
	long long i; vector<int> res;
	
	for(i = 2; i*i <= n; ++i) {
		if(n%i == 0) res.push_back(i);
		while(n%i == 0) n /= i;
	}
	
	if(n > 1) res.push_back(n);
}

/////////  or /////////////////
vector<int> factorise(int n){
	long long i; vector<int> res;
	
	while(n%2 == 0) { res.push_back(2); n /= 2; }
	
	for(i = 3; i*i <= n; i += 2){
		while(n%i == 0){                // if you just need the unique factors then : if(n%i==0) res.push_back(i); while(n%i==0) n/=i; 
			res.push_back(i);
			n /= i;
		}
	}
	if(n > 2) res.push_back(n);
	return res;
}

int main(){
	int n; cin>>n;
	vector<int> factors=factorise(n);
	for(int i=0;i<factors.size();i++) cout<<factors[i]<<" ";
	return 0;
}
