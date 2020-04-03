/*Aishwarya is a mathematics student at the Department of Mathematics and Computing, California. 
Her teacher recently gave her an intriguing assignment with only a single question. 
The question was to find out the minimum number of single digit prime numbers which when summed 
equals a given number X.

Input:
The first line contains T denoting the number of test cases. Each of the next T lines contains a single integer X.

Output:
Print the minimum number required. If it is not possible to obtain X using single digit prime numbers, output -1.

Constraints:
1<=T<=100
1<=X<=10^6

SAMPLE INPUT 
4
7
10
14
11
SAMPLE OUTPUT 
1
2
2
3
Explanation
10 can be represented as 7 + 3.

14 can be represented as 7+7*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6+2;
const ll oo = 1e9+7;
ll dp[maxn];

int main() {
	vector<int> p = {2, 3, 5, 7};
	int t, x;
    cin >> t;
	while (t--) {
		cin >> x;
    
        fill(dp, dp + maxn, oo);
        dp[0] = 0;
		for (int i = 0; i < p.size(); ++i)
			for (int j = p[i]; j <= x; ++j)
			    if (dp[j-p[i]] != oo)
				    dp[j] = min(dp[j], 1 + dp[j-p[i]]);

		cout << (dp[x] != oo ? dp[x] : -1) << endl;
	}
}