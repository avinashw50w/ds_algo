#include <iostream>
using namespace std;
#define SIZE 9999999
class trie{
	int n;
	int ch[SIZE][2];
public:
	trie() : n = 1, ch[0][0] = ch[0][1] = -1 {}

	void insert(int x){
		int node = 0;
		for(int i=31; i>=0; i--){
			int next = x & (1<<i);
			if(ch[node][next] == -1){
				ch[node][next] = n;
				ch[n][0] = ch[n][1] = -1;
				n++;
			}
			node = ch[node][next];
		}
	}

	int query(int x){
		int node = 0 , ans = 0;
		for(int i=31; i>=0; i--){
			int next = x & (1<<i);
			bool flag = 1;
			if(ch[node][next^1] == -1){
				next ^= 1;
				flag = 0;
			}
			if(flag) ans += (1<<i);
			
			node = ch[node][next^1];
		}
		return ans;
	}
};

int maxSubarrayXOR(int a[], int n){
	trie t;
	t.insert(0);
	int res = -oo , prefix = 0;
	for(int i=0; i<n; ++i){
		prefix ^= a[i];
		t.insert(prefix);
		res = max(res , t.query(prefix));
	}
	return res;
}

int main(){

}

