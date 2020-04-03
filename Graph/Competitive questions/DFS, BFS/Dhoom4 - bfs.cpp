/*Samarpit is the main hero of the Dhoom 4.He is trying to steal from the Code Bank Of Hackers.Samarpit has a key with an 
integer value printed on it. He also has N other keys with each key having its own specific value.Samarpit is trying to break 
the Lock for which he is supposed to get to the lock's key value. He can perform one type of operation.Take his own key and 
one of the other N keys and merge them.During merging Samarpit's Key value changes to product of both the keys modulus 100000.

For example if his key value was X and he took a key with value Y the his new key will be (X*Y)%100000.The other key that was 
used during the merging process remains along with other N-1 keys.

This entire process of merging takes 1 second.Now since he is in a hurry he asks to you to find the minimum time in which he 
could reach to the lock's key value.

Input:
The first line contains 2 integers they are Samarpit's Key value and the Lock's key value.
The second line contains N indicating the number of other keys Samarpit has. 
Third line contains N space separated integers indicating the value of N other keys.

Output: 
The minimum time required to get to the Lock's Key.If he is unable to reach that print -1.

Constraints:
1 ≤ N ≤ 1000 
1 ≤ Value of all the keys ≤ 100000

SAMPLE INPUT 
3 30
3
2 5 7
SAMPLE OUTPUT 
2
Explanation
In the first second he can take make his own key to value 6 by multiplying it by 2.Then in the next second he can multiply 
his new key with 5 to get to 30.*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)

const int mod = 100000;
int ans[mod+5], a[mod+5];

int main() {
    int key, lKey;
    int N; 
    
    cin >> key >> lKey;
    cin >> N;
    memset(ans, -1, sizeof(ans));
    
    rep(i,0,N) cin >> a[i];
    
    ans[key] = 0;
    queue<int> Q;
    Q.push(key);
    
    while(!Q.empty()) {
        int k = Q.front();
        Q.pop();
        int nKey;
        rep(i,0,N) {
            nKey = (k*a[i]) % mod;    
            if(ans[nKey] == -1) {
                ans[nKey] = ans[k] + 1;
                if(nKey == lKey) break;
                Q.push(nKey);
            }
        }
    }
    cout << ans[lKey] << endl;
}

//////////////////////////////////////////////
typedef unsigned long long int ull;
typedef long long int ll;
int a[1005];

int main(){
	int owkey,reqkey,n,i;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>owkey>>reqkey;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	int ans[100005];
	memset(ans,-1,sizeof(ans));
	queue<int>q;
	q.push(owkey);
	ans[owkey]=0;
	while(!q.empty()){
		ll val=q.front();
		q.pop();
		if(val==reqkey)
		break;
		for(i=0;i<n;i++){
			ll to=a[i];
			to=to*val;
			to%=100000;
			if(ans[to]==-1){
				ans[to]=ans[val]+1;
				q.push(to);
			}
		}
	}
	printf("%d\n",ans[reqkey]);
	fclose(stdout);
	return 0;
}